#include <ncine/config.h>

#if !NCINE_WITH_IMGUI
#error nCine must have ImGui integration enabled for this application to work
#endif

#if defined(_WIN32) && !NCINE_WITH_QT5
// Windows platforms
#include <ncine/common_windefines.h>
#include <windef.h>
#include <winbase.h> // LocalFree, FORMAT_*****
#include <shellapi.h> // CommandLineToArgvW
#include <WinUser.h> // MessageBoxA
#undef DELETE // Windows bad macros
#include <stdlib.h>
#include <string>
#elif !NCINE_WITH_QT5
// Non Windows platforms without QT
#include <stdio.h>
#else
// QT platforms (unified)
#include <QApplication>
#include <QMessageBox>
#include <ncine/Qt5Widget.h>
#endif

#include "GamePlayer.h"

#include <ncine/PCApplication.h>

ncine::IAppEventHandler* createAppEventHandler();

#if defined(_WIN32) && !NCINE_WITH_QT5
int main(int argc, char** argv);

//Returns the last Win32 error, in string format. Returns an empty string if there is no error.
static std::string GetLastErrorAsString()
{
	//Get the error message, if any.
	DWORD errorMessageID = GetLastError();
	if (errorMessageID == 0)
		return std::string(); //No error message has been recorded

	LPSTR messageBuffer = nullptr;
	size_t size = FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr, errorMessageID, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPSTR>(&messageBuffer), 0, NULL);

	std::string message(messageBuffer, size);

	//Free the buffer.
	LocalFree(messageBuffer);

	return message;
}

static int NoMemory()
{
	MessageBoxA(nullptr, "Out of memory while starting the application!", "OpenMysteryToolkit Player", MB_OK | MB_ICONERROR);
	return -1;
}

static int ConversionFailed(int i)
{
	std::string msg = std::string("Unable to convert argument ");
	msg += std::to_string(i);
	msg += ".\nWindows error: ";
	msg += GetLastErrorAsString();

	MessageBoxA(nullptr, msg.c_str(), "OpenMysteryToolkit Player", MB_OK | MB_ICONERROR);
	return -2;
}

int WINAPI wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
	// Windows does not provide argc, argv and it doesn't provide an ANSI CommandLine parsing
	// In this function we get all the arguments and perform a conversion to ANSI strings
	// in order to call "main" like the other platforms.
	// Please note that lpCmdLine does not include the executable name therefore it breaks
	// argc compatibility.

	int argc;
	LPWSTR* argvW = CommandLineToArgvW(GetCommandLineW(), &argc);

	if (!argvW)
	{
		return NoMemory();
	}

	size_t argvAtotalSize = wcslen(GetCommandLineW()) + 1;
	char** argvA = static_cast<char**>(malloc(argvAtotalSize));

	if (!argvA)
	{
		LocalFree(argvW);
		return NoMemory();
	}

	size_t PtNumOfCharConverted, argvWlen;
	for (int i = 0; i < argc; i++)
	{
		argvWlen = wcslen(argvW[i]);

		argvA[i] = static_cast<char*>(malloc(argvWlen + 1));
		wcstombs_s(&PtNumOfCharConverted, argvA[i], argvWlen + 1, argvW[i], argvWlen);
		argvA[argvWlen] = '\0';

		argvWlen++;
		if (PtNumOfCharConverted != argvWlen)
		{
			free(argvA);
			LocalFree(argvW);
			return ConversionFailed(i);
		}
	}

	LocalFree(argvW);

	int retCode = main(argc, argvA);

	free(argvA);
	return retCode;
}

static void printArgumentInfo()
{
	MessageBoxA(nullptr, "Please specify a game name as the first program argument!", "OpenMysteryToolkit Player", MB_OK | MB_ICONINFORMATION);
}
#elif !NCINE_WITH_QT5
static void printArgumentInfo()
{
	// @note: X11 or Mac?
	printf("Please specify a game name as the first program argument!");
}
#endif

int main(int argc, char** argv)
{
#if NCINE_WITH_QT5
	// Qt includes a MessageBox by default and it works in a different way than anything else.
	// @note: Qt5 support not tested

	if (argc < 2)
	{
		QMessageBox box;
		box.setWindowTitle("OpenMysteryToolkit Player");
		box.setText("Please specify a game name as the first program argument!");
		box.setIcon(QMessageBox::Information);
		box.exec();
		return 0;
	}

	GamePlayer::GameName = nctl::String(argv[1]);
	
	QApplication app(argc, argv);
	ncine::Qt5Widget* ncWidget = new ncine::Qt5Widget(createAppEventHandler);
	ncWidget->show();
	return app.exec();
#else
	if (argc < 2)
	{
		printArgumentInfo();
		return 0;
	}
	
	GamePlayer::GameName = nctl::String(argv[1]);

	return ncine::PCApplication::start(createAppEventHandler);
#endif
}

set(PACKAGE_NAME "OpenMysteryToolkit")
set(PACKAGE_EXE_NAME "omtplayer")
set(PACKAGE_VENDOR "Arves100")
set(PACKAGE_COPYRIGHT "Copyright ©2020 ${PACKAGE_VENDOR}")
set(PACKAGE_DESCRIPTION "Player for Open Mystery Toolkit supported games")
set(PACKAGE_HOMEPAGE "https://www.github.com/arves100/openmysterytoolkit")
set(PACKAGE_REVERSE_DNS "it.arves100.openmysterytoolkit.player")

set(PACKAGE_INCLUDE_DIRS include)

set(PACKAGE_SOURCES
	include/GamePlayer.h
	src/GamePlayer.cpp
	src/Main.cpp
)

set(PACKAGE_NAME "OpenMysteryToolkit")
set(PACKAGE_EXE_NAME "OTKPlayer")
set(PACKAGE_VENDOR "Arves100")
set(PACKAGE_COPYRIGHT "Copyright ©2019 ${PACKAGE_VENDOR}")
set(PACKAGE_DESCRIPTION "A toolkit for creating games in the style of Mystery Dungeon")
set(PACKAGE_HOMEPAGE "https://www.github.com/arves100/OpenMysteryToolkit")
set(PACKAGE_REVERSE_DNS "it.arves100.openmysterytoolkit")

set(PACKAGE_INCLUDE_DIRS include)

set(PACKAGE_SOURCES
	include/Monster.h
	include/Player.h
	src/Monster.cpp
	src/Player.cpp
	src/StdAfx.h
)

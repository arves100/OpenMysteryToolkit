set(NCPROJECT_NAME "OpenMysteryToolkit")
set(NCPROJECT_EXE_NAME "omt")
set(NCPROJECT_VENDOR "Arves100")
set(NCPROJECT_COPYRIGHT "Copyright ©2022 ${NCPROJECT_VENDOR}")
set(NCPROJECT_DESCRIPTION "An open source mystery dungeon viewer")
set(NCPROJECT_HOMEPAGE "https://www.scaminc.org/schifezze/pmu")
set(NCPROJECT_REVERSE_DNS "org.scaminc.pmu")
set(NCPROJECT_VERSION "0.1dev")

set(NCPROJECT_INCLUDE_DIRS src)

set(DB_FILES
	abilitydb.h
	abilitydb.cpp
    gameinfo.cpp
    gameinfo.h
	spelldb.h
	spelldb.cpp
	dungeondb.cpp
	dungeondb.h
	monsterdb.h
	monsterdb.cpp
	itemdb.h
	itemdb.cpp
	mapdb.cpp
	mapdb.h
	loader.h
)

set(PYTHON_FILES
    link.h
    inc.h
    omt.cpp
    modules.h
    omt.h
)

set(PYTHON_MODULES_FILES
    constants.cpp
    entity.cpp
    flags.cpp
    switches.cpp
    system.cpp
	log.cpp
)

set(PYTHON_CLASS_FILES
	player.cpp
	entity.cpp
	map.cpp
	dungeon.cpp
	map.h
	player.h
	dungeon.h
	entity.h
	monster.h
	monster.cpp
)

set(ABSTRACT_FILE 
    ISystem.h
	IDb.h
)

set (DEF_FILES
    defaults.h
    direction.h
    gender.h
    item.h
    statuslink.h
    cycleinfo.h
    scriptactivation.h
    stats.h
	deftable.h
	ability.h
	curve.h
	monsterinfo.h
)

set (COMPONENTS_FILES
	spawn.h
	container.h
    contact.h
    controllable.h
    motion.h
    paralysis.h
    poison.h
    showable.h
    sleep.h
    statsmod.h
    stackable.h
    tag.h
    talkable.h
    transform.h
    updatable.h
	monster.h
)

set (SYSTEM_FILES
    collision.h
    stats.h
    motion.h
    updatable.h
    stats.cpp
    updatable.cpp
    collision.cpp
    motion.cpp
	spawn.h
	spawn.cpp
)

set (GAME_FILES
	main.cpp
	main.h
	game.h
	game.cpp
	vari.h
	ecs.h
	python.h
	ecs.cpp
	db.h
)

set (GENERATED_FILES
	resource.rc
	version.rc
	version.cpp
	include/version.h
)

list(TRANSFORM DB_FILES PREPEND "src/db/")
list(TRANSFORM PYTHON_FILES PREPEND "src/python/")
list(TRANSFORM ABSTRACT_FILE PREPEND "src/abstract/")
list(TRANSFORM DEF_FILES PREPEND "src/def/")
list(TRANSFORM PYTHON_MODULES_FILES PREPEND "src/python/modules/")
list(TRANSFORM COMPONENTS_FILES PREPEND "src/components/")
list(TRANSFORM SYSTEM_FILES PREPEND "src/systems/")
list(TRANSFORM GAME_FILES PREPEND "src/game/")
list(TRANSFORM PYTHON_CLASS_FILES PREPEND "src/python/classes/")
list(TRANSFORM GENERATED_FILES PREPEND "${CMAKE_CURRENT_BINARY_DIR}/generated/")

source_group("db" FILES ${DB_FILES})
source_group("python" FILES ${PYTHON_FILES})
source_group("abstract" FILES ${ABSTRACT_FILE})
source_group("def" FILES ${DEF_FILES})
source_group("python/modules" FILES ${PYTHON_MODULES_FILES})
source_group("components" FILES ${COMPONENTS_FILES})
source_group("systems" FILES ${SYSTEM_FILES})
source_group("game" FILES ${GAME_FILES})
source_group("generated" FILES ${GENERATED_FILES})
source_group("python/classes" FILES ${PYTHON_CLASS_FILES})

set(NCPROJECT_SOURCES
	${CMAKE_CURRENT_BINARY_DIR}/generated/include/version.h
	${DB_FILES}
	${PYTHON_FILES}
	${ABSTRACT_FILE}
	${DEF_FILES}
	${PYTHON_MODULES_FILES}
	${SYSTEM_FILES}
	${COMPONENTS_FILES}
	${GAME_FILES}
	${GENERATED_FILES}
	${PYTHON_CLASS_FILES}
)

function (callback_before_target)
	find_package(EnTT CONFIG REQUIRED)
	#find_package(Python3 COMPONENTS Development REQUIRED)
	find_package(pybind11 CONFIG REQUIRED)
	find_package(nlohmann_json CONFIG REQUIRED)
endfunction()

function (callback_after_target)
	target_link_libraries(${NCPROJECT_EXE_NAME} PRIVATE  nlohmann_json::nlohmann_json pybind11::module pybind11::embed EnTT::EnTT)
endfunction()

# Don't edit beyond this line
if(CMAKE_SYSTEM_NAME STREQUAL "Android")
	return()
endif()

cmake_minimum_required(VERSION 3.13)
project(${NCPROJECT_NAME})


find_path(NCPROJECT_DIR cmake/project_main.cmake
	PATHS ${nCine_DIR} $ENV{NCINE_DIR}
	PATH_SUFFIXES project ../project ../../../project ../../../share/ncine/project
	NO_CMAKE_FIND_ROOT_PATH # For Emscripten
	DOC "Path to the nCine template project scripts")

if(IS_DIRECTORY ${NCPROJECT_DIR})
	include(${NCPROJECT_DIR}/cmake/project_main.cmake)
else()
	if(NOT DEFINED nCine_DIR AND "$ENV{NCINE_DIR}" STREQUAL "")
		message(FATAL_ERROR "Set the nCine_DIR CMake variable or the NCINE_DIR environment variable to a valid nCine directory.")
	elseif(DEFINED nCine_DIR)
		message(FATAL_ERROR "The nCine_DIR CMake variable \"${nCine_DIR}\" is not a valid nCine directory.")
	elseif(NOT "$ENV{NCINE_DIR}" STREQUAL "")
		message(FATAL_ERROR "The NCINE_DIR environment variable \"$ENV{NCINE_DIR}\" is not a valid nCine directory.")
	endif()
endif()

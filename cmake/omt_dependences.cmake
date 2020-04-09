find_package(RapidJSON CONFIG REQUIRED)
target_include_directories(${PACKAGE_EXE_NAME} PRIVATE ${RAPIDJSON_INCLUDE_DIRS})

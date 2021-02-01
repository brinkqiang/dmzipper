cmake_minimum_required(VERSION 3.2)

PROJECT(dmzipper)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()

SET(DMZIPPER_VERSION_MAJOR "1")
SET(DMZIPPER_VERSION_MINOR "0")
SET(DMZIPPER_VERSION_PATCH "1")
SET(DMZIPPER_VERSION "${DMZIPPER_VERSION_MAJOR}.${DMZIPPER_VERSION_MINOR}.${DMZIPPER_VERSION_PATCH}")

MESSAGE(STATUS "VERSION: ${DMZIPPER_VERSION}")

OPTION(USE_DMZIPPER "use dmzipper" ON)

add_definitions( -DUSE_ZLIB )

ModuleImport("dmzlib" "thirdparty/dmzlib")
LibImportDepends("minizip" "src/minizip" "zlibstatic")
LibImportDepends("dmzipper" "src/dmzipper" "minizip")

ExeImport("test" "dmzipper")


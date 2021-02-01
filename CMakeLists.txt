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

OPTION(USE_DMZIPPER "use dmzipper" OFF)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/include/dmzipper_config.h.in ${CMAKE_CURRENT_SOURCE_DIR}/include/dmzipper_config.h)

LibImport("dmzipper_module" "src/dmzipper_module")
ExeImport("test" "dmzipper_module")

#ADD_CUSTOM_COMMAND(
#TARGET dmzippertest
#PRE_BUILD
#COMMAND ${CMAKE_COMMAND} -E copy_if_different
#${CMAKE_CURRENT_SOURCE_DIR}/config/test.csv
#$<TARGET_FILE_DIR:dmzippertest>
#)

#INSTALL(DIRECTORY include/ DESTINATION include)
#INSTALL(TARGETS dmzipper
#        RUNTIME DESTINATION bin
#        LIBRARY DESTINATION lib
#        ARCHIVE DESTINATION lib)

#SET(DMZIPPER_LIBS "dmzipper")
#MARK_AS_ADVANCED(${DMZIPPER_LIBS})
cmake_minimum_required(VERSION 3.10)
project(TestingNetwork VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("/usr/include/")
include_directories("${CMAKE_CXX_COMPILER_ID}/")

set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}")

message("CMAKE_CXX_COMPILER_ID= ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}")
message("PROJ_DIR= ${PROJ_DIR}")


# get object files 
file(GLOB OBJ_FILES   ${PROJ_DIR}/Networking/*.o)
SET(OBJS ${OBJ_FILES})
SET_SOURCE_FILES_PROPERTIES(${OBJS} PROPERTIES EXTERNAL_OBJECT true GENERATED true)


# add libspdz.so
find_library(SPDZ_LIB SPDZ PATHS "${PROJ_DIR}/")
if(NOT SPDZ_LIB)
	  message(FATAL_ERROR "libSPDZ library not found.")
endif()

# add the executable
file(GLOB TEST_FILES "${PROJ_DIR}/tests/*.cpp")
set(i 0)
FOREACH (file ${TEST_FILES})
	message(${file})
	add_executable("test_${i}" ${file}) # ${ALL_HEADS} ${ALL_SRC} )
	target_link_libraries("test_${i}" ${OBJ_FILES}  crypto pthread ssl ${SPDZ_LIB} )
    math(EXPR i "${i} + 1")
ENDFOREACH ()

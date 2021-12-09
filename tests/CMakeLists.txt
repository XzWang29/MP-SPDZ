cmake_minimum_required(VERSION 3.10)
project(TestingNetwork VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories( "${CMAKE_CURRENT_SOURCE_DIR}/../")

message("CMAKE_CXX_COMPILER_ID= ${CMAKE_CXX_COMPILER_ID}")
message("CMAKE_CURRENT_SOURCE_DIR= ${CMAKE_CURRENT_SOURCE_DIR}")

# get object files 
file(GLOB OBJ_FILES   ${CMAKE_CURRENT_SOURCE_DIR}/../Networking/*.o)
FOREACH (file ${OBJ_FILES})
	message(${file})
ENDFOREACH ()
SET(OBJS ${OBJ_FILES})
SET_SOURCE_FILES_PROPERTIES(${OBJS} PROPERTIES EXTERNAL_OBJECT true GENERATED true)

# add libspdz.so
find_library(SPDZ_LIB SPDZ PATHS "${CMAKE_CURRENT_SOURCE_DIR}/../")
if(NOT SPDZ_LIB)
	  message(FATAL_ERROR "libSPDZ library not found.")
endif()

find_library(SSL_LIB ssl PATHS "/lib/x86_64-linux-gnu/")
if(NOT SSL_LIB)
	  message(FATAL_ERROR "ssl library not found.")
endif()

find_library(SSL_LIB ssl PATHS "/lib/x86_64-linux-gnu/")
if(NOT SSL_LIB)
	  message(FATAL_ERROR "ssl library not found.")
endif()


# add the executable
set(i 0)
file(GLOB TEST_FILES "*.cpp")
FOREACH (file ${TEST_FILES})
	message(${file})
	add_executable("test_${i}" ${file} )
	target_link_libraries("test_${i}" ${OBJ_FILES} crypto  pthread ${SSL_LIB} ${SPDZ_LIB} )
    math(EXPR i "${i} + 1")
ENDFOREACH ()

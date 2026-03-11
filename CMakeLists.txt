#*******************************************************************************
# Project config
#*******************************************************************************/

cmake_minimum_required(VERSION 3.20)

project(misc
    LANGUAGES CXX
    DESCRIPTION "Some misc snippets in C++")

# Build options
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON" CACHE BOOL "Export commands for lsp" FORCE)
set(CMAKE_CXX_STANDARD 17)

#*******************************************************************************
# CMake Submodules
#*******************************************************************************

include(CTest)

# include(GoogleTest) is not working
find_package(GTest REQUIRED)

#*******************************************************************************
# Implementation
#*******************************************************************************

add_subdirectory(src)

#*******************************************************************************
# Testing
#*******************************************************************************

add_subdirectory(tests)

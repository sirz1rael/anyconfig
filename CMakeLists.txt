cmake_minimum_required(VERSION 3.15...3.28)

project(anyconfig VERSION 0.0.1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(ANYCONFIG_BUILD_TESTS "Build anyconfig tests" ON)
option(ANYCONFIG_BUILD_EXAMPLES "Build anyconfig examples" ON)
option(ANYCONFIG_INSTALL "Generate installation target" ON)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

add_subdirectory(anyconfig)

if(ANYCONFIG_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()

if(ANYCONFIG_BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()


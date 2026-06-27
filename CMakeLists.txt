cmake_minimum_required(VERSION 3.20)

project(KSH LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_COMPILER clang++)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Wshadow
    -Wconversion
    -Wsign-conversion
    -Wnon-virtual-dtor
    -Wold-style-cast
    -Wdouble-promotion
    -Wnull-dereference
)

find_program(CLANG_TIDY_EXE NAMES clang-tidy)

if(CLANG_TIDY_EXE)
    message(STATUS "clang-tidy found: ${CLANG_TIDY_EXE}")

    set(CMAKE_CXX_CLANG_TIDY
        clang-tidy;
        -checks=clang-analyzer-*,cppcoreguidelines-*,modernize-*,readability-*,performance-*
    )
endif()

add_executable(lru
    tests/test_LRU.cpp
)

cmake_minimum_required(VERSION 3.21)

project(DocuDB VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

set(DB_BIN_DIR "${PROJECT_BINARY_DIR}/src")
set(DB_SRC_DIR "${PROJECT_SOURCE_DIR}/src")

include_directories(SYSTEM include)

add_subdirectory(lib)

add_executable(DocuDB src/main.cpp)
add_executable(UnitTests tst/test.cpp tst/catch.hpp)

target_link_libraries(DocuDB PUBLIC DocuLib)
target_link_libraries(UnitTests PUBLIC DocuLib)
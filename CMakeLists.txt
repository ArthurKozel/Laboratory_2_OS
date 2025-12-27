cmake_minimum_required(VERSION 3.15)
project(Laboratory_2_OS LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)

add_library(Core STATIC
    Core/Threads/threads.cpp
    Core/Utilities/utilities.cpp
)

target_include_directories(Core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Globals
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Threads
    ${CMAKE_CURRENT_SOURCE_DIR}/Core/Utilities
)

add_executable(Main
    Main/Main/main.cpp
    Main/Main/main.h
)

target_link_libraries(Main PRIVATE Core)



include(FetchContent)
FetchContent_Declare(
 googletest 
 URL https://github.com/google/googletest/archive/refs/heads/main.zip
 DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
FetchContent_MakeAvailable(googletest)


enable_testing()

add_executable(Test
    Test/test.cpp
)

target_link_libraries(Test PRIVATE Core GTest::gtest GTest::gtest_main)

add_test(NAME CoreTests COMMAND Test)

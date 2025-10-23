
cmake_minimum_required(VERSION 3.12)
project(laba3oop)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# настройка GTest 
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)


include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

#тестовый исполняемый файл
add_executable(laba3_main
    main.cpp
    Figure/figure.cpp
    Square/square.cpp
    Trap/trapezoid.cpp
    Array/Array.cpp
    Rect/rectangle.cpp
)
target_include_directories(laba3_main PRIVATE ${PROJECT_SOURCE_DIR})

add_executable(laba3_tests
    test_laba3.cpp
    Figure/figure.cpp
    Square/square.cpp
    Trap/trapezoid.cpp
    Array/Array.cpp
    Rect/rectangle.cpp
)

target_link_libraries(laba3_tests PRIVATE gtest_main)
target_include_directories(laba3_tests PRIVATE ${PROJECT_SOURCE_DIR})

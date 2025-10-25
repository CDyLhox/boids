cmake_minimum_required(VERSION 3.13)
project(boids)
set(CMAKE_CXX_STANDARD 14)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(SOURCE_FILES main.cpp)
add_executable(boids ${SOURCE_FILES})
target_link_libraries(boids sfml-graphics sfml-window sfml-system)


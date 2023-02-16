cmake_minimum_required(VERSION 3.10)

project(SNAKE VERSION 0.0.1)

set (CMAKE_CXX_FLAGS "-lncurses")

include_directories(headers)

file(GLOB SOURCES "src/*.cpp")

add_executable(game-snake ${SOURCES} "main.cpp")

target_link_libraries(game-snake ncurses)

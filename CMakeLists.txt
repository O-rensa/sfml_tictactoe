cmake_minimum_required(VERSION 3.10)

project(tictactoe)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}.exe main.cpp)

add_subdirectory(src)

target_link_libraries(${PROJECT_NAME}.exe srclib)
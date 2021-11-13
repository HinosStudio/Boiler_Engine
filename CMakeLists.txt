cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(apps)
add_subdirectory(src/Engine)
add_subdirectory(src/SDLimp)

find_package(SDL2 CONFIG REQUIRED)


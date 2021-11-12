cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src/Engine)
add_subdirectory(src/SDLimp)

include_directories()

add_executable(main
        main.cpp
        )

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)

target_link_libraries(main PRIVATE Boiler_Engine_Lib)
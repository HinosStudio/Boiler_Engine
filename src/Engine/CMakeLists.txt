cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

set(CMAKE_CXX_STANDARD 17)

add_library(Boiler_Engine_Lib STATIC
        Core/Engine.cpp
        Core/Entity.cpp
        Core/Extension.cpp
        Core/Scene.cpp
        Core/Time.cpp

        Util/V2.cpp
        Util/Rect.cpp
        )

target_include_directories(Boiler_Engine_Lib PRIVATE ${CMAKE_SOURCE_DIR}/include/Engine)

find_package(SDL2 CONFIG REQUIRED)

target_link_libraries(Boiler_Engine_Lib PRIVATE SDL2::SDL2 SDL2::SDL2main)
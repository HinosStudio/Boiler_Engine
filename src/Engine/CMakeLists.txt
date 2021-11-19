cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

add_library(Boiler_Engine STATIC
        Core/Engine.cpp
        Core/Entity.cpp
        Core/Extension.cpp
        Core/Scene.cpp
        Core/Time.cpp

        Util/V2.cpp
        Util/Rect.cpp
        ../ECS/EntityManager.cpp ../ECS/EntityComponent.cpp)

target_include_directories(Boiler_Engine PUBLIC ${CMAKE_SOURCE_DIR}/include/Engine)
find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(Boiler_Engine PUBLIC SDL2::SDL2)
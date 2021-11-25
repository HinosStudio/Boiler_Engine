cmake_minimum_required(VERSION 3.20)

add_library(BoilerLib STATIC
        ${CMAKE_SOURCE_DIR}/src/messaging/Observable.cpp

        ${CMAKE_SOURCE_DIR}/src/core/Engine.cpp
        ${CMAKE_SOURCE_DIR}/src/core/Debug.cpp
        ${CMAKE_SOURCE_DIR}/src/core/Time.cpp

        ${CMAKE_SOURCE_DIR}/src/rendering/Window.cpp
        ${CMAKE_SOURCE_DIR}/src/rendering/Renderer.cpp
        ${CMAKE_SOURCE_DIR}/src/rendering/Texture.cpp
        ../include/rendering/RenderingEngine.hpp ../src/rendering/RenderingEngine.cpp)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

target_link_libraries(BoilerLib
        PUBLIC SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_ttf
        )

add_subdirectory(Boiler)
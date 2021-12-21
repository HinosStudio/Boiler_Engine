cmake_minimum_required(VERSION 3.20)
project(BoilerLib)

add_library(BoilerLib STATIC
        ${CMAKE_SOURCE_DIR}/src/boiler/core/Engine.cpp
        # ${CMAKE_SOURCE_DIR}/src/boiler/core/Debug.cpp
        ${CMAKE_SOURCE_DIR}/src/boiler/core/Time.cpp

        ${CMAKE_SOURCE_DIR}/src/boiler/rendering/Window.cpp
        ${CMAKE_SOURCE_DIR}/src/boiler/rendering/Renderer.cpp
        ${CMAKE_SOURCE_DIR}/src/boiler/rendering/Texture.cpp
        ${CMAKE_SOURCE_DIR}/src/boiler/rendering/RenderingEngine.cpp

        ${CMAKE_SOURCE_DIR}/src/boiler/messaging/Observable.cpp

        ${CMAKE_SOURCE_DIR}/src/boiler/events/EventSystem.cpp

        ${CMAKE_SOURCE_DIR}/src/boiler/input/InputHandler.cpp
        )

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(sdl2-image CONFIG REQUIRED)

target_link_libraries(BoilerLib
        PUBLIC SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_ttf SDL2::SDL2_image
        )
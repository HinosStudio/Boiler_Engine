cmake_minimum_required(VERSION 3.20)
project(SDL_Rendering)

set(CMAKE_CXX_STANDARD 17)


add_library(SDL_Rendering STATIC
        Rendering/Window.cpp
        Rendering/Color.cpp
        Rendering/SDLRendererSubsystem.cpp

        Input/SDLInputSubsystem.cpp

        Extensions/Renderer.cpp
        Extensions/CircleRenderer.cpp
        Extensions/FRectRenderer.cpp
        Extensions/TextRenderer.cpp
        )

target_include_directories(SDL_Rendering PRIVATE
        ${CMAKE_SOURCE_DIR}/include/SDLimp
        ${CMAKE_SOURCE_DIR}/include/Engine/Core
        ${CMAKE_SOURCE_DIR}/include/Engine/Interfaces
        ${CMAKE_SOURCE_DIR}/include/Engine/Util
        )

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)
find_package(GLEW Required)

target_link_libraries(SDL_Rendering PRIVATE SDL2::SDL2 SDL2::SDL2main SDL2::SDL2_ttf GLEW::GLEW)
cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_library(Boiler_Engine_Lib STATIC
        src/Engine/Core/Engine.cpp
        src/Engine/Core/Entity.cpp
        src/Engine/Core/Extension.cpp
        src/Engine/Core/Scene.cpp
        src/Engine/Core/Time.cpp

        src/Engine/Util/V2.cpp
        src/Engine/Util/Rect.cpp
        )

add_executable(Boiler_Engine
        main.cpp

        src/SDLimp/Rendering/Window.cpp
        src/SDLimp/Rendering/Color.cpp
        src/SDLimp/Rendering/SDLRendererSubsystem.cpp

        src/SDLimp/Extensions/Renderer.cpp
        src/SDLimp/Extensions/CircleRenderer.cpp
        src/SDLimp/Extensions/FRectRenderer.cpp
        src/SDLimp/Extensions/TextRenderer.cpp

        src/Pathfinding/AStar.cpp
        include/SDLimp/Input/SDLInputSubsystem.hpp include/Engine/Input/IInputSubsystem.hpp src/SDLimp/Input/SDLInputSubsystem.cpp)

find_package(SDL2 CONFIG REQUIRED)
find_package(sdl2-ttf CONFIG REQUIRED)

target_link_libraries(Boiler_Engine PRIVATE
        Boiler_Engine_Lib
        SDL2::SDL2
        SDL2::SDL2main
        SDL2::SDL2_ttf
        )
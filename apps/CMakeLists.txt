cmake_minimum_required(VERSION 3.20)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE Boiler_Engine SDL_Rendering)

add_executable(rectangles RectanglesMain.cpp)
target_link_libraries(rectangles PRIVATE Boiler_Engine SDL_Rendering)
cmake_minimum_required(VERSION 3.20)
project(Boiler_Engine)

set(CMAKE_CXX_STANDARD 17)

if (WIN32 OR WIN64)
    set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
endif ()

include_directories(include)

add_subdirectory(apps)

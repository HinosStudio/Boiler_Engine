cmake_minimum_required(VERSION 3.20)

add_executable(Boiler BoilerMain.cpp)

target_link_libraries(Boiler
        PRIVATE BoilerLib)
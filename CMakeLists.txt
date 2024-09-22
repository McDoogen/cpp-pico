cmake_minimum_required(VERSION 3.22)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(cpp-pico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(projects/hello)
add_subdirectory(projects/hello2)
add_subdirectory(projects/gamepad)
add_subdirectory(projects/ros2-led)
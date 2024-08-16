cmake_minimum_required(VERSION 3.22)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(cpp-pico C CXX ASM)
pico_sdk_init()

add_subdirectory(projects/hello)
add_subdirectory(projects/hello2)
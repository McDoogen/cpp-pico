cmake_minimum_required(VERSION 3.22)
include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)
include(FetchContent)

project(cpp-pico C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_subdirectory(projects/hello)
add_subdirectory(projects/hello2)
add_subdirectory(projects/gamepad)


message("Fetching micro_ros repository...")
FetchContent_Declare(
  micro_ros
  GIT_REPOSITORY git@github.com:micro-ROS/micro_ros_raspberrypi_pico_sdk.git
  GIT_TAG        jazzy
)
FetchContent_MakeAvailable(micro_ros)
link_directories(${micro_ros_SOURCE_DIR}/libmicroros)

add_subdirectory(projects/ros2-led)
add_subdirectory(projects/monstera-led)
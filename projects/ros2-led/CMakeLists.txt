
include(FetchContent)

#TODO:DS: Can I add an 'IF' so we only log this if it is not available?
message("Fetching micro_ros repository...")
FetchContent_Declare(
  micro_ros
  GIT_REPOSITORY git@github.com:micro-ROS/micro_ros_raspberrypi_pico_sdk.git
  GIT_TAG        jazzy
)
FetchContent_MakeAvailable(micro_ros)

link_directories(${micro_ros_SOURCE_DIR}/libmicroros)

#TODO:DS: SHould I move the above, one level up?

add_executable(ros2-led
    ros2-led.cpp
    pico_uart_transport.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(ros2-led pico_stdlib microros)   #TODO:DS: What is microros here?
target_include_directories(ros2-led PUBLIC ${micro_ros_SOURCE_DIR}/libmicroros/include)

# Configure Pico
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(ros2-led)
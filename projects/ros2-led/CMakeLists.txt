add_executable(ros2-led
    ros2-led.cpp
    pico_uart_transport.c
)

# Add pico_stdlib library which aggregates commonly used features
target_link_libraries(ros2-led pico_stdlib microros)
target_include_directories(ros2-led PUBLIC ${micro_ros_SOURCE_DIR}/libmicroros/include)

# Configure Pico
add_compile_definitions(PICO_UART_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_ENABLE_CRLF_SUPPORT=0)
add_compile_definitions(PICO_STDIO_DEFAULT_CRLF=0)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(ros2-led)
add_executable(gamepad
    gamepad.c
)

target_link_libraries(gamepad pico_stdlib hardware_i2c)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(gamepad)
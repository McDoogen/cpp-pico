add_executable(hello2
    hello2.cpp
)

target_link_libraries(hello2 pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello2)
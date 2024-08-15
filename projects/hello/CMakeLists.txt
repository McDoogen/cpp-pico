add_executable(hello
    hello.cpp
)

target_link_libraries(hello pico_stdlib)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(hello)
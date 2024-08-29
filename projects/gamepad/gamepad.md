# Gamepad

    The purpose of this project is to write a driver for the Adafruit I2C gamepad. This will be a practice project to show off to Carbon Robotics

    Some distinct elements I want to show off
    - Write the gamepad as a library? or header? basically I want any project to be able to import the gamepad and utilize it
    - Write my main as a simple use case for the library
    - Determine how it is best to organize this library. Should I place it in another folder location? How are my own libraries organized?
    - Lets make sure it works with the PICO as well as the PICO2

### To Flash
```
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program build/projects/gamepad/gamepad.elf verify reset exit"
```

### To Monitor the Serial bus
```
minicom -b 115200 -o -D /dev/ttyACM0
```
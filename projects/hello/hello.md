# Hello

This is your typical hello world for the Pi Pico. It blinks the LED!

### To Flash
```
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program build/projects/hello/hello.elf verify reset exit"
```
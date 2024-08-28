# Hello2

This is your typical hello world for the Pi Pico. It blunks the LED!


### To Flash
```
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program build/projects/hello2/hello2.elf verify reset exit"

```
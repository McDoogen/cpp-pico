# Monstera-led

Node for the "Connected LED" for project Monstera.


### To Flash with the pico debugger
```
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program build/projects/monstera-led/monstera-led.elf verify reset exit"

```
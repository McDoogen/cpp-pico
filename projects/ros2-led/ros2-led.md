# ROS2-led

Using ROS2 to make an LED change state


### To Flash
```
sudo openocd -f interface/cmsis-dap.cfg -f target/rp2040.cfg -c "adapter speed 5000" -c "program build/projects/ros2-led/ros2-led.elf verify reset exit"

```
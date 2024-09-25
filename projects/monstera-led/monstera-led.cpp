#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

#include <rcl/rcl.h>
#include <rcl/error_handling.h>
#include <rclc/rclc.h>
#include <rclc/executor.h>
#include <std_msgs/msg/int32.h>
#include <rmw_microros/rmw_microros.h>

extern "C"
{
    #include "pico_uart_transport.h"
}

rcl_subscription_t subscriber;
std_msgs__msg__Int32 msg;

const uint LED_PIN = PICO_DEFAULT_LED_PIN;
const uint COMM_PIN = 16;

void subscription_callback(const void * msgin)
{
    std_msgs__msg__Int32* msgCast = (std_msgs__msg__Int32*) msgin;

    if (msgCast->data == 0) {
        gpio_put(COMM_PIN, 0);
    } else {
        gpio_put(COMM_PIN, 1);
    }
}

int main()
{
    rmw_uros_set_custom_transport(
		true,
		NULL,
		pico_serial_transport_open,
		pico_serial_transport_close,
		pico_serial_transport_write,
		pico_serial_transport_read
	);
    
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(COMM_PIN);
    gpio_set_dir(COMM_PIN, GPIO_OUT);

    rcl_node_t node;
    rcl_allocator_t allocator;
    rclc_support_t support;
    rclc_executor_t executor;

    allocator = rcl_get_default_allocator();

    // Wait for agent successful ping for 2 minutes.
    const int timeout_ms = 1000; 
    const uint8_t attempts = 120;

    rcl_ret_t ret = rmw_uros_ping_agent(timeout_ms, attempts);

    if (ret != RCL_RET_OK)
    {
        // Unreachable agent, exiting program.
        return ret;
    }

    rclc_support_init(&support, 0, NULL, &allocator);

    rclc_node_init_default(&node, "monstera_controller", "", &support);
    
    rclc_subscription_init_default(
        &subscriber,
        &node,
        ROSIDL_GET_MSG_TYPE_SUPPORT(std_msgs, msg, Int32),
        "comm_led");

    rclc_executor_init(&executor, &support.context, 1, &allocator);
    rclc_executor_add_subscription(&executor, &subscriber, &msg, subscription_callback, ON_NEW_DATA);

    gpio_put(LED_PIN, 1);
    msg.data = 0;
    while (true)
    {
        rclc_executor_spin_some(&executor, RCL_MS_TO_NS(100));
    }
    return 0;
}
/*
 * LED_Program.c
 *
 *  Created on: Aug 13, 2024
 *      Author: abdal
 */


#include "LED_Interface.h"

/**
 * @brief  Initializes the LED.
 * @param  led: Pointer to the LED structure.
 * @param  port: GPIO port where the LED is connected.
 * @param  pinNumber: GPIO pin number where the LED is connected.
 * @return None.
 */
void LED_Init(LED_t* led, GPIO_Port_t port, U8 pinNumber) {
    // Configure the GPIO pin for the LED
    GPIO_Config_t config;
    config.pin.pinNumber = pinNumber;
    config.pin.port = port;
    config.mode = GPIO_MODE_OUTPUT_PUSHPULL;  // Set as output push-pull
    config.speed = GPIO_SPEED_2MHZ;           // 2 MHz speed
    config.pullType = 0;                      // No pull-up/pull-down for output

    // Initialize the GPIO pin
    GPIO_init(&config);

    led->pin.port = port;
    led->pin.pinNumber = pinNumber;
}

/**
 * @brief  Turns the LED on.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_On(LED_t* led) {
    GPIO_WritePin(&led->pin, 1);
}

/**
 * @brief  Turns the LED off.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_Off(LED_t* led) {
    GPIO_WritePin(&led->pin, 0);
}

/**
 * @brief  Toggles the state of the LED.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_Toggle(LED_t* led) {
    U8 currentState = GPIO_ReadPin(&led->pin);
    GPIO_WritePin(&led->pin, !currentState);
}

/**
 * @brief  Sets the LED state (on or off).
 * @param  led: Pointer to the LED structure.
 * @param  state: Desired state of the LED (LED_ON or LED_OFF).
 * @return None.
 */
void LED_SetState(LED_t* led, LED_State_t state) {
    if (state == LED_ON) {
        LED_On(led);
    } else {
        LED_Off(led);
    }
}

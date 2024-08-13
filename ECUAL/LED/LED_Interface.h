/*
 * LED_Interface.h
 *
 *  Created on: Aug 13, 2024
 *      Author: abdal
 */

#ifndef LED_LED_INTERFACE_H_
#define LED_LED_INTERFACE_H_

#include "../../MCAL/GPIO/GPIO_Interface.h"

typedef enum {
    LED_OFF = 0,
    LED_ON
} LED_State_t;

typedef struct {
    GPIO_Pin_t pin;  // GPIO pin connected to the LED
} LED_t;

/**
 * @brief  Initializes the LED.
 * @param  led: Pointer to the LED structure.
 * @param  port: GPIO port where the LED is connected.
 * @param  pinNumber: GPIO pin number where the LED is connected.
 * @return None.
 */
void LED_Init(LED_t* led, GPIO_Port_t port, U8 pinNumber);

/**
 * @brief  Turns the LED on.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_On(LED_t* led);

/**
 * @brief  Turns the LED off.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_Off(LED_t* led);

/**
 * @brief  Toggles the state of the LED.
 * @param  led: Pointer to the LED structure.
 * @return None.
 */
void LED_Toggle(LED_t* led);

/**
 * @brief  Sets the LED state (on or off).
 * @param  led: Pointer to the LED structure.
 * @param  state: Desired state of the LED (LED_ON or LED_OFF).
 * @return None.
 */
void LED_SetState(LED_t* led, LED_State_t state);

#endif /* LED_LED_INTERFACE_H_ */

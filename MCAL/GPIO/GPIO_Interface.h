/*
 * GPIO_Interface.h
 *
 *  Created on: Aug 12, 2024
 *      Author: abdal
 */

#ifndef GPIO_GPIO_INTERFACE_H_
#define GPIO_GPIO_INTERFACE_H_

#include "GPIO_Config.h"
#include "GPIO_Registers.h"

/* Input Modes */
#define GPIO_MODE_INPUT_ANALOG       0b00
#define GPIO_MODE_INPUT_FLOATING     0b01
#define GPIO_MODE_INPUT_PUSHPULL     0b10

/* Output Modes */
#define GPIO_MODE_OUTPUT_PUSHPULL    0b00
#define GPIO_MODE_OUTPUT_OPEN_DRAIN  0b01
#define GPIO_MODE_ALTFN_PUSHPULL     0b10
#define GPIO_MODE_ALTFN_OPEN_DRAIN   0b11

/* Speed */
#define GPIO_SPEED_2MHZ   0b10
#define GPIO_SPEED_10MHZ  0b01
#define GPIO_SPEED_50MHZ  0b11

/* Pull type */
#define GPIO_INPUT_PULLUP    0
#define GPIO_INPUT_PULLDOWN  1

typedef enum {
	PORTA,
	PORTB,
	PORTC
} GPIO_Port_t;

typedef struct {
	U8 pinNumber;
	GPIO_Port_t port;
} GPIO_Pin_t;

typedef struct {
	GPIO_Pin_t pin;
	U8 mode;
	U8 speed;
	U8 pullType;
} GPIO_Config_t;

/**
 * @brief  Initializes a GPIO pin with the specified configuration.
 * @param  config: Pointer to the GPIO_Config_t structure containing the pin configuration.
 * @return None.
 */
void GPIO_init(GPIO_Config_t* config);

/**
 * @brief  Writes a high or low state to a GPIO pin.
 * @param  pin: Pointer to the GPIO_Pin_t structure representing the pin.
 * @param  state: State to write to the pin (0 = Low, 1 = High).
 * @return None.
 */
void GPIO_WritePin(GPIO_Pin_t* pin, U8 state);

/**
 * @brief  Reads the state of a GPIO pin.
 * @param  pin: Pointer to the GPIO_Pin_t structure representing the pin.
 * @return State of the pin (0 = Low, 1 = High).
 */
U8 GPIO_ReadPin(GPIO_Pin_t* pin);

#endif /* GPIO_GPIO_INTERFACE_H_ */

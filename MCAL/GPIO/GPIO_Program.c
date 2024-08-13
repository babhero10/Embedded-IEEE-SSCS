/*
 * GPIO_Program.c
 *
 *  Created on: Aug 12, 2024
 *      Author: abdal
 */

#include "GPIO_Interface.h"


// Helper function to get the base address of the GPIO port
/**
 * @brief: Get the base address of the GPIO port
 * @param:
 * */
static GPIO_RegDef_t* GPIO_GetPortBase(GPIO_Port_t port) {
    switch (port) {
        case PORTA: return GPIOA;
        case PORTB: return GPIOB;
        case PORTC: return GPIOC;
        default: return NULL;
    }
}

/**
 * @brief  Initializes a GPIO pin with the specified configuration.
 * @param  config: Pointer to the GPIO_Config_t structure containing the pin configuration.
 * @return None.
 */
void GPIO_init(GPIO_Config_t* config) {
    GPIO_RegDef_t* GPIOx = GPIO_GetPortBase(config->pin.port);
    U8 pinNumber = config->pin.pinNumber;

    // Determine which control register (CRL or CRH) to modify based on the pin number
    if (pinNumber < 8) {
        GPIOx->CRL &= ~(0b1111 << (pinNumber * 4));
        GPIOx->CRL |= ((config->mode | (config->speed << 2)) << (pinNumber * 4));
    } else {
        pinNumber -= 8;  // Adjust pin number for CRH
        GPIOx->CRH &= ~(0b1111 << (pinNumber * 4));
        GPIOx->CRH |= ((config->mode | (config->speed << 2)) << (pinNumber * 4));
    }

    // Configure pull-up/pull-down resistors if the pin is set as input push-pull
    if (config->mode == GPIO_MODE_INPUT_PUSHPULL) {
        if (config->pullType == GPIO_INPUT_PULLUP) {
            GPIOx->ODR |= (1 << config->pin.pinNumber);
        } else if (config->pullType == GPIO_INPUT_PULLDOWN) {
            GPIOx->ODR &= ~(1 << config->pin.pinNumber);
        }
    }
}

/**
 * @brief  Writes a high or low state to a GPIO pin.
 * @param  pin: Pointer to the GPIO_Pin_t structure representing the pin.
 * @param  state: State to write to the pin (0 = Low, 1 = High).
 * @return None.
 */
void GPIO_WritePin(GPIO_Pin_t* pin, U8 state) {
    GPIO_RegDef_t* GPIOx = GPIO_GetPortBase(pin->port);

    if (state) {
        GPIOx->BSRR = (1 << pin->pinNumber);  // Set the pin high
    } else {
        GPIOx->BRR = (1 << pin->pinNumber);  // Set the pin low
    }
}

/**
 * @brief  Reads the state of a GPIO pin.
 * @param  pin: Pointer to the GPIO_Pin_t structure representing the pin.
 * @return State of the pin (0 = Low, 1 = High).
 */
U8 GPIO_ReadPin(GPIO_Pin_t* pin) {
    GPIO_RegDef_t* GPIOx = GPIO_GetPortBase(pin->port);

    return (U8)((GPIOx->IDR >> pin->pinNumber) & 0x01);  // Read the pin state
}

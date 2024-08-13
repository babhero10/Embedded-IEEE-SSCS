/*
 * RCC_Interface.h
 *
 *  Created on: Aug 7, 2024
 *      Author: abdal
 */

#ifndef RCC_RCC_INTERFACE_H_
#define RCC_RCC_INTERFACE_H_

#include "RCC_Config.h"
#include "RCC_Registers.h"

typedef enum {
    RCC_AFIO_EN = 0,
    RCC_GPIOA_EN = 2,
    RCC_GPIOB_EN = 3,
    RCC_GPIOC_EN = 4,
    RCC_GPIOD_EN = 5,
    RCC_GPIOE_EN = 6,
    RCC_ADC1_EN = 9,
    RCC_ADC2_EN = 10,
    RCC_TIM1_EN = 11,
    RCC_SPI1_EN = 12,
    RCC_USART1_EN = 14,
    RCC_TIM2_EN = 0 + 32,  // APB1ENR starts at bit 0
    RCC_TIM3_EN = 1 + 32,
    RCC_TIM4_EN = 2 + 32,
    RCC_USART2_EN = 17 + 32,
    RCC_USART3_EN = 18 + 32,
    RCC_I2C1_EN = 21 + 32,
    RCC_I2C2_EN = 22 + 32,
    RCC_SPI2_EN = 14 + 32
} Peripheral_t;

/**
 * @brief: Initialize RCC driver.
 * @return: None.
 * */
void RCC_init(void);


/**
 * @brief: Enable peripherals clock.
 * @param peripheral: Value of Peripheral_t name to enable.
 * @return None.
 * */
void RCC_peripheralEnable(Peripheral_t peripheral);

/**
 * @brief: Disable peripherals clock.
 * @param peripheral: Value of Peripheral_t name to disable.
 * @return None.
 * */
void RCC_peripheralDisable(Peripheral_t peripheral);

#endif /* RCC_RCC_INTERFACE_H_ */

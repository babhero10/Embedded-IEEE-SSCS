/*
 * RCC_Program.c
 *
 *  Created on: Aug 7, 2024
 *      Author: abdal
 */

#include "RCC_Interface.h"

/**
 * @brief: Initialize RCC driver.
 * @return: None.
 */
void RCC_init(void)
{
#if SYSTEM_CLOCK == RCC_HSI
    // Turn on clock.
    RCC->CR |= (1 << 0);

    // Wait till ready.
    while (!(RCC->CR & (1 << 1))); // Corrected to wait until HSI is ready.

    // Choose system clock.
    RCC->CFGR &= ~(0b11 << 0);

#elif SYSTEM_CLOCK == RCC_HSE
    // Choose clock.
    RCC->CR |= (HSEBYP << 18);

    // Turn on clock.
    RCC->CR |= (1 << 16);

    // Wait till ready.
    while (!(RCC->CR & (1 << 17))); // Corrected to wait until HSE is ready.

    // Choose system clock.
    RCC->CFGR &= ~(0b11 << 0); // Clear first 2 bits.
    RCC->CFGR |= (0b01 << 0);

#elif SYSTEM_CLOCK == RCC_PLL
    // PLL select clock source.
    RCC->CFGR |= (PLL_CLOCK_SOURCE << 16);
    RCC->CFGR |= (PLL_HSE_DIVIDER << 17);
    RCC->CFGR |= (PLL_MULTIPLIER << 18);

    // Turn on clock.
    RCC->CR |= (1 << 24);

    // Wait till ready.
    while (!(RCC->CR & (1 << 25))); // Corrected to wait until PLL is ready.

    // Choose system clock.
    RCC->CFGR &= ~(0b11 << 0); // Clear first 2 bits.
    RCC->CFGR |= (0b10 << 0);
#endif

    // Check if chosen clock is used as system clock.
    while ((RCC->CFGR & (0b11 << 2)) != (RCC->CFGR & (0b11 << 0)));

    // Set ABH pre-scaler.
    RCC->CFGR &= ~(0b1111 << 4);
    RCC->CFGR |= (ABH_PRE_SCALER << 4);

    // Set APB1 pre-scaler.
    RCC->CFGR &= ~(0b111 << 8);
    RCC->CFGR |= (APB1_PRE_SCALER << 8);

    // Set APB2 pre-scaler.
    RCC->CFGR &= ~(0b111 << 11);
    RCC->CFGR |= (APB2_PRE_SCALER << 11);

    // Set ADC pre-scaler.
    RCC->CFGR &= ~(0b11 << 14);
    RCC->CFGR |= (ADC_PRE_SCALER << 14);

    // USB pre-scaler.
    RCC->CFGR &= ~(0b1 << 22);
    RCC->CFGR |= (USB_PRE_SCALER << 22);

    // Micro-controller clock output.
    RCC->CFGR &= ~(0b111 << 24);
    RCC->CFGR |= (MCO_OUTPUT << 24);
}

/**
 * @brief: Enable peripherals clock.
 * @param peripheral: Value of Peripheral_t name to enable.
 * @return None.
 */
void RCC_peripheralEnable(Peripheral_t peripheral)
{
    if (peripheral < 32) {
        RCC->APB2ENR |= (1 << peripheral);
    } else {
        RCC->APB1ENR |= (1 << (peripheral - 32));
    }
}

/**
 * @brief: Disable peripherals clock.
 * @param peripheral: Value of Peripheral_t name to disable.
 * @return None.
 */
void RCC_peripheralDisable(Peripheral_t peripheral)
{
    if (peripheral < 32) {
        RCC->APB2ENR &= ~(1 << peripheral);
    } else {
        RCC->APB1ENR &= ~(1 << (peripheral - 32));
    }
}

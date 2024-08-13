/*
 * RCC_Config.h
 *
 *  Created on: Aug 7, 2024
 *      Author: abdal
 */

#ifndef RCC_RCC_CONFIG_H_
#define RCC_RCC_CONFIG_H_

/* System clocks */
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/* PLL multipliers */
#define PLL_MULTIPLIER_X_2  0b0000
#define PLL_MULTIPLIER_X_3  0b0001
#define PLL_MULTIPLIER_X_4  0b0010
#define PLL_MULTIPLIER_X_5  0b0011
#define PLL_MULTIPLIER_X_6  0b0100
#define PLL_MULTIPLIER_X_7  0b0101
#define PLL_MULTIPLIER_X_8  0b0110
#define PLL_MULTIPLIER_X_9  0b0111
#define PLL_MULTIPLIER_X_10 0b1000
#define PLL_MULTIPLIER_X_11 0b1001
#define PLL_MULTIPLIER_X_12 0b1010
#define PLL_MULTIPLIER_X_13 0b1011
#define PLL_MULTIPLIER_X_14 0b1100
#define PLL_MULTIPLIER_X_15 0b1101
#define PLL_MULTIPLIER_X_16 0b1110

/* ABH pre-scaler */
#define ABH_PRE_SCALE_1   0b0000
#define ABH_PRE_SCALE_2   0b1000
#define ABH_PRE_SCALE_4   0b1001
#define ABH_PRE_SCALE_8   0b1010
#define ABH_PRE_SCALE_16  0b1011
#define ABH_PRE_SCALE_64  0b1100
#define ABH_PRE_SCALE_128 0b1101
#define ABH_PRE_SCALE_256 0b1110
#define ABH_PRE_SCALE_512 0b1111

/* APB low-speed pre-scaler (APB1) */
#define APB1_PRE_SCALE_1   0b000
#define APB1_PRE_SCALE_2   0b100
#define APB1_PRE_SCALE_4   0b101
#define APB1_PRE_SCALE_8   0b110
#define APB1_PRE_SCALE_16  0b111

/* APB high-speed pre-scaler (APB2) */
#define APB2_PRE_SCALE_1   0b000
#define APB2_PRE_SCALE_2   0b100
#define APB2_PRE_SCALE_4   0b101
#define APB2_PRE_SCALE_8   0b110
#define APB2_PRE_SCALE_16  0b111

/* Micro-controller clock output */
#define MCO_NO_CLOCK     0b000
#define MCO_SYSTEM_CLOCK 0b100
#define MCO_HSI          0b101
#define MCO_HSE 		 0b110
#define MCO_PLL 		 0b111

/* ADC pre-scaler */
#define ADC_PRE_SCALER_2 0b00
#define ADC_PRE_SCALER_4 0b01
#define ADC_PRE_SCALER_6 0b10
#define ADC_PRE_SCALER_8 0b11

/************ USER CONFIGURATIONS ************/
/* Choose system clock*/
#define SYSTEM_CLOCK  RCC_HSI

/** Choosing HSE type.
 * 0: oscillator.
 * 1: clock source.
 * */
#define HSEBYP 0

/** HSE divider for PLL entry.
 * 0: HSE clock not divided.
 * 1: HSE clock divided by 2.
 * */
#define PLL_HSE_DIVIDER 0

/** PLL entry clock source.
 * 0: HSI oscillator clock / 2 selected as PLL input clock.
 * 1: HSE oscillator clock selected as PLL input clock.
 * */
#define PLL_CLOCK_SOURCE 0

/** USB pre-scaler.
 * 0: PLL clock is divided by 1.5.
 * 1: PLL clock is not divided.
 * */
#define USB_PRE_SCALER 0

#define PLL_MULTIPLIER    PLL_MULTIPLIER_X_2

#define ABH_PRE_SCALER    ABH_PRE_SCALE_2
#define APB1_PRE_SCALER   APB1_PRE_SCALE_2
#define APB2_PRE_SCALER   APB2_PRE_SCALE_2

#define ADC_PRE_SCALER    ADC_PRE_SCALER_2

#define MCO_OUTPUT		  MCO_SYSTEM_CLOCK

#endif /* RCC_RCC_CONFIG_H_ */

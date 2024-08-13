/*
 * GPIO_Registers.h
 *
 *  Created on: Aug 12, 2024
 *      Author: abdal
 */

#ifndef GPIO_GPIO_REGISTERS_H_
#define GPIO_GPIO_REGISTERS_H_

#include "../../LIB/STD_TYPES.h"

#define GPIOA_BASE_ADDR 0x40010800
#define GPIOB_BASE_ADDR 0x40010C00
#define GPIOC_BASE_ADDR 0x40011000

typedef struct {
	U32 CRL;
	U32 CRH;
	U32 IDR;
	U32 ODR;
	U32 BSRR;
	U32 BRR;
	U32 LCKR;
} GPIO_RegDef_t;


#define GPIOA  ((GPIO_RegDef_t *) (GPIOA_BASE_ADDR))
#define GPIOB  ((GPIO_RegDef_t *) (GPIOB_BASE_ADDR))
#define GPIOC  ((GPIO_RegDef_t *) (GPIOC_BASE_ADDR))


#endif /* GPIO_GPIO_REGISTERS_H_ */

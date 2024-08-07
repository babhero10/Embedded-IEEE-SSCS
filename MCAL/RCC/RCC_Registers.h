/*
 * RCC_Registers.h
 *
 *  Created on: Aug 7, 2024
 *      Author: abdal
 */


#ifndef RCC_RCC_REGISTERS_H_
#define RCC_RCC_REGISTERS_H_

#include "../../LIB/STD_TYPES.h"

#define RCC_BASE_ADDRESS 0x40021400

typedef struct {
	U32 CR;
	U32 CFGR;
	U32 CIR;
	U32 APB2RSTR;
	U32 APB1RSTR;
	U32 AHBENR;
	U32 APB2ENR;
	U32 APB1ENR;
	U32 BDCR;
	U32 CSR;
} RCC_RegDef_t;


#define RCC ((RCC_RegDef_t *) RCC_BASE_ADDRESS)

#endif /* RCC_RCC_REGISTERS_H_ */

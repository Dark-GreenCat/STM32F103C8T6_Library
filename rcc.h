#ifndef RCC_H
#define RCC_H

#include "macro.h"
#include "bit_operation.h"

#define USER_RCC_BASE 0x40021000
#define USER_RCC_APB2ENR_OFFSET 0x18

void enable_RCC_GPIOA_clock();

#endif
#ifndef BIT_OPERATION_H
#define BIT_OPERATION_H

#include <stdint.h>
#include "macro.h"

void clear_bit(volatile uint32_t* REG, uint8_t bit_index);
void set_bit(volatile uint32_t* REG, uint8_t bit_index);

#endif

#include "bit_operation.h"

void clear_bit(volatile uint32_t* REG, uint8_t bit_index) {
    *REG &= ~BIT(bit_index);
}

void set_bit(volatile uint32_t* REG, uint8_t bit_index) {
    *REG |= BIT(bit_index);
}
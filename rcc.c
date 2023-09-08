#include "rcc.h"

void enable_RCC_GPIOA_clock() {
    set_bit(REG(USER_RCC_BASE + USER_RCC_APB2ENR_OFFSET), 2);
}
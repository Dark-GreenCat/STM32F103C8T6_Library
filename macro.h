#ifndef MACRO_H
#define MACRO_H

#include <stdint.h>

#define BIT(x) ((uint32_t) 1U << (x))
#define REG(x) ((volatile uint32_t *) (x))

#endif
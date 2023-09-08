#include "gpio.h"

void gpio_init_pin(gpio_init_t* GPIO_INIT) {
#define CLEAR_CNF_MODE(REG, x) { clear_bit((REG), (x)); clear_bit((REG), (x) + 1); }
    volatile uint32_t* config_reg = (GPIO_INIT->gpio_pin <= 7) ? &GPIO_INIT->gpio_port->CRL : &GPIO_INIT->gpio_port->CRH;

    /* Config io_mode */
    CLEAR_CNF_MODE(config_reg, 4 * (GPIO_INIT->gpio_pin % 8))
        * config_reg |= ((uint32_t)GPIO_INIT->io_mode) << (4 * (GPIO_INIT->gpio_pin % 8));

    /* Config io_config */
    if (GPIO_INIT->io_mode != MODE_INPUT) {
        CLEAR_CNF_MODE(config_reg, 4 * (GPIO_INIT->gpio_pin % 8) + 2)
            * config_reg |= ((uint32_t)GPIO_INIT->io_config) << (4 * (GPIO_INIT->gpio_pin % 8) + 2);
    }
    else {
        if (GPIO_INIT->io_config != CONFIG_INPUT_PULLDOWN && GPIO_INIT->io_config != CONFIG_INPUT_PULLUP) {
            CLEAR_CNF_MODE(config_reg, 4 * (GPIO_INIT->gpio_pin % 8) + 2)
                * config_reg |= ((uint32_t)GPIO_INIT->io_config) << (4 * (GPIO_INIT->gpio_pin % 8) + 2);
        }
        else {
            CLEAR_CNF_MODE(config_reg, 4 * (GPIO_INIT->gpio_pin % 8) + 2)
                * config_reg |= ((uint32_t)0b10) << (4 * (GPIO_INIT->gpio_pin % 8) + 2);
            if (GPIO_INIT->io_config == CONFIG_INPUT_PULLDOWN) {
                set_bit(&GPIO_INIT->gpio_port->BRR, GPIO_INIT->gpio_pin);
            }
            else {
                set_bit(&GPIO_INIT->gpio_port->BSRR, GPIO_INIT->gpio_pin);
            }
        }
    }
}

/* GPIO controlling */
void gpio_write(gpio_config_t* GPIOx, uint16_t GPIO_PIN, gpio_state_t PIN_STATE) {
    clear_bit(&GPIOx->BSRR, GPIO_PIN);

    if (PIN_STATE == HIGH) set_bit(&GPIOx->BSRR, GPIO_PIN);
    else set_bit(&GPIOx->BRR, GPIO_PIN);
}

uint8_t gpio_read(gpio_config_t* GPIOx, uint16_t GPIO_PIN) {
    return (GPIOx->IDR & BIT(GPIO_PIN)) ? HIGH : LOW;
}

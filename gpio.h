#ifndef GPIO_H
#define GPIO_H

#include "macro.h"
#include "bit_operation.h"

/*
 * DEFINED TYPE
 */
#define USER_GPIOA_BASE 0x40010800
#define USER_LED_GPIO_PORT (gpio_config_t *) USER_GPIOA_BASE
#define USER_LED_GPIO_PIN 6
#define USER_BUTTON_GPIO_PORT (gpio_config_t *) USER_GPIOA_BASE
#define USER_BUTTON_GPIO_PIN 1

typedef enum { LOW, HIGH } gpio_state_t;

typedef struct {
    uint32_t CRL;
    uint32_t CRH;
    uint32_t IDR;
    uint32_t ODR;
    uint32_t BSRR;
    uint32_t BRR;
    uint32_t LCKR;
} gpio_config_t;


enum { MODE_INPUT, MODE_OUTPUT_LOW_SPEED, MODE_OUTPUT_MEDIUM_SPEED, MODE_OUTPUT_HIGH_SPEED };
enum { CONFIG_INPUT_ANALOG, CONFIG_INPUT_FLOATING, CONFIG_INPUT_PULLUP, CONFIG_INPUT_PULLDOWN };
enum { CONFIG_OUTPUT_GP_PUSHPULL, CONFIG_OUTPUT_GP_OPENDRAIN, CONFIG_OUTPUT_AF_PUSHPULL, CONFIG_OUTPUT_AF_OPENDRAIN };

typedef struct {
    gpio_config_t* gpio_port;
    uint16_t gpio_pin;
    uint32_t io_mode;
    uint32_t io_config;
} gpio_init_t;


/*
 * FUNCTION
 */
void gpio_init_pin(gpio_init_t* GPIO_INIT);

/* GPIO controlling */
void gpio_write(gpio_config_t* GPIOx, uint16_t GPIO_PIN, gpio_state_t PIN_STATE);
uint8_t gpio_read(gpio_config_t* GPIOx, uint16_t GPIO_PIN);

#endif

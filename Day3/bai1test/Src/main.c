#include "my_gpio.h"
#include <stdint.h>


static void delay(uint32_t ms);


static void delay(uint32_t ms)
{
    volatile uint32_t i;
    for (i = 0; i < ms * 1000; i++) {

    }
}

int main(void) {

    My_GPIO_Init(GPIOA, GPIO_PIN_5, GPIO_MODE_OUTPUT, GPIO_OTYPE_PP, GPIO_SPEED_MEDIUM, GPIO_PUPD_NOPULL);


    My_GPIO_Init(GPIOC, GPIO_PIN_13, GPIO_MODE_INPUT, GPIO_OTYPE_PP, GPIO_SPEED_MEDIUM, GPIO_PUPD_PULLUP);

    uint8_t led_state = GPIO_PIN_RESET;
    uint8_t last_button_state = GPIO_PIN_SET;

    while (1) {
        uint8_t current_button_state = My_GPIO_ReadPin(GPIOC, GPIO_PIN_13);


        if (last_button_state == GPIO_PIN_SET && current_button_state == GPIO_PIN_RESET) {

            if (My_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
                delay(2000);
                led_state = !led_state;
                My_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state);
            }
        }

        last_button_state = current_button_state;
    }

    return 0;
}

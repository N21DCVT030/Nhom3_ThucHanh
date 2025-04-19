#include "my_gpio.h"
#include <stdint.h>

// Hàm delay nhận tham số thời gian (mili giây)
static void delay(uint32_t ms);

// Hàm delay (ước lượng cho 16 MHz clock)
static void delay(uint32_t ms)
{
    volatile uint32_t i;
    for (i = 0; i < ms * 1000; i++) {

    }
}

int main(void) {

    My_GPIO_Init(GPIOA, GPIO_PIN_5, GPIO_MODE_OUTPUT, GPIO_OTYPE_OD, GPIO_SPEED_MEDIUM, GPIO_PUPD_NOPULL);


    My_GPIO_Init(GPIOC, GPIO_PIN_13, GPIO_MODE_INPUT, GPIO_OTYPE_PP, GPIO_SPEED_MEDIUM, GPIO_PUPD_PULLUP);

    uint8_t led_state = GPIO_PIN_SET;
    uint8_t last_button_state = GPIO_PIN_SET;

    while (1) {
        uint8_t current_button_state = My_GPIO_ReadPin(GPIOC, GPIO_PIN_13);


        if (last_button_state == GPIO_PIN_SET && current_button_state == GPIO_PIN_RESET) {
            delay(200);

            if (My_GPIO_ReadPin(GPIOC, GPIO_PIN_13) == GPIO_PIN_RESET) {
                delay(500);
                led_state = !led_state; // trạng thái LED
                My_GPIO_WritePin(GPIOA, GPIO_PIN_5, led_state); // Cập nhật LED
            }
        }

        last_button_state = current_button_state;
    }

    return 0;
}

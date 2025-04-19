#include "my_gpio.h"

void My_GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t mode, uint8_t otype, uint8_t speed, uint8_t pupd) {
    // Bật clock cho GPIO
    if (GPIOx == GPIOA) {
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOA;
    } else if (GPIOx == GPIOC) {
        RCC_AHB1ENR |= RCC_AHB1ENR_GPIOC;
    }

    // Xác định vị trí bit trong thanh ghi MODER, PUPDR (2 bit mỗi chân)
    uint32_t pin_pos = 0;
    while ((pin & (1U << pin_pos)) == 0) pin_pos++;

    // Cấu hình chế độ (MODER)
    GPIOx->MODER &= ~(0x3 << (pin_pos * 2)); // Xóa bit cũ
    GPIOx->MODER |= (mode << (pin_pos * 2)); // Ghi mode

    // Cấu hình loại ngõ ra (OTYPER)
    GPIOx->OTYPER &= ~(0x1 << pin_pos); // Xóa bit cũ
    GPIOx->OTYPER |= (otype << pin_pos); // Ghi otype

    // Cấu hình tốc độ (OSPEEDR)
    GPIOx->OSPEEDR &= ~(0x3 << (pin_pos * 2)); // Xóa bit cũ
    GPIOx->OSPEEDR |= (speed << (pin_pos * 2)); // Ghi speed

    // Cấu hình pull-up/pull-down (PUPDR)
    GPIOx->PUPDR &= ~(0x3 << (pin_pos * 2)); // Xóa bit cũ
    GPIOx->PUPDR |= (pupd << (pin_pos * 2)); // Ghi pupd
}

uint8_t My_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pin) {
    return (GPIOx->IDR & pin) ? GPIO_PIN_SET : GPIO_PIN_RESET;
}

void My_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t state) {
    if (state == GPIO_PIN_SET) {
        GPIOx->BSRR = pin; // Set bit
    } else {
        GPIOx->BSRR = (pin << 16); // Reset bit
    }
}

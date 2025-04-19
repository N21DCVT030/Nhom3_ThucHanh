#ifndef MY_GPIO_H
#define MY_GPIO_H

#include <stdint.h>

// Định nghĩa các thanh ghi GPIO
#define GPIOA_BASE  0x40020000
#define GPIOC_BASE  0x40020800

typedef struct {
    volatile uint32_t MODER;   // Chế độ chân (Input/Output/AF/Analog)
    volatile uint32_t OTYPER;  // Loại ngõ ra (Push-Pull/Open-Drain)
    volatile uint32_t OSPEEDR; // Tốc độ chân
    volatile uint32_t PUPDR;   // Pull-up/Pull-down
    volatile uint32_t IDR;     // Input Data Register
    volatile uint32_t ODR;     // Output Data Register
    volatile uint32_t BSRR;    // Bit Set/Reset Register

} GPIO_TypeDef;

#define GPIOA  ((GPIO_TypeDef *)GPIOA_BASE)
#define GPIOC  ((GPIO_TypeDef *)GPIOC_BASE)

// Định nghĩa chân GPIO
#define GPIO_PIN_5   (1U << 5)  // PA5
#define GPIO_PIN_13  (1U << 13) // PC13

// Định nghĩa chế độ GPIO
#define GPIO_MODE_INPUT    0x00
#define GPIO_MODE_OUTPUT   0x01

// Định nghĩa loại ngõ ra
#define GPIO_OTYPE_PP      0x00  // Push-Pull
#define GPIO_OTYPE_OD      0x01  // Open-Drain

// Định nghĩa tốc độ
#define GPIO_SPEED_MEDIUM  0x01

// Định nghĩa pull-up/pull-down
#define GPIO_PUPD_NOPULL   0x00
#define GPIO_PUPD_PULLUP   0x01
#define GPIO_PUPD_PULLDOWN 0x02

// Định nghĩa trạng thái
#define GPIO_PIN_SET       1
#define GPIO_PIN_RESET     0

// Định nghĩa RCC
#define RCC_BASE           0x40023800
#define RCC_AHB1ENR        (*(volatile uint32_t *)(RCC_BASE + 0x30))
#define RCC_AHB1ENR_GPIOA  (1U << 0)
#define RCC_AHB1ENR_GPIOC  (1U << 2)

// Hàm khởi tạo GPIO
void My_GPIO_Init(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t mode, uint8_t otype, uint8_t speed, uint8_t pupd);

// Hàm đọc trạng thái chân
uint8_t My_GPIO_ReadPin(GPIO_TypeDef *GPIOx, uint32_t pin);

// Hàm ghi trạng thái chân
void My_GPIO_WritePin(GPIO_TypeDef *GPIOx, uint32_t pin, uint8_t state);

#endif

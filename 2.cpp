#include "stm32f10x.h"

void delay_ms(int ms) {
    for (int i = 0; i < ms * 8000; i++) {
        __asm("NOP");
    }
}

void EXTI0_IRQHandler(void) {
    if (EXTI->PR & (1<<0)) {
        GPIOC->ODR ^= (1<<13);
        EXTI->PR |= (1<<0);
    }
}

int main(void) {
    RCC->APB2ENR |= (1<<2) | (1<<4) | (1<<0);

    GPIOA->CRL &= ~(0xF << (0*4));
    GPIOA->CRL |=  (0x8 << (0*4));
    GPIOA->ODR |=  (1<<0);

    GPIOC->CRH &= ~(0xF << (5*4));
    GPIOC->CRH |=  (0x2 << (5*4));

    GPIOA->CRL &= ~(0xF << (5*4));
    GPIOA->CRL |=  (0x2 << (5*4));

    AFIO->EXTICR[0] &= ~(0xF << 0);
    EXTI->IMR  |= (1<<0);
    EXTI->FTSR |= (1<<0);
    NVIC_EnableIRQ(EXTI0_IRQn);

    while(1) {
        GPIOA->ODR ^= (1<<5);
        delay_ms(500);
    }
}
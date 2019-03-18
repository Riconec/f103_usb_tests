#ifndef DELAY_TIM6_H
#define DELAY_TIM6_H

#include "stdint.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>


void delay_setup(void);
void delay_us(uint16_t us);

#endif
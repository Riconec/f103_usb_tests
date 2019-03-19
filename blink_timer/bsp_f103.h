#ifndef BSP_F103_H
#define BSP_F103_H

#include "stdint.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/timer.h>

#define LED_PORT RCC_GPIOC
#define LED_PIN GPIO13
#define HSE_SOLDERED 8000000u


void bsp_init_8MHz_HSE(void);
void bsp_init_mco_pa8(void);

#endif

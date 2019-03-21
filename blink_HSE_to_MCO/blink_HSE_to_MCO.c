#include "stdint.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <bsp_f103.h>


int main(void) {

    /* Enable oscillators and jump to HSE assumed it is 8MHz */
    bsp_init_8MHz_HSE();

    /* Enable clock for GPIO port C and Alternate function IO */
    rcc_periph_clock_enable(RCC_GPIOC);
    /* Actually not needed for MCO */
    //rcc_periph_clock_enable(RCC_AFIO);

    /* Set pin to push-pull configuration */
    gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

    /* Debug output of the clock on PA8 */
    bsp_init_mco_pa8();

    /* Init port to "1" (LED off) */
    gpio_set(GPIOC, GPIO13);

    while (1u) {
        /* Wait a bit */
    //    delay_us(300000u);
    for (uint32_t i = 0; i < 800000; i++) {
		__asm__("nop");
	}
        /* Change the state of the LED */
        gpio_toggle(GPIOC, GPIO13);
    }

}



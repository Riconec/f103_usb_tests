#include "stdint.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>

#define LED_PORT RCC_GPIOC
#define LED_PIN GPIO13

int main(void) {

	/* Enable clock for GPIO port C */
	rcc_periph_clock_enable(RCC_GPIOC);

	/* Set pin to push-pull configuration */
	gpio_set_mode(GPIOC, GPIO_MODE_OUTPUT_2_MHZ, GPIO_CNF_OUTPUT_PUSHPULL, GPIO13);

	/* Init port to "1" (LED off) */
	gpio_set(GPIOC, GPIO13);

	while (1u) {
		/* Wait a bit */
		for (uint32_t i = 0; i < 800000; i++) {
			__asm__("nop");
		}

		/* Change the state of the LED */
		gpio_toggle(GPIOC, GPIO13);


	}

}

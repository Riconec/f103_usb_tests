#include "stdint.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/flash.h>
#include "bsp_f103.h"

void bsp_init_8MHz_HSE(void) {
    /* Clock setup */
    /* Enable HSI oscillator */
    rcc_osc_on(RCC_HSI);

    /* Enable HSE oscillator */
    rcc_osc_on(RCC_HSE);

    /* Wait for HSI to be ready */
    rcc_wait_for_osc_ready(RCC_HSI);

    /* Set HSI as system clock source till we are ready to use HSE */
    rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

    /* Set 1:1 clock ratio for peripheral busses */
    rcc_set_hpre(RCC_CFGR_HPRE_SYSCLK_NODIV);       /* AHB /1 */
    rcc_set_ppre1(RCC_CFGR_PPRE1_HCLK_NODIV);       /* APB1 /1 */
    rcc_set_ppre2(RCC_CFGR_PPRE2_HCLK_NODIV);       /* APB2 /1 */

    /* ADC clock prescaler /2 */
    rcc_set_adcpre(RCC_CFGR_ADCPRE_PCLK2_DIV2);     /* ADC /2 */

    /*
     * Sysclk is running with 8MHz -> 0 waitstates.
     * 0WS from 0-24MHz
     * 1WS from 24-48MHz
     * 2WS from 48-72MHz
     */
    flash_set_ws(FLASH_ACR_LATENCY_0WS);

    /* Wait for HSE to be ready */
    rcc_wait_for_osc_ready(RCC_HSE);

    /* Set HSE as system clock source */
    rcc_set_sysclk_source(RCC_CFGR_SW_SYSCLKSEL_HSICLK);

    /* Set the peripheral clock frequencies used */
    /* TODO: Calculate this out of input setings? */
    rcc_ahb_frequency = 8000000u;
    rcc_apb1_frequency = 8000000u;
    rcc_apb2_frequency = 8000000u;
}

void bsp_init_mco_pa8(void) {
    /* Enable clock for GPIO port A */
    rcc_periph_clock_enable(RCC_GPIOA);

    /* Set A8 pin to alternate push-pull (MCO) configuration */
    gpio_set_mode(GPIOA, GPIO_MODE_OUTPUT_50_MHZ, GPIO_CNF_OUTPUT_ALTFN_PUSHPULL, GPIO8);

    /* Select MCO source */
    rcc_set_mco(RCC_CFGR_MCO_SYSCLK);
}
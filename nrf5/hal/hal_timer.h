/*
 * This file is part of the Micro Python project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Glenn Ruben Bakke
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef HAL_TIMER_H__
#define HAL_TIMER_H__

#include "nrf.h"

#if NRF51
  #define TIMER_BASE_POINTERS (const uint32_t[]){NRF_TIMER0_BASE, \
                                                 NRF_TIMER1_BASE, \
                                                 NRF_TIMER2_BASE}
  #define TIMER_IRQ_VALUES (const uint32_t[]){TIMER0_IRQn, \
                                              TIMER1_IRQn, \
                                              TIMER2_IRQn}
#endif

#if NRF52
  #define TIMER_BASE_POINTERS (const uint32_t[]){NRF_TIMER0_BASE, \
                                                 NRF_TIMER1_BASE, \
                                                 NRF_TIMER1_BASE, \
                                                 NRF_TIMER1_BASE, \
                                                 NRF_TIMER2_BASE}
  #define TIMER_IRQ_VALUES (const uint32_t[]){TIMER0_IRQn, \
                                              TIMER1_IRQn, \
                                              TIMER2_IRQn, \
                                              TIMER3_IRQn, \
                                              TIMER4_IRQn}
#endif

#define TIMER_BASE(x) ((NRF_TIMER_Type *)TIMER_BASE_POINTERS[x])
#define TIMER_IRQ_NUM(x) (TIMER_IRQ_VALUES[x])

/**
  * @brief  Timer Configuration Structure definition
  */
typedef struct {
} hal_timer_init_t;

/**
  * @brief  Timer handle Structure definition
  */
typedef struct __Timer_HandleTypeDef
{
    NRF_TIMER_Type             *instance;    /* Timer registers base address */
    hal_timer_init_t           init;         /* Timer initialization parameters */
    uint8_t                    id;           /* Timer instance id */
} Timer_HandleTypeDef;

void hal_timer_init(NRF_TIMER_Type * p_instance, hal_timer_init_t const * p_timer_init);

#endif // HAL_TIMER_H__

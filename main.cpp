/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "mbed.h"
#include "2SMPB02E.h"

using namespace sixtron;

namespace {
#define HALF_PERIOD 2s
}

static DigitalOut led1(LED1);

O2SMPB02E smp(I2C1_SDA, I2C1_SCL);

int main()
{
    if(!smp.init()){
        printf("Failed to init 2SMPB02E\n");
    }
    while (true) {
        led1 = !led1;
        smp.temperature();
        // if (led1) {
        //     printf("Alive!\n");
        // }
        ThisThread::sleep_for(HALF_PERIOD);
    }
}

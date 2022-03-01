/*
 * Copyright (c) 2022, CATIE
 * SPDX-License-Identifier: Apache-2.0
 */
#include "2SMPB02E.h"
#include "mbed.h"

using namespace sixtron;

namespace {
#define PERIOD 1s
}

static DigitalOut led1(LED1);

O2SMPB02E smp(I2C1_SDA, I2C1_SCL);

int main()
{
    if (!smp.init()) {
        printf("Failed to init 2SMPB02E\n");
    }

    // Single Measurement
    smp.measure_single_shot();

    ThisThread::sleep_for(100ms);

    printf("Temperature: %f °C\n", smp.temperature() / 256.0);
    printf("Pressure: %f hPa\n\n", smp.pressure() / 100.0);

    // Periodic Measurement
    smp.start_periodic_measurement();

    while (true) {
        led1 = !led1;
        printf("Temperature: %f °C\n", smp.temperature() / 256.0);
        printf("Pressure: %f hPa\n\n", smp.pressure() / 100.0);
        ThisThread::sleep_for(PERIOD);
    }
}

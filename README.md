# Omron 2SMPB-02E Example
Omron 2SMPB-02E driver for Mbed OS

## Requirements
### Hardware requirements
The following boards are required:
- *List Omron 2SMPB-02E Example hardware requirements here*

### Software requirements
Omron 2SMPB-02E Example makes use of the following libraries (automatically
imported by `mbed deploy` or `mbed import`):
- *List Omron 2SMPB-02E Example software requirements here*

## Usage
To clone **and** deploy the project in one command, use `mbed import` and skip to the
target enabling instructions:
```shell
mbed import https://gitlab.com/catie_6tron/omron-2smpb-02e-example.git omron-2smpb-02e-example
```

Alternatively:

- Clone to "omron-2smpb-02e-example" and enter it:
  ```shell
  git clone https://gitlab.com/catie_6tron/omron-2smpb-02e-example.git omron-2smpb-02e-example
  cd omron-2smpb-02e-example
  ```

- Deploy software requirements with:
  ```shell
  mbed deploy
  ```

Enable the custom target:
```shell
cp zest-core-stm32l562ve/custom_targets.json .
```

Compile the project:
```shell
mbed compile
```

Program the target device with a Segger J-Link debug probe and
[`sixtron_flash`](https://gitlab.com/catie_6tron/6tron-flash) tool:
```shell
sixtron_flash stm32l562ve BUILD/ZEST_CORE_STM32L562VE/GCC_ARM/omron-2smpb-02e-example.elf
```

Debug on the target device with the probe and Segger
[Ozone](https://www.segger.com/products/development-tools/ozone-j-link-debugger)
software.

# Open Farm Valve Controller Firmware

Zephyr-based firmware for the Open Farm wireless latch valve controller.

## Target

- MCU: STM32 / STM32WL series
- RTOS: Zephyr OS
- Application: low-power wireless valve controller
- Features:
  - latch valve pulse control
  - battery monitoring
  - wireless command handling
  - watchdog and fault recovery

## Roadmap

- [ ] LED + logging bring-up
- [ ] Valve GPIO abstraction
- [ ] Valve state machine
- [ ] Persistent configuration
- [ ] Low power mode
- [ ] LoRa command protocol
- [ ] Custom board support

solenoid-valve-controller/
│
├── app/
│   │
│   ├── CMakeLists.txt
│   ├── prj.conf
│   ├── Kconfig
│   │
│   ├── boards/                     # Zephyr Board Definition (KHÔNG ĐỤNG)
│   │   └── arm/
│   │       └── openfarm_f407vet6/
│   │
│   ├── dts/
│   │   ├── overlays/
│   │   └── bindings/
│   │
│   ├── include/
│   │
│   │   ├── bsp/
│   │   ├── drivers/
│   │   ├── services/
│   │   ├── protocol/
│   │   ├── system/
│   │   ├── app/
│   │   └── common/
│   │
│   └── src/
│       │
│       ├── main.c
│       │
│       ├── bsp/
│       │   │
│       │   ├── board/
│       │   ├── gpio/
│       │   ├── led/
│       │   ├── button/
│       │   ├── uart/
│       │   ├── spi/
│       │   ├── i2c/
│       │   ├── adc/
│       │   ├── pwm/
│       │   ├── watchdog/
│       │   ├── rtc/
│       │   ├── flash/
│       │   └── power/
│       │
│       ├── drivers/
│       │   │
│       │   ├── bq25798/
│       │   ├── a7680c/
│       │   ├── sx1262/
│       │   ├── w25q128/
│       │   ├── at24cxx/
│       │   ├── lora/
│       │   └── ...
│       │
│       ├── services/
│       │   │
│       │   ├── led_manager/
│       │   ├── valve_manager/
│       │   ├── battery_manager/
│       │   ├── network_manager/
│       │   ├── storage_manager/
│       │   ├── watchdog_manager/
│       │   ├── sensor_manager/
│       │   ├── command_manager/
│       │   ├── firmware_manager/
│       │   └── logger/
│       │
│       ├── protocol/
│       │   │
│       │   ├── mqtt/
│       │   ├── lora/
│       │   ├── uart/
│       │   ├── sms/
│       │   ├── at/
│       │   └── packet/
│       │
│       ├── system/
│       │   │
│       │   ├── app_init/
│       │   ├── config/
│       │   ├── event/
│       │   ├── state_machine/
│       │   ├── scheduler/
│       │   ├── shell/
│       │   ├── diagnostics/
│       │   └── fault/
│       │
│       ├── app/
│       │   │
│       │   ├── application.c
│       │   ├── application.h
│       │   ├── app_tasks.c
│       │   ├── app_events.c
│       │   └── app_config.c
│       │
│       └── common/
│           │
│           ├── types.h
│           ├── error.h
│           ├── macros.h
│           ├── version.h
│           ├── crc.c
│           ├── utils.c
│           └── ring_buffer.c
│
├── docs/
│   ├── architecture/
│   ├── hardware/
│   ├── protocol/
│   ├── images/
│   └── api/
│
├── scripts/
│   ├── flash.sh
│   ├── build.sh
│   ├── format.sh
│   └── release.sh
│
├── tests/
│
├── tools/
│
├── .github/
│   └── workflows/
│
├── README.md
├── CHANGELOG.md
└── LICENSE
Layer kiến trúc

Đây là phần quan trọng nhất.

                    Application
                         │
               -------------------
               |                 |
          Valve Manager     Network Manager
               |                 |
        Battery Manager     Storage Manager
               |                 |
        ----------------------------
               Drivers
        ----------------------------
      BQ25798   A7680C   SX1262
               |     |      |
        ----------------------------
                  BSP
        GPIO UART SPI I2C ADC PWM
               |
            Zephyr OS
               |
        STM32 HAL + DeviceTree
               |
            STM32F407


source ~/.zephyr_env
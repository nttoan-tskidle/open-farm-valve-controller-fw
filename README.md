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
#ifndef BOARD_H 
#define BOARD_H

#include <stdint.h>

typedef enum
{
    BOARD_LED_HEARTBEAT = 0,
    BOARD_LED_UART,
    BOARD_LED_WIFI,
    BOARD_LED_SIM,
    BOARD_LED_MQTT,
    BOARD_LED_FLASH,
    BOARD_LED_VALVE,
    BOARD_LED_MAX
} board_led_t;

typedef enum {
    BOARD_BUTTON_BOOT = 0,
    BOARD_BUTTON_USER,
    BOARD_BUTTON_MAX
} board_button_t;

typedef enum
{
    BOARD_GPIO_SIM_PWR = 0,
    BOARD_GPIO_SIM_RESET,
    BOARD_GPIO_FLASH_CS,
    BOARD_GPIO_VALVE_A,
    BOARD_GPIO_VALVE_B,
    BOARD_GPIO_MAX
} board_gpio_t;

typedef enum
{
    BOARD_UART_DEBUG = 0,
    BOARD_UART_SIM,
    BOARD_UART_RS485,
    BOARD_UART_MAX
} board_uart_t;

typedef enum
{
    BOARD_SPI_FLASH = 0,
    BOARD_SPI_MAX
} board_spi_t;

typedef enum
{
    BOARD_I2C_BQ25798 = 0,
    BOARD_I2C_SENSOR,
    BOARD_I2C_MAX
} board_i2c_t;

typedef enum {
    BOARD_ADC_BATTERY = 0,
    BOARD_ADC_SOLAR,
    BOARD_ADC_ADAPTER,
    BOARD_ADC_VALVE_CURRENT,
    BOARD_ADC_PUMP_CURRENT,
    BOARD_ADC_BOARD_TEMP,
    BOARD_ADC_MAX
} board_adc_t;

int board_init(void);

#endif /* BOARD_H */
#include "services/system/system_service.h"

#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(system_service, LOG_LEVEL_INF);

typedef enum {
    SYSTEM_BOOT_STATE_START = 0,
    SYSTEM_BOOT_STATE_HW_CHECK,
    SYSTEM_BOOT_STATE_LOAD_CONFIG,
    SYSTEM_BOOT_STATE_START_LED,
    SYSTEM_BOOT_STATE_START_APP,
    SYSTEM_BOOT_STATE_READY,
    SYSTEM_BOOT_STATE_ERROR,
} system_boot_state_t;

static system_boot_state_t boot_state = SYSTEM_BOOT_STATE_START;

static int system_hw_check(void)
{
    LOG_INF("Hardware check start");

    /*
     * Sau này kiểm tra:
     * - reset reason
     * - battery voltage
     * - external flash
     * - RTC
     * - watchdog
     * - device ID
     */

    LOG_INF("Hardware check OK");
    return 0;
}

static int system_load_config(void)
{
    LOG_INF("Load configuration start");

    /*
     * Sau này đọc config từ NVS/Flash:
     * - device_id
     * - farm_id
     * - mqtt broker
     * - SIM APN
     * - valve config
     */

    LOG_INF("Load configuration OK");
    return 0;
}

static int system_start_led(void)
{
    LOG_INF("Start LED service");

    /*
     * Sau này gọi:
     * led_service_start();
     */

    LOG_INF("LED service OK");
    return 0;
}

static int system_start_app(void)
{
    LOG_INF("Start application services");

    /*
     * Sau này gọi:
     * power_service_start();
     * sensor_service_start();
     * lora_service_start();
     * sim_service_start();
     * mqtt_service_start();
     * valve_service_start();
     */

    LOG_INF("Application services OK");
    return 0;
}

int system_service_start(void)
{
    int ret = 0;

    LOG_INF("System service start");

    while (boot_state != SYSTEM_BOOT_STATE_READY &&
           boot_state != SYSTEM_BOOT_STATE_ERROR) {

        switch (boot_state) {
        case SYSTEM_BOOT_STATE_START:
            LOG_INF("Boot state: START");
            boot_state = SYSTEM_BOOT_STATE_HW_CHECK;
            break;

        case SYSTEM_BOOT_STATE_HW_CHECK:
            LOG_INF("Boot state: HW_CHECK");
            ret = system_hw_check();
            boot_state = (ret == 0) ?
                SYSTEM_BOOT_STATE_LOAD_CONFIG :
                SYSTEM_BOOT_STATE_ERROR;
            break;

        case SYSTEM_BOOT_STATE_LOAD_CONFIG:
            LOG_INF("Boot state: LOAD_CONFIG");
            ret = system_load_config();
            boot_state = (ret == 0) ?
                SYSTEM_BOOT_STATE_START_LED :
                SYSTEM_BOOT_STATE_ERROR;
            break;

        case SYSTEM_BOOT_STATE_START_LED:
            LOG_INF("Boot state: START_LED");
            ret = system_start_led();
            boot_state = (ret == 0) ?
                SYSTEM_BOOT_STATE_START_APP :
                SYSTEM_BOOT_STATE_ERROR;
            break;

        case SYSTEM_BOOT_STATE_START_APP:
            LOG_INF("Boot state: START_APP");
            ret = system_start_app();
            boot_state = (ret == 0) ?
                SYSTEM_BOOT_STATE_READY :
                SYSTEM_BOOT_STATE_ERROR;
            break;

        default:
            LOG_ERR("Invalid boot state");
            boot_state = SYSTEM_BOOT_STATE_ERROR;
            break;
        }

        k_msleep(10);
    }

    if (boot_state == SYSTEM_BOOT_STATE_READY) {
        LOG_INF("System boot completed");
        return 0;
    }

    LOG_ERR("System boot failed");
    return -EIO;
}
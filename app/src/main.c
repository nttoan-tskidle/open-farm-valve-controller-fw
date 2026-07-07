#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "services/system/system_service.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    LOG_INF("==================================");
    LOG_INF("Open Farm Foundation");
    LOG_INF("Firmware boot");
    LOG_INF("Board: %s", CONFIG_BOARD);
    LOG_INF("==================================");

    int ret = system_service_start();

    if (ret != 0) {
        LOG_ERR("System failed to start: %d", ret);
        return ret;
    }

    LOG_INF("Application is running");

    while (1) {
        k_sleep(K_SECONDS(1));
    }

    return 0;
}
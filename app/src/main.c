#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "bsp/board/board.h"

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    int ret = board_init();
    if (ret < 0) {
        LOG_ERR("Board init failed: %d", ret);
        return ret;
    }

    LOG_INF("Open Farm valve controller started");

    while (1) {
        LOG_INF("System heartbeat");
        k_sleep(K_SECONDS(1));
    }

    return 0;
}
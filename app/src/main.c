#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(main, LOG_LEVEL_INF);

int main(void)
{
    LOG_INF("Open Farm Valve Controller firmware started");

    while (1) {
        LOG_INF("System alive");
        k_sleep(K_SECONDS(2));
    }

    return 0;
}
#include "bsp/board/board.h"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(board, LOG_LEVEL_INF);

int board_init(void)
{
    LOG_INF("Board initialization started");

    /*
     * Board-level initialization will be added here.
     * Keep this function responsible for board resource bring-up only.
     */

    LOG_INF("Board initialization completed");

    return 0;
}
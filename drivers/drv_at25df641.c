/*
 * Copyright (c) 2006-2020, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2021-01-21     A19582       the first version
 */

#include "drv_spi.h"
#include <rtthread.h>
#include <rtdevice.h>
#include "dfs_fs.h"
#include "spi_flash_sfud.h"

int rt_spi_opt_at25df641_init(void)
{
    rt_hw_spi_device_attach("spi2", "spi20", GPIOA, GPIO_PIN_1);

    if (rt_sfud_flash_probe("AT25DF641", "spi20"))
    {
        rt_kprintf("rt sfud flash probe success\n");
        return RT_EOK;
    }
    else {
        rt_kprintf("rt sfud flash probe fail\n");
        return RT_EOK;
    }

    return 0;
}

INIT_COMPONENT_EXPORT(rt_spi_opt_at25df641_init);

int dfs_mount_init(void)
{
    dfs_mkfs("elm", "AT25DF641");

    if(dfs_mount("AT25DF641", "/", "elm", 0, 0) == 0)
    {
        rt_kprintf("dfs_mount success\n");
        return RT_EOK;
    }
    else {
        rt_kprintf("dfs_mount fail\n");
        return -RT_ERROR;
    }
}

//INIT_COMPONENT_EXPORT(dfs_mount_init);

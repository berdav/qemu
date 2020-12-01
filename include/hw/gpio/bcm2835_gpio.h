/*
 * Raspberry Pi (BCM2835) GPIO Controller
 *
 * Copyright (c) 2017 Antfield SAS
 *
 * Authors:
 *  Clement Deschamps <clement.deschamps@antfield.fr>
 *  Luc Michel <luc.michel@antfield.fr>
 *
 * GPIO External support
 *  Davide Berardi <berardi.dav@gmail.com>
 *
 * This work is licensed under the terms of the GNU GPL, version 2 or later.
 * See the COPYING file in the top-level directory.
 */

#ifndef BCM2835_GPIO_H
#define BCM2835_GPIO_H

#define ARM_IRQS 8
#define GPU_IRQS 64

#include "hw/sd/sd.h"
#include "hw/sysbus.h"
#include "qom/object.h"
#include "hw/intc/bcm2835_ic.h"

struct BCM2835GpioState {
    SysBusDevice parent_obj;
    CPUState *cpu;

    MemoryRegion iomem;

    /* SDBus selector */
    SDBus sdbus;
    SDBus *sdbus_sdhci;
    SDBus *sdbus_sdhost;
    BCM2835ICState *ic;

    uint8_t fsel[54];
    uint32_t lev0, lev1;
    /* Event detection */
    uint32_t eds0, eds1;
    /* Edge selector */
    uint32_t ren0, ren1;
    uint32_t fen0, fen1;

    uint8_t sd_fsel;
    qemu_irq out[54];
    qemu_irq irq[3];
};

#define TYPE_BCM2835_GPIO "bcm2835_gpio"
OBJECT_DECLARE_SIMPLE_TYPE(BCM2835GpioState, BCM2835_GPIO)

#endif

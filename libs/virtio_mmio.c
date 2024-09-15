#include "virtio_mmio.h"
#include "arch_mmio.h"

// デバイスステータスレジスタを読み込む
static uint32_t read_device_status(struct virtio_mmio *dev) {
    return mmio_read32le(dev->base + VIRTIO_REG_DEVICE_STATUS);
}

// デバイスステータスレジスタに書き込む
static void write_device_status(struct virtio_mmio *dev, uint8_t value) {
    mmio_write32le(dev->base + VIRTIO_REG_DEVICE_STATUS, value);
}

static void virtio_blk_init(struct virtio_mmio *dev,unsigned index){

    // reset the device
    write_device_status(dev,0);

    // set the acknowledge
    write_device_status(dev,VIRTIO_STATUS_ACK);

    // set the driver status bit
    write_device_status(dev,VIRTIO_STATUS_DRIVER);

    // 
}
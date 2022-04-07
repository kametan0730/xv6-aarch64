#include "virtio_net.h"
#include "types.h"
#include "aarch64.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "sleeplock.h"
#include "fs.h"
#include "buf.h"

#define R1(r) ((volatile uint8 *)(VIRTIO1 + (r)))

#define write_io8(a, r) ((volatile uint8 *)(VIRTIO1 + (r)))

void virtio_net_init(){

    printf("loading virtio-net\n");

    printf("mac_address: %x:%x:%x:%x:%x:%x\n", *R1(0x100), *R1(0x101), *R1(0x102), *R1(0x103), *R1(0x104), *R1(0x105));


}
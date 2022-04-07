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
#include "virtio.h"

#define R1_32(r) ((volatile uint32 *)(VIRTIO1 + (r)))
#define W1_8(r, v) (volatile uint8*)(VIRTIO1 + (r)) = v
#define W1_16(r, v) *((volatile uint16*)(VIRTIO1 + (r))) = v

typedef struct  {
    uint8 mac[6];
    uint16 status;
    uint16 max_virtqueue_pairs;
    uint16 mtu;
} virtio_net_config;

void virtio_net_init(){

    if(*R1_32(VIRTIO_MMIO_MAGIC_VALUE) != 0x74726976 ||
       *R1_32(VIRTIO_MMIO_VERSION) != 1 ||
       *R1_32(VIRTIO_MMIO_DEVICE_ID) != 1 ||
       *R1_32(VIRTIO_MMIO_VENDOR_ID) != 0x554d4551){
        panic("could not find virtio net");
    }


    printf("loading virtio-net\n");



    //printf("mac_address: %x:%x:%x:%x:%x:%x\n", *R1(0x100), *R1(0x101), *R1(0x102), *R1(0x103), *R1(0x104), *R1(0x105));


    /*
    W1_16(0x110, 0x5C8);
     */

    /*
    virtio_net_config* netconf = (virtio_net_config*) (VIRTIO1 + 0x100);
    printf("mac_address: %x:%x:%x:%x:%x:%x\n", netconf->mac[0], netconf->mac[1], netconf->mac[2], netconf->mac[3], netconf->mac[4], netconf->mac[5]);

    printf("mtu: %x\n", netconf->mtu);
    netconf->mtu = 1440;
    printf("mtu: %x\n", netconf->mtu);


    for(int i = 0; i < 0x200; i += 1){
        printf("%x: %x\n", i, *R1(i));
    }
    */

}
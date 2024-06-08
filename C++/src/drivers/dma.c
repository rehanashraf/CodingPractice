/*
 * dma.cpp
 *
 *  Created on: Sep 21, 2023
 *      Author: rehanashraf
 */



/* Hardware base address of register set */
#define DEVICE_BASE_ADDRESS 0x7f004000

/* Structure representing DMA device register set */
typedef struct {
    unsigned long cmd;
    unsigned long status;
    unsigned long source_address;
    unsigned long destination_address;
    unsigned long count;
} volatile dma_dev_regs_t;

/*
     Function to do a dma.

     Parameters:
     source        starting address of data to move
     dest          starting address of destination
     count         byte count of data to move

*/
void do_dma(unsigned long source, unsigned long dest, int count) {

    dma_dev_regs_t *pRegs = DEVICE_BASE_ADDRESS;

    pRegs->status = 0;

    pRegs->source_address = source;
    pRegs->destination_address = dest;
    pRegs->count = count;

    pRegs->cmd = 1;

    while ( pRegs->status == 0 ) {}
}

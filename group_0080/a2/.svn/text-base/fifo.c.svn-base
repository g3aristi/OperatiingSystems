#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

int lastEvicted = 0;

/* Page to evict is chosen using the fifo algorithm
 * Returns the slot in the coremap that held the page that
 * was evicted.
 */
int fifo_evict(struct page *p) {
    if(lastEvicted >= memsize){
	lastEvicted = 0;
    }
    lastEvicted++;
    struct page *victim = find_page(coremap[lastEvicted-1].vaddr);
    victim->pframe = -1;
	
    return lastEvicted-1;
}

/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void fifo_init() {
}

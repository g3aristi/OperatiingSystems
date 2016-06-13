#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

extern int time;

/* Page to evict is chosen using the accurate LRU algorithm 
 * Returns the slot in the coremap that held the page that
 * was evicted.
 */

int lru_evict(struct page *p) {
	int slot, i = 0;
	int oldest = time;
	for(i = 0; i < memsize; i++){
		//The smallest time its the least recently accessed
		if(coremap[i].lruStamp > oldest){
			oldest = coremap[i].lruStamp;
			slot = i;
		}
	}
	struct page *victim = find_page(coremap[slot].vaddr);
	victim->pframe = -1;
	return slot;
}


/* Initialize any data structures needed for this 
 * replacement algorithm 
 */
void lru_init() {
}

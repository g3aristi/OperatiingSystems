#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"


extern int memsize;

extern int debug;

extern struct frame *coremap;

extern  int clock;

/* Page to evict is chosen using the accurate clock algorithm 
 * Returns the slot in the coremap that held the page that
 * was evicted.
 */

int clock_evict(struct page *p) {
	while(1){
		clock++;
		if(clock == memsize){
			clock = 0;
		}

		if(coremap[clock].clockFlag == 1){
			coremap[clock].clockFlag = 0;

		} else {
			struct page *victim = find_page(coremap[clock].vaddr);
			victim->pframe = -1;	
			return clock;
		}
	}
}

/* Initialize any data structures needed for this replacement
 * algorithm 
 */
void clock_init() {
}

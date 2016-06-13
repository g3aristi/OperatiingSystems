#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <getopt.h>
#include <stdlib.h>
#include "pagetable.h"

#define MAXLINE 256

extern int memsize;
extern struct frame *coremap;

extern char *tracefile;
extern int ref_count;
int length = 0;
addr_t *trace_array;

void line_count(){
	FILE *file = NULL;
	if((file = fopen(tracefile, "r")) == NULL) {
		perror("Error opening tracefile:");
		exit(1);
	}

	char buf[MAXLINE];//, type;

	while(fgets(buf, MAXLINE, file) != NULL) {
		if(buf[0] != '=') {
			length++;
		} else {
			continue;
		}

	}
}

 int opt_evict(struct page *p){
	int maxDistance = -1;
 	int distance = -1;
	int coreCur, traceCur;
	int slot = -1;

 	for(coreCur = 0; coreCur < memsize; coreCur++){
 		distance = 0;
 		for(traceCur = ref_count; traceCur < length; traceCur++){ 
 			if(coremap[coreCur].vaddr == trace_array[traceCur]){
 				break;
 			}
 			distance++;
 		}

 		if(distance > maxDistance){
 			maxDistance = distance;
 			slot = coreCur;
 		}
 	}
	struct page *victim = find_page(coremap[slot].vaddr);
	victim->pframe = -1;
	return slot;
 }

/* Initializes any data structures needed for this
 * replacement algorithm.
 */
void opt_init() {
	line_count();
	FILE *file = NULL;
	trace_array = malloc(length * sizeof(addr_t));
	char buf[MAXLINE];
	char type;
	addr_t vaddr = 0;
	int length = 0; 
	int i = 0;

	if((file = fopen(tracefile, "r")) == NULL) {
		perror("Error opening tracefile:");
		exit(1);
	}

	while(fgets(buf, MAXLINE, file) != NULL) {
		if(buf[0] != '=') {
			sscanf(buf, " %c %lx,%u", &type, &vaddr, &length);
			vaddr = vaddr & ~0xfff;
			trace_array[i] = vaddr;
			i++;
		} else {
			continue;
		}

	}
}


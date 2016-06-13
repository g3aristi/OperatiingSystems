#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <math.h>

#define SYSTEM_MALLOC 1
#define BIG_CHUNK 136158 //4096*33

typedef struct node{
	int size;
	int usage; //0 unused(free), 1 used(allocated)
	struct node * next;
} node;


node *head = NULL;
int thread = 0;
static pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void initialize_heap(unsigned int size);
void *make_space(struct node *node, unsigned int size);
void *split(struct node *node, unsigned int size);

void print_list();


void initialize_heap(unsigned int size){
	if (size + (int) sizeof(node) > BIG_CHUNK){
  		head = sbrk(size + (int) sizeof(node));
		head->size = size + (int) sizeof(node);

	} else {
		head = sbrk(BIG_CHUNK);
		head->size = BIG_CHUNK;
	}
	head->next = NULL;
	head->usage = 0;
	thread = 1;

}


void *make_space(struct node *cur, unsigned int size){
printf("making more space\n");
	//alloc_node is the node with memory, free_node is leftover memory
	node *alloc_node;
	//still no memory left
	if ((size + sizeof(node)) > BIG_CHUNK){
		alloc_node = sbrk(size);
		alloc_node->size = size + (int) sizeof(node);
	//alloc node returned, free_node->usage node with leftover memory
	} else {
		alloc_node = sbrk(BIG_CHUNK);
		alloc_node->size = size + (int) sizeof(node);
		node *free_node = NULL;
		free_node = alloc_node;
		free_node += 1;
		free_node = (void *)free_node + size;
		alloc_node->size = BIG_CHUNK - size - (int) sizeof(node);
		free_node->usage = 0;
		free_node->next = NULL;
		alloc_node->next = free_node;
	}
	alloc_node->usage = 1;
	cur->next = alloc_node;
	pthread_mutex_unlock(&lock);
	return (void*)alloc_node + 1;
}


void *split(struct node *cur, unsigned int size){
	if(cur->size - (size + sizeof(node)) < (sizeof(node) + 8)){
		cur->size = size;
		cur->usage = 1;
		pthread_mutex_unlock(&lock);
		return (void *)cur + 1;
	}
	//split cur into alloc node(cur) and free node
	node *free_node;
	free_node = cur;
	free_node += 1;
	free_node = (void *)free_node + size;
	free_node->size = cur->size - size - (int) sizeof(node);
	free_node->usage = 0;
	free_node->next = cur->next;

	cur->next = free_node;
	cur->size = size + sizeof(node);
	cur->usage = 1;
	pthread_mutex_unlock(&lock);
	return (void*)cur + 1;
}


/* mymalloc: allocates memory on the heap of the requesthd size. The block
 of memory returned should always be padded so that it begins
 and ends on a word boundary.
 unsigned int size: the number of bytes to allocate.
 retval: a pointer to the block of memory allocated or NULL if the
 memory could not be allocated.
 (NOTE: the system also sets errno, but we are not the system,
 so you are not required to do so.)
 */

void *mymalloc(unsigned int size) {
    pthread_mutex_lock(&lock);
    //Adding the padding.
    size = (size + (size%8));
	//first thread to arrive.
	if (!thread){
		initialize_heap(size);
	}

	node *cur = NULL;
	cur = head;
	while(cur){
		//case 1: no sufficient space
		if(cur->next == NULL && (cur->usage || (cur->size < size + (int) sizeof(node)))){
			return make_space(cur, size);			
		}


		//case 2: Found a free node with enough space
		else if(cur->usage == 0 && cur->size > size + (int) sizeof(node)){
			return split(cur, size);

		} //case 3: keep checking for space and getting ride of node size 0
                if(!cur->next->size && cur->next->next){
                        cur->next = cur->next->next;
                }
		cur = cur->next;
	}
	pthread_mutex_unlock(&lock);
	return NULL;
}


/* myfree: unallocates memory that has been allocated with mymalloc.
 void *ptr: pointer to the first byte of a block of memory allocated by
 mymalloc.
 retval: 0 if the memory was successfully freed and 1 otherwise.
 (NOTE: the system version of free returns no error.)
 */
unsigned int myfree(void *ptr) {
	pthread_mutex_lock(&lock);
	node *cur = NULL;
	cur = head; 
	node *prev = NULL;
	while(cur){
		if((void *)cur + 1 == ptr){
			cur->usage = 0;

			//check if the previous node is freed, if so merge.
			if(prev && prev->usage == 0){
				prev->size = prev->size + cur->size;
				prev->next = cur->next;
			} // check if next node is freed, if so merge.

			if(cur->next && cur->next->usage == 0){
				cur->size = cur->size + cur->next->size;
				cur->next = cur->next->next;
			}

			pthread_mutex_unlock(&lock);
			return 0;

		}

		prev = cur;
		cur = cur->next;

	}
	pthread_mutex_unlock(&lock);
	return 1;
}


void print_list() {
	node *cur = NULL;
	cur = head;
    while(cur){
        printf("addres:  \t%#014lx-usage: %d-node: %d -> \n",(unsigned long) cur, cur->usage, cur->size);
        cur = cur->next;
    }
    printf("\n");
}

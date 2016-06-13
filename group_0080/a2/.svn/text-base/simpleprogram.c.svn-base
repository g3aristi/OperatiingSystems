#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


void my_fork(){
    char message[] = "Simple program for assigment 2";
    int fd[2];
    
    int result;
    if((result = pipe(fd)) == -1) {
        perror("pipe error");
        exit(1);
    }

    int r;
    if((r = fork()) == -1) {
        perror("fork");
        exit(1);
        
    //PARENT
    } else if (r > 0) { 
        close(fd[0]);

        if(write(fd[1], message, sizeof(message)) == -1) {
            perror("write to pipe");
        }

        close(fd[1]);
        
	//CHILD
    } else {
 
        // Child will read from parent
        char other[256];

        while(read(fd[0], other, sizeof(message)) > 0) {
            printf("[%d] child received %s", getpid(), other);
        }
        printf("child finished reading");
    }

}

// simple program using a pipe the parent writes to the child
int main() {

	/* Markers used to bound trace regions of interest */
	volatile char MARKER_START, MARKER_END;
	/* Record marker addresses */
	FILE* marker_fp = fopen("sp.marker","w");
	if(marker_fp == NULL ) {
		perror("Couldn't open marker file:");
		exit(1);
	}
	fprintf(marker_fp, "%p %p", &MARKER_START, &MARKER_END );
	fclose(marker_fp);

	MARKER_START = 33;
	my_fork();
	MARKER_END = 34;

	return 0;
}

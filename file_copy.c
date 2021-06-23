#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define MaxBuf 8192

int main(int argc, char **argv){
	int fd_in, fd_out;
	size_t readCnt, offset, curPos;
	char buf[MaxBuf];
	
	if(argc != 3) { 
        fprintf(stderr, "usage: %s sourceFile targetFile\n", argv[0]); 
        exit(0); 
    }
	fd_in = open(argv[1], O_RDONLY);
	if(fd_in < 0) { 
        fprintf(stderr, "open error: %s\n", argv[1]); 
        exit(1); 
    }
    //0600 means owner can read&write the file
	fd_out = open(argv[2], O_CREAT|O_WRONLY, 0600);	
	if(fd_out < 0) { 
        fprintf(stderr, "open error: %s\n", argv[2]); 
        exit(1); 
    }
    //fetch length
	offset = lseek(fd_in, (size_t)0, SEEK_END);
    //set back to begining
	lseek(fd_in, 0, SEEK_SET);
    
	read(fd_in, buf, offset);
	buf[offset] = '\0';
	write(fd_out, buf, offset);
	
	return 0;
}
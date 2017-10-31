#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

int main(){
  struct stat buf;
  if(stat("stat.c", &buf) == -1) {
    printf("Failed to fetch buf\n");
  }

  else{
    long bytes = buf.st_size;
    int gb; int mb; int kb; int b;
    b = bytes%1024;
    bytes = bytes/1024;
    kb = bytes%1024;
    bytes = bytes/1024;
    mb = bytes % 1024;
    bytes = bytes/1024;
    gb = bytes;
    
    printf("File size: %dGB %dMB %dKB %dB\n",gb, mb, kb, b);

    printf("File permissions: %o\n",buf.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO));//bitwise and to get rid of the first 3 numbers
    printf("Time last accessed: %s\n",ctime(&buf.st_atime)); 
  }
}

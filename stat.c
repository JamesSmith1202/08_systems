#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <time.h>

void print_an_oct(int das) {
  if (!das) {
    printf("---");
  }
  else if (das == 1) {
    printf("--x");
  }
  else if (das == 2) {
    printf("-w-");
  }
  else if (das == 3) {
    printf("-wx");
  }
  else if (das == 4) {
    printf("r--");
  }
  else if (das == 5) {
    printf("r-x");
  }
  else if (das == 6) {
    printf("rw-");
  }
  else if (das == 7) {
    printf("rwx");
  }
}

	   
void print_oct(int sad) {
  if (!sad) {
    return;
  }
  else {
    print_oct(sad/8);
    print_an_oct(sad%8);
  }
}
  

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
    unsigned int perms_filter = 511;
    unsigned int perm = buf.st_mode & perms_filter;
    printf("File permissions: %o\n",(perm));//bitwise and to get rid of the first 3 numbers
    printf("Time last accessed: %s\n",ctime(&buf.st_atime));

    print_oct(perm);
    printf("\n");
  }
}

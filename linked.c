#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char *argv[]){
    struct stat *fileStat1, *fileStat2;
    fileStat1 = malloc(sizeof(struct stat));
    fileStat2 = malloc(sizeof(struct stat));
    char buf[256];
    if(lstat(argv[1], fileStat1) < 0){
        perror(argv[1]);
        return 1;
    }
    if(lstat(argv[2], fileStat2) < 0){
        perror(argv[2]);
        return 1;
    }
    int isLnk1 = S_ISLNK(fileStat1->st_mode), isLnk2 = S_ISLNK(fileStat2->st_mode);
    if(isLnk1 && !isLnk2){
        readlink(argv[1], buf, 256);
        if(strcmp(buf, argv[2]) == 0){
            printf("%s is a symbolic link to %s\n", argv[1], argv[2]);
            return 0;
        }
    }
    else if(!isLnk1 && isLnk2){
        readlink(argv[2], buf, 256);
        if(strcmp(buf, argv[1]) == 0){
            printf("%s is a symbolic link to %s\n", argv[2], argv[1]);
            return 0;
        }
    }
    if(stat(argv[1], fileStat1) < 0 || stat(argv[2], fileStat2) < 0){
        perror("Error");
        return 1;
    }
    if(fileStat1->st_ino == fileStat2->st_ino){
        printf("These files are linked.\n");
    }
    else{
        printf("The files are not linked\n");
    }
    return 0;
}
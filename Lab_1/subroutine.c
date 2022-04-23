#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
/*delay driver*/
int main(int argc, char *argv[] ) {
    if(argc == 1) {
        printf("Usage: %s <delay>\n", argv[0]);
        exit(1);
    }
    for(int i = 1; i < atoi(argv[1]); i++){
        sleep(1);
        printf("\n %d", i);
    }
    return 0;
}
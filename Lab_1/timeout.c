#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Use the same delay function from subroutine.c
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    //set end of delay
    clock_t end = clock() + milli_seconds;
    
    // wait until end of delay 
    while (clock() < end);
}

int main(int argc, char *argv[] ) {
    if(argc != 3){
        printf("Format should be: ./timeout.exe seconds command");
    }else{
        printf("Perfect");
    }
    
    return 0;
}
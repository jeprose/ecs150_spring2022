#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<process.h>

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
    //catch inccorrect formatting or negative delays
    if(argc < 3 || argc > 6){
        printf("Format should be: ./timeout.exe seconds command");
        return 0;
    }
    int timeout = atoi(argv[1]);
    if( timeout < 0){
        printf("The delay should be positive.");
        return 0;
    }
    // save cmd/path of cmd to variable as well as sleep duration
    //testing with subroutine
    char path[] = "./subroutine.exe";
    int sleep = atoi(argv[1]);
    const char * argVec[] = {"p", "arg1", "arg2", "arg3", NULL};
    const char * envVec[] = {NULL};

    if(argc > 3){
        for(int i = 3; i < argc; i++){
            argVec[i-2] = argv[i];
        }
    }

    fork();
    if(execve(path, argVec, envVec) == -1){
       perror("uh oh what, somthing happened: ");
    }; 

    
    
    return 0;
}
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<signal.h>
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
    printf("%d\n", argc);
    if(argc < 3 || argc > 6){
        printf("Format should be: ./timeout.exe seconds command");
        return 0;
    }
    int timeout = atoi(argv[1]);
    if(timeout < 0){
        printf("The delay should be positive.");
        return 0;
    }
    char* path = argv[2];
    int sleepTime = atoi(argv[1]);
    char const *argVec[] = {"p", "arg1", "arg2", "arg3", NULL};
    const char * envVec[] = {NULL};

    if(argc >= 3){
        for(int i = 2; i < argc; i++){
            argVec[i-2] = argv[i];
            printf("%s\n",argVec[i-2]);
        }
    }

    pid_t process_id = fork();
    if(process_id == 0){
        if(execve(path, argVec, envVec) == -1){
            perror("uh oh what, somthing happened: ");
        };
    }
    else{
        sleep(sleepTime);
        kill(process_id, 9);
    }
    printf("Finished executing.\n");
    return 0;
}
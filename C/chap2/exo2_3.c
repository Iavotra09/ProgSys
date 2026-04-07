#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid_fils;
    for(int i=0; i<5; i++)
    {
        pid_fils=fork();
        if(pid_fils==0)     //break pour que chaque processus fils ne crée pas des sous-processus fils    //brek pour que chaque processus 
            break;
    }

    for(int i=0; i<5; i++)
        wait(NULL);
    if(pid_fils>0)
        printf("Je suis le père.\n");
    return 0;
}
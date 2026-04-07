#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    pid_t pid_fils;
    time_t debut, fin;
    debut=time(NULL);
    
    for(int i=0; i<2; i++)
    {
        pid_fils=fork();
        if(pid_fils==0)
        {
            srand(getpid());
            int sec=rand()%10+1;
            sleep(sec);
            exit(0);
        }
    }
    for(int i=0; i<2; i++)
        wait(NULL);

    fin=time(NULL);
    printf("Durée totale: %lds.\n", fin-debut);
    return 0;
}
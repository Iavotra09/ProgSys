#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int nombreFils=5;

int main()
{
    pid_t pid_fils;
    for(int i=0; i<nombreFils; i++)
    {
        pid_fils=fork();
        if(pid_fils==0)
        {
            printf("Je suis le fils %d.\n", i+1);
            break;      //pour que le processus fils ne crée pas un sous-processus fils
        }
        if(pid_fils>0)      //les processus fils sont créé successivement et respecte l'ordre
            waitpid(pid_fils, NULL, 0);
    }

    if(pid_fils>0)
        printf("Je suis le père.\n");
    return 0;
}
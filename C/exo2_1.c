#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t pid_fils=fork();
    if(pid_fils==0)
        printf("Je suis le fils.\n");
    else if(pid_fils>0)
    {
        wait(NULL);
        printf("Je suis le père.\n");
    }
    else
        perror("Erreur lors de la création du processus fils.\n");

    return 0;
}
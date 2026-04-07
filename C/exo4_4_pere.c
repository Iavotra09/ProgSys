#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

int main()
{
    int tube[2];
    if(pipe(tube)!=0)
    {
        printf("Erreur lors de la création du tube.\n");
        exit(1);
    }
    
    pid_t pid_fils=fork();
    if (pid_fils==0)
    {
        char fd[50];
        sprintf(fd, "%d", tube[0]);
        setenv("DESCRIPT", fd, 1);
        execl("./programme4_fils", "programme4_fils", NULL);//il faut aussi compiler le programme fils pour avoir l'exécutable "programme_fils"
    }
    else
    {
        close(tube[0]);
        char *message="Message bien reçu par le fils.";
        write(tube[1], message, strlen(message)+1);
        wait(NULL);
    }
    return 0;
}
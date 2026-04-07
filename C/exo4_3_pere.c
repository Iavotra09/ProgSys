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
        char fd[10];
        sprintf(fd, "%d", tube[0]);  //metre le descripteur en string
        execl("./programme3_fils", "programme3_fils", fd, NULL);//il faut compiler le programme fils pour avoir l'exécutable "programme_fils"
    }
    else
    {
        close(tube[0]);
        char *message="Message bien reçu par le fils.";
        write(tube[1], message, strlen(message)+1);  //+1 pour \0 à la fin de la chaine
        wait(NULL);
    }
    return 0;
}
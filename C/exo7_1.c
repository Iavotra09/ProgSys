#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
    pid_t fils;
    char choix;
    
    fils=fork();
    if(fils==-1)
    {
        printf("erreur lors de la création du processus fils.\n");
        exit(0);
    }  
    if(fils==0)
        while(1); //boucle infinie
    else
    {
        do
        {
            printf("s=endormir, r=reveiller et q=tuer : ");
            scanf(" %c", &choix);
            
            if(choix=='s')
                kill(fils, SIGSTOP);
            if(choix=='r')
                kill(fils, SIGCONT);
            if(choix=='q') 
            {
                kill(fils, SIGTERM);
                wait(NULL);
                return 0;
            }
        } while(1);
    }
}
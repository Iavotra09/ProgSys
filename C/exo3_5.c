#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char fileName[200];
    while(1)
    {
        printf("Nom du fichier texte / Entrée \"q\" pour quitter: ");
        scanf("%s", fileName);
        if(strcmp(fileName, "q")==0)   //q pour quitter
            exit(0); 
        else
        {
            if(access(fileName, F_OK)!=0)  //si le fichier n'existe pas
                printf("Le fichier n'existe pas.\n");
            else
            {
                pid_t pid=fork();   //créer un processus fils pour chaque fichier dans emacs pour que le programme continue de tourner 
                if(pid==0)      //le processus fils
                {
                    char *argv[]={"emacs", fileName, NULL};
                    execv("/usr/bin/emacs", argv);
                }
            }
        }
    }
    return 0;
}
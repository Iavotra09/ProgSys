#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 256
int main()
{
    pid_t pid_fils;
    int tube1[2], tube2[2];
    char mot1[256], mot2[256], mot[256];
    bool trouve=0, retour=0;

    if(pipe(tube1)!=0 || pipe(tube2)!=0)
    {
        printf("Erreur lors de la création du tube.\n");
        exit(1);
    }

    pid_fils=fork();
    if(pid_fils==-1)
    {
        printf("Erreur lors de la création du processus.\n");
        exit(1);
    }
    if(pid_fils==0)
    {
        close(tube1[0]);
        close(tube2[1]);
        printf("Mot: ");
        scanf("%s", mot1);
        write(tube1[1], mot1, SIZE);

        read(tube2[0], &retour, sizeof(bool));
        if(retour)
            printf("Le mot est trouvé.\n");
        else
            printf("Le mot n'est pas trouvé.\n"); 
    }
    else
    {
        close(tube1[1]);
        close(tube2[0]);
        read(tube1[0], mot2, SIZE);

        FILE *fp=fopen("fichier.txt", "r");
        if(!fp)
        {
            printf("Erreur lors de l'ouverture du fichier.\n");
            exit(1);
        }
        while(fscanf(fp, "%s", mot)!=EOF)
        {
            if(strcmp(mot, mot2)==0)
            {
                trouve=1;
                break;
            }
        }
        fclose(fp);
        write(tube2[1], &trouve, sizeof(bool));
        wait(NULL);
    }
    return 0;
}
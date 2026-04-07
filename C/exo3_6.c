#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
    int n, k, a, b, total=0;
    if(argc!=3)     //si la personne n'a pas entré deux arguments
    {
        printf("Erreur! Deux nombres requises!");
        exit(1);
    }

    n=atoi(argv[1]);
    k=atoi(argv[2]);
    if(k==0 || k==n)   //cas de base
    {
        printf("1");
        exit(0);
    }
    
    char f1[]="/tmp/f1.txt";
    char f2[]="/tmp/f2.txt";*/
    
    pid_t pid1=fork();
    if(pid1==0)
    {
        char commande[500];
        sprintf(commande, "%s %d %d > %s", argv[0], n-1, k, f1);
        execl("/bin/sh", "bash", "-c", commande, NULL);
        exit(0);
    }

    pid_t pid2=fork();
    if(pid2==0)
    {
        char commande[500];
        sprintf(commande, "%s %d %d > %s", argv[0], n-1, k-1, f2);
        execl("/bin/sh", "bash", "-c", commande, NULL);
        exit(0);
    }

    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);

    FILE *fp1=fopen(f1, "w");
    FILE *fp2=fopen(f2, "w");
    if(!fp1 || !fp2)
    {
        printf("erreur sur la créations des fichiers temporaires.");
        exit(1);
    }
    fscanf(fp1, "%d", &a);
    fscanf(fp2, "%d", &b);
    fclose(fp1);
    fclose(fp2);
    remove(f1);
    remove(f2);
    printf("Réponse: %d", a+b);
    return 0;
}
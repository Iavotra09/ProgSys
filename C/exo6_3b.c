#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int *tableau;
    int fd;
    int taille, nbElements;
    char nom[100];
    
    printf("Nom du fichier à charger: ");
    scanf("%s", nom);
    
    fd=open(nom, O_RDONLY);
    if(fd==-1)
    {
        printf("Erreur: impossible d'ouvrir %s\n", nom);
        exit(1);
    }
    
    taille=lseek(fd, 0, SEEK_END);      //aller à la fin pour savoir la taille --> calculer le nb d'elts --> revenir au début
    nbElements=taille / sizeof(int);
    lseek(fd, 0, SEEK_SET);
    
    tableau = malloc(taille);
    read(fd, tableau, taille);
    close(fd);
    printf("\n%d entiers:\n", nbElements);
    for(int i=0; i<nbElements; i++)
        printf("%d ", tableau[i]);
    printf("\n");
    free(tableau);
    
    return 0;
}
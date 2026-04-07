#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int tableau[100];
    int n, i;
    int fd;
    
    printf("Nombre d'entiers: ");
    scanf("%d", &n);    
    for(i=0; i<n; i++)
    {
        printf("Nombre %d: ", i+1);
        scanf("%d", &tableau[i]);
    }

    fd=open("fichierBin", O_CREAT | O_WRONLY | O_TRUNC, 0664); //permission
    if(fd==-1)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        exit(1);
    }
    
    write(fd, tableau, n * sizeof(int));
    close(fd);    
    printf("Sauvegarde terminée dans fichierBin\n");   
    return 0;
}
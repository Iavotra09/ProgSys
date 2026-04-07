#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char fileName[200];
    printf("Nom du fichier texte: ");
    scanf("%s", fileName);
    
    if(access(fileName, F_OK)!=0)  //si le fichier n'exsite pas
    {
        printf("Le fichier n'existe pas.\n");
        exit(1);
    }
    char *argv[]={"emacs", fileName, NULL};
    execv("/usr/bin/emacs", argv);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Chemin du répertoire requis(1 argument).\n");
        exit(1);
    }
    char commande[1000];  //mettre la commande à executer avec system dans une variable avec le chemin
    sprintf(commande, "cp -r . %s", argv[1]);
    system(commande);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char argv[250];   
    while(1)
    {
        printf("Nom du répertoire / Entrée \"q\" pour quitter: ");
        scanf("%s", argv);
        if(strcmp(argv, "q")==0)   //q pour quitter
            exit(0); 
        else
        {
            char commande[1000];  //mettre la commande à executer avec system dans une variable avec le chemin
            sprintf(commande, "cp -r . %s", argv);
            system(commande);
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int a, b;
    if(argc!=3)     //si la personne n'a pas entré deux arguments
    {
        printf("Erreur! Deux nombres requises!");
        exit(1);
    }
    a=atoi(argv[1]);
    b=atoi(argv[2]);
    printf("Somme: %d\n", a+b);
    return 0;
}
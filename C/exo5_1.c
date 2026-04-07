#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *tab;
    int taille;
}tableau;

void *afficheTableau(void *arg)
{
    tableau *a=(tableau *)arg;
    for(int i=0; i<a->taille; i++)
        printf("%d  ", a->tab[i]);
    printf("\n");
    return NULL;
}

int main()
{
    pthread_t th;
    tableau A;
    int temp[]={21, 20, 36, 5, 11};

    A.tab=temp;
    A.taille=5;
    pthread_create(&th, NULL, afficheTableau, &A);
    pthread_join(th, NULL);
    return 0;
}
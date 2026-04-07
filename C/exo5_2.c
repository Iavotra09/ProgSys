#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>

void *creerTableau(void *arg)
{
    int taille=*(int *)arg;
    int *tab=malloc(taille*sizeof(int));

    for(int i=0; i<taille; i++)
        tab[i]=rand()%100;
    return tab;
}

int main()
{
    pthread_t th;
    int *tableau;
    srand(time(NULL));
    int taille=rand()%10+1;

    pthread_create(&th, NULL, creerTableau, &taille);
    pthread_join(th, (void **)&tableau);
    for(int i=0; i<taille; i++)
        printf("%d  ", tableau[i]);

    printf("\n");
    free(tableau);
    return 0;
}
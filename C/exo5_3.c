#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct
{
    int *tab;
    int nbElements;
    int x;
}TypeTableau;

void *creerTableau(void *arg)
{
    TypeTableau *a=(TypeTableau *)arg;
    a->tab=malloc(a->nbElements*sizeof(int));

    for(int i=0; i<a->nbElements; i++)
        a->tab[i]=rand()%100;
    return NULL;
}

void *chercheX(void *arg)
{
    TypeTableau *a=(TypeTableau *)arg;
    for(int i=0; i<a->nbElements; i++)
    {
        if(a->tab[i]==a->x)
            return (void *)1;
    }
    return (void *)0;
}

int main()
{
    pthread_t th1, th2;
    TypeTableau A;
    int resultat;
    srand(time(NULL));
    A.nbElements=rand()%10+1;

    pthread_create(&th1, NULL, creerTableau, &A);
    printf("Nombre à chercher: ");
    scanf("%d", &A.x);
    pthread_join(th1, NULL);

    for(int i=0; i<A.nbElements; i++)
        printf("%d  ", A.tab[i]);
    printf("\n");
    pthread_create(&th2, NULL, chercheX, &A);
    pthread_join(th2, (void **)&resultat);
    free(A.tab);
    return 0;
}
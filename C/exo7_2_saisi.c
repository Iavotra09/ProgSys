#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int main()
{
    int pid, nombre;
    FILE *f;
    
    printf("PID du programme affiche : ");
    scanf("%d", &pid);   
    printf("Entier a saisir : ");
    scanf("%d", &nombre);
    
    f = fopen("/tmp/entier.txt", "w");
    fprintf(f, "%d", nombre);
    fclose(f);    
    kill(pid, SIGUSR1);
    return 0;
}
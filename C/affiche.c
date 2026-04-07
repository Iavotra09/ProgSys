#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int main()
{
    int nombre;
    FILE *f;
    
    printf("Mon PID est : %d\n", getpid());
    printf("En attente d'un signal...\n");   
    pause();  // il va attendr un signal
    
    f=fopen("/tmp/entier.txt", "r");
    fscanf(f, "%d", &nombre);
    fclose(f);   
    printf("Entier recu : %d\n", nombre);
    return 0;
}
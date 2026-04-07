#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    int fd_fils=atoi(argv[1]); //remettre le descripteur en nombre
    char message_fils[500];
    
    read(fd_fils, message_fils, sizeof(message_fils));
    printf("Nouveau message du fils: %s\n", message_fils);
    close(fd_fils);
    return 0;
}
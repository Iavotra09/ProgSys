#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>

#define TAILLE_MIN 1000000

int main(int argc, char **argv)
{
    DIR *dir;
    struct dirent *ent;
    struct stat st;
    char chemin[512];
    
    for(int i=1; i<argc; i++)
    {
        printf("\n--- Répertoire: %s ---\n", argv[i]);        
        dir = opendir(argv[i]);
        if (dir == NULL)
        {
            printf("Impossible d'ouvrir %s\n", argv[i]);
            continue;
        }
        
        while((ent=readdir(dir))!=NULL)
        {
            sprintf(chemin, "%s/%s", argv[i], ent->d_name); //le chemin complet
            if (stat(chemin, &st) == 0)
            {
                if (S_ISREG(st.st_mode) && st.st_size >= TAILLE_MIN)
                    printf("%s (taille: %ld octets, UID: %d)\n", ent->d_name, st.st_size, st.st_uid);
            }
        }       
        closedir(dir);
    }   
    return 0;
}
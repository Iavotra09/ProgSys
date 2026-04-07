import sys
import os
import stat

TAILLE_MIN = 1000000

for i in range(1, len(sys.argv)) :
        print(f"\n--- Répertoire: {sys.argv[i]} ---")
        try :
            dir = os.opendir(sys.argv[i])
        except :
                print(f"Impossible d'ouvrir {sys.argv[i]}")
                continue
        for ent in os.listdir(sys.argv[i]) :
                chemin = f"{sys.argv[i]}/{ent}" 
                try :
                    st = os.stat(chemin)
                except :
                    continue
                if stat.S_ISREG(st.st_mode) and st.st_size >= TAILLE_MIN :
                    print(f"{ent} (taille: {st.st_size} octets, UID: {st.st_uid})")
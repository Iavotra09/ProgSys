import sys
import os

if len(sys.argv) != 2 :
        print("Chemin du répertoire requis(1 argument).")
        sys.exit(1)

commande = f"cp -r . {sys.argv[1]}"
os.system(commande)
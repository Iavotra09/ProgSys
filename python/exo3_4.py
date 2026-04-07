import os
import sys

while True :
        argv = input("Nom du répertoire / Entrée \"q\" pour quitter: ")
        if argv == "q" :
            sys.exit(0)
        else :
                commande = f"cp -r . {argv}" 
                os.system(commande)
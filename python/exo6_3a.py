import sys
import struct

n = int(input("Nombre d'entiers: "))
tableau = []
for i in range(n) :
        tableau.append(int(input(f"Nombre {i+1}: ")))

try :
    fd = open("fichierBin", "wb")  #permission
except :
        print("Erreur lors de l'ouverture du fichier.")
        sys.exit(1)

fd.write(struct.pack(f"{n}i", *tableau))
fd.close()
print("Sauvegarde terminée dans fichierBin")
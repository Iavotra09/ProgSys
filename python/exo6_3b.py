import sys
import struct

nom = input("Nom du fichier à charger: ")

try :
    fd = open(nom, "rb")
except :
        print(f"Erreur: impossible d'ouvrir {nom}")
        sys.exit(1)

fd.seek(0, 2)       #aller à la fin pour savoir la taille --> calculer le nb d'elts --> revenir au début
taille = fd.tell()
nbElements = taille // struct.calcsize("i")
fd.seek(0, 0)

tableau = struct.unpack(f"{nbElements}i", fd.read(taille))
fd.close()

print(f"\n{nbElements} entiers:")
for i in range(nbElements) :
    print(tableau[i], end=" ")
print()
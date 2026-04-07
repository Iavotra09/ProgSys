import sys

if len(sys.argv) != 3 :     #si la personne n'a pas entré deux arguments
        print("Erreur! Deux nombres requises!")
        sys.exit(1)

a = int(sys.argv[1])
b = int(sys.argv[2])
print(f"Somme: {a+b}")
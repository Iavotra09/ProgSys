import threading
import random

def creerTableau(taille) :
        tab = [random.randint(0, 99) for i in range(taille)]
        return tab

taille = random.randint(1, 10)
resultat = [None]

def wrapper() :
        resultat[0] = creerTableau(taille)

th = threading.Thread(target=wrapper)
th.start()
th.join()

tableau = resultat[0]
for i in range(taille) :
    print(tableau[i], end="  ")
print()
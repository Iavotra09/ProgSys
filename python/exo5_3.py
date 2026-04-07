import threading
import random

class TypeTableau :
    def __init__(self) :
        self.tab = []
        self.nbElements = 0
        self.x = 0

def creerTableau(a) :
        a.tab = [random.randint(0, 99) for i in range(a.nbElements)]

def chercheX(a) :
        for i in range(a.nbElements) :
            if a.tab[i] == a.x :
                resultat[0] = 1
                return
        resultat[0] = 0

A = TypeTableau()
resultat = [None]

A.nbElements = random.randint(1, 10)
th1 = threading.Thread(target=creerTableau, args=(A,))
th1.start()
A.x = int(input("Nombre à chercher: "))
th1.join()

for i in range(A.nbElements) :
    print(A.tab[i], end="  ")
print()

th2 = threading.Thread(target=chercheX, args=(A,))
th2.start()
th2.join()

if resultat[0] :
    print(f"{A.x} est trouvé.")
else :
    print(f"{A.x} n'est pas trouvé.")
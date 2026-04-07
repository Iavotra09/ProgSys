import threading

class tableau :
    def __init__(self, tab, taille) :
        self.tab = tab
        self.taille = taille

def afficheTableau(arg) :
        a = arg
        for i in range(a.taille) :
            print(a.tab[i], end="  ")
        print()

A = tableau([21, 20, 36, 5, 11], 5)

th = threading.Thread(target=afficheTableau, args=(A,))
th.start()
th.join()
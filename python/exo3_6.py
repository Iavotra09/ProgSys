import os
import sys

total = 0

if len(sys.argv) != 3 :
        print("Erreur! Deux nombres requises!")
        sys.exit(1)

n = int(sys.argv[1])
k = int(sys.argv[2])

if k == 0 or k == n :   # LES cas de base
        print("1")
        sys.exit(0)

f1 = "/tmp/f1.txt"
f2 = "/tmp/f2.txt"

pid1 = os.fork()
if pid1 == 0 :
        commande = f"{sys.argv[0]} {n-1} {k} > {f1}"
        os.execl("/bin/sh", "bash", "-c", commande)
        os._exit(0)

pid2 = os.fork()
if pid2 == 0 :
        commande = f"{sys.argv[0]} {n-1} {k-1} > {f2}"
        os.execl("/bin/sh", "bash", "-c", commande)
        os._exit(0)

os.waitpid(pid1, 0)
os.waitpid(pid2, 0)

fp1 = open(f1, "r")
fp2 = open(f2, "r")

if not fp1 or not fp2 :
        print("erreur sur la créations des fichiers temporaires.")
        sys.exit(1)

a = int(fp1.read())
b = int(fp2.read())
fp1.close()
fp2.close()
os.remove(f1)
os.remove(f2)
print(f"Réponse: {a+b}")
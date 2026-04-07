import os
import sys
import signal

pid = int(input("PID du programme affiche : "))
nombre = int(input("Entier a saisir : "))

f = open("/tmp/entier.txt", "w")
f.write(str(nombre))
f.close()
os.kill(pid, signal.SIGUSR1)
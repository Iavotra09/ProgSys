import os
import signal

print(f"Mon PID est : {os.getpid()}")
print("En attente d'un signal...")
signal.pause()  # il va attendre un signal

f = open("/tmp/entier.txt", "r")
nombre = int(f.read())
f.close()
print(f"Entier recu : {nombre}")
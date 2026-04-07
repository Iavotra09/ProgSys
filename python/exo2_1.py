import os
import sys

pid = os.fork()

if pid == 0:
    print("Je suis le fils.")
    sys.exit(0)
elif pid > 0:
    os.wait()
    print("Je suis le père.")
else:
    print("Erreur lors de la création du processus fils.", file=sys.stderr)
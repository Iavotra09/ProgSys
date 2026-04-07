import os
import sys
import signal

fils = os.fork()

if fils == -1 :
        print("erreur lors de la création du processus fils.")
        sys.exit(0)

if fils == 0 :
    while True : pass   #boucle infinie
else :
        while True :
                choix = input("s=endormir, r=reveiller et q=tuer : ")
                if choix == 's' :
                    os.kill(fils, signal.SIGSTOP)
                if choix == 'r' :
                    os.kill(fils, signal.SIGCONT)
                if choix == 'q' :
                        os.kill(fils, signal.SIGTERM)
                        os.wait()
                        sys.exit(0)
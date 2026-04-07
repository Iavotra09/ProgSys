import os
import sys

while True :
        fileName = input("Nom du fichier texte / Entrée \"q\" pour quitter: ")
        if fileName == "q" :
            sys.exit(0)
        else :
                if not os.access(fileName, os.F_OK) :
                    print("Le fichier n'existe pas.")
                else :
                        pid = os.fork()
                        if pid == 0 :
                                argv = ["emacs", fileName]
                                os.execv("/usr/bin/emacs", argv)
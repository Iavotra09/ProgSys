import os
import sys

fileName = input("Nom du fichier texte: ")

if not os.access(fileName, os.F_OK) :
        print("Le fichier n'existe pas.")
        sys.exit(1)

argv = ["emacs", fileName]
os.execv("/usr/bin/emacs", argv)
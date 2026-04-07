import os
import sys

tube_r, tube_w = os.pipe()

if tube_r is None :
        print("Erreur lors de la création du tube.")
        sys.exit(1)

pid_fils = os.fork()

if pid_fils == 0 :
        fd = str(tube_r)    #metre le descripteur en string
        os.execl("./programme3_fils.py", "programme3_fils.py", fd)  #il faut avoir le programme fils "programme3_fils.py"
else :
        os.close(tube_r)
        message = "Message bien reçu par le fils."
        os.write(tube_w, (message + "\0").encode())     #+1 pour \0 à la fin de la chaine
        os.wait()
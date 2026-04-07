import os
import sys

tube_r, tube_w = os.pipe()

if tube_r is None :
        print("Erreur lors de la création du tube.")
        sys.exit(1)

pid_fils = os.fork()

if pid_fils == 0 :
        fd = str(tube_r)
        os.environ["DESCRIPT"] = fd
        os.execl("./programme4_fils.py", "programme4_fils.py")  #il faut aussi avoir le programme fils "programme4_fils.py"
else :
        os.close(tube_r)
        message = "Message bien reçu par le fils."
        os.write(tube_w, (message + "\0").encode())
        os.wait()
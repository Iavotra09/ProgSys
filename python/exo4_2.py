import os
import sys

tube1_r, tube1_w = os.pipe()
tube2_r, tube2_w = os.pipe()

if tube1_r is None or tube2_r is None :
        print("Erreur lors de la création du tube.")
        sys.exit(1)

pid_fils = os.fork()

if pid_fils == -1 :
        print("Erreur lors de la création du processus.")
        sys.exit(1)

if pid_fils == 0 :
        os.close(tube1_r)
        os.close(tube2_w)
        sys.stdout.write("Mot: ")
        sys.stdout.flush()
        mot1 = input()
        os.dup2(tube1_w, sys.stdout.fileno())
        os.dup2(tube2_r, sys.stdin.fileno())
        sys.stdout.write(mot1 + "\n")
        sys.stdout.flush()
        retour = int(input())
        if retour :
            sys.stderr.write("Le mot est trouvé.\n")
        else :
            sys.stderr.write("Le mot n'est pas trouvé.\n")
else :
        os.close(tube1_w)
        os.close(tube2_r)
        os.dup2(tube1_r, sys.stdin.fileno())
        os.dup2(tube2_w, sys.stdout.fileno())
        mot2 = input()
        trouve = 0
        fp = open("fichier.txt", "r")
        if not fp :
                sys.stdout.write("Erreur lors de l'ouverture du fichier.\n")
                sys.exit(1)
        for mot in fp.read().split() :
                if mot == mot2 :
                        trouve = 1
                        break
        fp.close()
        sys.stdout.write(str(trouve) + "\n")
        sys.stdout.flush()
        os.wait()
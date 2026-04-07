import os
import sys
import struct

SIZE = 256

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
        mot1 = input("Mot: ")
        os.write(tube1_w, mot1.encode().ljust(SIZE))
        retour = struct.unpack("?", os.read(tube2_r, 1))[0]
        if retour :
            print("Le mot est trouvé.")
        else :
            print("Le mot n'est pas trouvé.")
else :
        os.close(tube1_w)
        os.close(tube2_r)
        mot2 = os.read(tube1_r, SIZE).decode().strip()
        trouve = False
        fp = open("fichier.txt", "r")
        if not fp :
                print("Erreur lors de l'ouverture du fichier.")
                sys.exit(1)
        for mot in fp.read().split() :
                if mot == mot2 :
                        trouve = True
                        break
        fp.close()
        os.write(tube2_w, struct.pack("?", trouve))
        os.wait()
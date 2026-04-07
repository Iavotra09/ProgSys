import os
import sys

var = os.environ.get("DESCRIPT")    #prendre le descripteur qui est un variable d'environnement
fd_fils = int(var)  #remettre le descripteur en nombre
message_fils = os.read(fd_fils, 500)
print(f"Nouveau message du fils: {message_fils.decode()}")
os.close(fd_fils)
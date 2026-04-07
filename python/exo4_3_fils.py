import os
import sys

fd_fils = int(sys.argv[1])  #descripteur --> nombre
message_fils = os.read(fd_fils, 500)
print(f"Nouveau message du fils: {message_fils.decode()}")
os.close(fd_fils)
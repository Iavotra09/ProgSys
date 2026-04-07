import os

nombreFils = 5

pid_fils = None
for i in range(nombreFils) :
    pid_fils = os.fork()
    if pid_fils == 0 :
            print(f"Je suis le fils {i+1}.")
            break
    if pid_fils > 0 :      
        os.waitpid(pid_fils, 0)
if pid_fils > 0 :
    print("Je suis le père.")
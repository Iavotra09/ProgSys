import os

pid_fils = None
for i in range(5) :
    pid_fils = os.fork()
    if pid_fils == 0 :
        break

for i in range(5) :
    os.wait()
if pid_fils > 0 :
    print("Je suis le père.")
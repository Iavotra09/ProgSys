import os
import time
import random

debut = time.time()

pid_fils = None
for i in range(2) :
    pid_fils = os.fork()
    if pid_fils == 0 :
            random.seed(os.getpid())
            sec = random.randint(1, 10)
            time.sleep(sec)
            os._exit(0)

for i in range(2) :
    os.wait()

fin = time.time()
print(f"Durée totale: {int(fin-debut)}s.")
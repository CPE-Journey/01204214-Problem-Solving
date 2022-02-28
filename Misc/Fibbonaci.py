from time import time
memory = [0,1,1]

def normalFib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return normalFib(n-1)+normalFib(n-2)

def dynamicFib(n):
    if n < len(memory):
        return memory[n]
    if n == 1 or n == 2:
        return 1
    else:
        res = dynamicFib(n-1) + dynamicFib(n-2)
        memory.append(res)
        return res

for i in range(5):
    start = time()
    print(dynamicFib(35))
    print(time()-start)
# print(dynamicFib(35))


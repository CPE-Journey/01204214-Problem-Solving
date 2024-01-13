[N,M] = [int(i) for i in input().split()]
family = [0 for i in range(N+1)]

for i in range(N):
    family[i+1] = int(input())

for i in range(M):
    [a,b] = [int(i) for i in input().split()]
    family[a] = b
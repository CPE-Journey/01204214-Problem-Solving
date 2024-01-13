n = int(input())

nextOrder = []
current = [[i for i in range(n)],[0 for i in range(n)]]
returned = [False for i in range(n)]
returnCount = 0
round = 0

for i in range(n):
    nextOrder.append(int(input())-1)

while returnCount < n:
    for i in range(n):
        current[(round+1)%2][nextOrder[i]] = current[round%2][i]
        if i == current[(round+1)%2][i] and not returned[i]:
            returned[i] = True
            returnCount += 1
    round += 1

print(round)
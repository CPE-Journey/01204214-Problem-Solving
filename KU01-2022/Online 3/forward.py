[N,S] = [int(i) for i in input().split()]

students = []
visited = [False for i in range(N)]

for i in range(N):
    students.append(int(input())-1)

current = S - 1
count = 0

while True:
    if visited[current]:
        break
    elif students[current] == -1:
        count += 1
        break
    else:
        count += 1
        visited[current] = True
        current = students[current]

print(count)

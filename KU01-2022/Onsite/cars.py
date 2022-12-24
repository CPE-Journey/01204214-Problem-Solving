N = int(input())
cars = []
answer = 0

for i in range(N):
    cars.append([int(i) for i in input().split()]) # [Price, Score]
    
cars.sort(key=lambda x: x[1],reverse=True)

min_price = cars[0][0]

for car in cars:
    if min_price >= car[0]:
        min_price = car[0]
    else:
        answer += 1

print(answer)
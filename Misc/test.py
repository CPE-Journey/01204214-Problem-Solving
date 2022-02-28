# white_on_green = '\033[37;42m'
# white_on_yellow = '\033[34;43m'
# normal = '\033[0;0m'

# ch1 = '1'
# ch2 = white_on_green + '2' + normal
# ch3 = white_on_yellow + '3' + normal
# ch4 = '4'
# ch5 = white_on_yellow + '5' + normal
# print(ch1 + ch2 + ch3 + ch4 + ch5)

def leftShift(arr):
    first = arr[0]
    for i in range(len(arr)-1):
        arr[i] = arr[i+1]
    arr[len(arr)-1] = first

current = [0,0,1,0,1]

leftShift(current)
print(current)
leftShift(current)
print(current)
leftShift(current)
print(current)
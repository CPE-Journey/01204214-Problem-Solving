# from this import d


# def generate(seating_sequence1,seating_sequence2,p_row):
#     seating_sequence = []
#     diff = p_row*2

#     while(len(seating_sequence1) < diff):
#         seating_sequence1.append('-')
    
#     while(len(seating_sequence2) < diff):
#         seating_sequence2.append('-')

#     for i in range(diff):
#         seating_sequence.append(seating_sequence1[i])
#         seating_sequence.append(seating_sequence2[i])

# def reverseOrder(seating_sequence):
#     reverse_seating_sequence = seating_sequence

# generate(4)

# def printRoom(seating_sequence):
#     width = (len(seating_sequence)//4)
#     print("-"*(3*width+1))
#     print(f"|{' '*((3*width-10)//2)}Exam Room{' '*((3*width-10)//2)}|")
#     print("-"*(3*width+1))
    
#     count = 0
#     for j in range(4):
#         print("|",end="")
#         for i in range(width):
#             print(f"{seating_sequence[count]}|",end="")
#             count += 1
#         print(f"\n{'-'*(3*width+1)}")

# printRoom(['A1', 'B1', 'A2', 'B2', 'A3', 'B3', 'A4', 'B4', 'A5', ' -', 'A6', ' -', ' -', ' -', ' -', ' -'])


# ages = [3, 10, 18, 20]

# for i in ages:
#     print(i)

# {id: 1,name: 'A'}

# x = 5

# try: # if
#     print(1)
#     print(x)
#     print(2)
# except: # else if
#     print("Error")
# else:
#     print("No Error")
# finally:
#     print("Always Execute")

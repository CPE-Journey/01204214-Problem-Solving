from dataclasses import dataclass


with open('./Week 05 - Graph Traversal & Greedy Algorithm/Testcase/twoteams_input-5.txt','r') as f:
    data = [i for i in f.readlines()]
    format_string = ""
    # print(data)
    
    for line in data:
        select = line.split()
        format_string += '{'+select[0]+','+select[1]+'},\n'

    with open('./Week 05 - Graph Traversal & Greedy Algorithm/Testcase/format_twoteams_input-5.txt','w') as g:
        g.write(format_string)
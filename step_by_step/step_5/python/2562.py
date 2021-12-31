# 최댓값

input_list = []
for x in range(0, 9):
    input_list.append(int(input()))
# print(input_list)
max = max(input_list)
print(max)
for x in input_list:
    if x == max:
        print(input_list.index(max)+1)    # index는 0부터 시작
# 나머지

input_list = []
for x in range(0,10):
    input_remainder = int(input()) % 42
    input_list.append(input_remainder)
# print(input_list)
input_set = set(input_list) # set는 unordered, unindexed, 중복된 item이 불가능하다
# print(set(input_list))
print(len(input_set))
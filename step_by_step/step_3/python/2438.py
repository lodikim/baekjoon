# 별 찍기 - 1

N = int(input())

for x in range(N): # x는 0 ~ N-1
    for y in range(x+1): # y는 0 ~ x
        print("*", end = "") # default로 되어 있는 end = "\n"를 바꿔줌
    print("") # 줄바꿈을 위해
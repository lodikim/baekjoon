# 별 찍기 - 2

N = int(input())

for x in range(N): # x는 0 ~ N-1
    # 공백의 개수는 N - (x+1), 별의 개수는 x+1
    for space in range(N-(x+1)):
        print(" ", end="")
    for star in range(x+1):
        print("*", end="")
    print("") # 줄바꿈을 위해
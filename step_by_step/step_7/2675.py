# 문자열 반복

T = int(input())

for cases in range(0, T):
    R, S = input().split()
    for element in S:
        for times in range(0, int(R)):
            print(element, end="")
    print()
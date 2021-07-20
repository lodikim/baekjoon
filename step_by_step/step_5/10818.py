# 최소, 최대

N = int(input())    # 파이썬은 필요가 없음
input_list = list(map(int, input().split()))
min = min(input_list)
max = max(input_list)
print("{} {}".format(min, max))
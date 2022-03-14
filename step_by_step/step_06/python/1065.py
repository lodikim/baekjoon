# 한수

# 1. 한수를 판별하는 함수
def hansu(x: int) -> bool:
    digits = list(map(int, list(str(x))))
    if len(digits) == 1:
        return True
    digit_diff = [] # 자릿수들의 차
    for i in range(0, len(digits)):
        if i==0:
            continue
        digit_diff.append(digits[i] - digits[i-1])
    if len(set(digit_diff)) == 1:
        return True
    else:
        return False

# 2. 1~N 까지의 수 중, 한수의 개수를 구한다.
N = int(input())
count = 0
for num in range(1, N+1):
    if hansu(num):  # 한수이면 True
        count = count + 1
    else:
        continue
print(count)
# 숫자의 개수

A = int(input())
B = int(input())
C = int(input())

product = A*B*C
digits = list(str(product))
# print(digits) : 예제의 경우, ['1', '7', '0', '3', '7', '3', '0', '0']
for x in range(0,10): # x 는 0~9
    print(digits.count(str(x))) # digits는 list[str]이므로 str(x)를 count
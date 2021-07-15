# X보다 작은 수

N, X = map(int, input().split())
A = input().split() # A는 map: A[0]이 첫 숫자, A[1]이 두 번째 숫자...
# 이 시점에서, A[0], A[1], ... 등등은 int가 아니라, str이다.

for x in range(N):
    if X > int(A[x]): # str인 A[x]를 int로 변환하여 비교
        print(A[x], end=" ")
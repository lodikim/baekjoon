# A+B - 8

T = int(input())

for x in range(T):
    A, B = map(int, input().split())
    print("Case #" + str(x+1) + ": " + str(A) + " + " + str(B) + " = " + str(A+B))
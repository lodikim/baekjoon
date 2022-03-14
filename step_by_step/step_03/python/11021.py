# A+B - 7

T = int(input())

for x in range(T):
    A, B = map(int, input().split())
    print("Case #" + str(x+1) + ": " + str(A+B))
    
# print("Case #", x+1, ":", A+B) => 불필요한 공백
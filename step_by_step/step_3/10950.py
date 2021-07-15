# A+B - 3

T = int(input())

for x in range(T):
    A, B = map(int, input().split())
    print(A+B)

# 입력과 출력 스트림은 별개이므로,
# 테스트케이스를 전부 입력받아서 저장한 뒤 전부 출력할 필요는 없다
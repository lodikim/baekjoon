# A+B - 4

# EOF(End of File)일 때 while문 종료
while True:
    try:
        A, B = map(int, input().split())
        print(A+B)
    except:
        break
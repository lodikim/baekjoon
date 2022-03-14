# 더하기 사이클

N = int(input()) # 0 <= N <= 99

first_N = N # 처음 N의 값
cycle = 0
while True:
    # 십의 자리: N//10, 일의 자리: N%10
    digit_sum = N//10 + N%10
    digit_1 = N%10  # 주어진 수의 가장 오른쪽 자리 수
    digit_2 = digit_sum%10  # 합의 가장 오른쪽 자리 수
    N = digit_1*10 + digit_2    # N을 새로운 수로 바꾸기
    cycle = cycle + 1
    # print("Cycle: " + str(cycle) + ", Number: " + str(N))

    if N == first_N:
        print(cycle)
        break
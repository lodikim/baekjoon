# 다이얼

dial = ["", "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"]
# 앞에 빈 문자열을 넣음으로써, index가 곧 걸리는 시간이 되도록 함

input_str = list(input())

needed_time = 0
for letter in input_str:    # 입력 단어의 처음부터, 각 대문자 검사
    for numbers in dial:    # dial 속, 어느 번호에 해당되는지 검사
        if letter in numbers:
            needed_time = needed_time + dial.index(numbers) # index가 걸리는 시간
print(needed_time)
# 크로아티아 알파벳

croatia_alphabet = ["c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="]

input_str = input()
count = 0   # 알파벳 개수
str_count = 0   # input_str 중, 크로아티아 알파벳 표현에 쓰인 문자 개수
# 1. 입력 문자열 중 croatia_alphabet에 있는 알파벳들 count
for cr_letter in croatia_alphabet:
    num_letter = input_str.count(cr_letter)
    count = count + num_letter
    if cr_letter == "dz=":  # 3글자이고, 나중 z= 에서 중복으로 세는 것 때문에 예외 처리
        count = count - num_letter
        str_count = str_count + 3*num_letter - 2*num_letter
    else:
        str_count = str_count + 2*num_letter

# 2. 남은 알파벳들 count
count = count + (len(input_str) - str_count)
print(count)

# 처음에는 알파벳 확인 후 삭제하는 방법을 시도했으나, "nljj" 경우로 오류
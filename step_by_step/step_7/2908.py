# 상수

reverse_numbers = input()[::-1]
# slice 이용 : [::-1] 은 [시작(문자열의 끝이면 생략):끝(문자열의 시작이면 생략):간격(-1씩 이동)]
left, right = reverse_numbers.split()
print(max(int(left), int(right)))
# 단어 공부
from collections import Counter

input_word = input()
alphabet_count = Counter(input_word.upper()).most_common()
# most_common : 많은 횟수 순으로 [('문자', 횟수), ... ] 형태
if len(alphabet_count) == 1:
    print(alphabet_count[0][0])
else:
    if alphabet_count[0][1] != alphabet_count[1][1]:
        print(alphabet_count[0][0])
    else:
        print("?")
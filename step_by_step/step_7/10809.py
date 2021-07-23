# 알파벳 찾기
import string

list_S = list(input())
for alphabet in string.ascii_lowercase:
    if alphabet in list_S:
        print(str(list_S.index(alphabet)), end="")
    else:
        print(str(-1), end="")
    
    if alphabet != "z":
        print(end=" ")
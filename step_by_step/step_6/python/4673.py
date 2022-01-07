# 셀프 넘버

# 1. n을 입력했을 때, d(n)을 구하는 함수를 작성한다.
def find_dn(n: int) -> int:
    dn = n
    while n>0:  # n이 0이 되면 빠져나옴
        dn = dn + n%10
        n = n//10
    return dn

# 2. 1부터 10000까지 진행하며, d(n)들의 리스트 list_dn을 만든다.
list_dn = []
for x in range(1, 10001):
    list_dn.append(find_dn(x))

# 3. 중복된 d(n)들을 없애준다.
# print(len(list_dn)) : 10000
list_dn = list(set(list_dn))
# print(len(list_dn)) : 9045

# 4. 1부터 10000까지의 수들 중, list_dn에 포함되지 않는 수들의 리스트를 만든다.
self_num = list(set(range(1, 10001)) - set(list_dn))
for self_number in sorted(self_num):
    print(self_number)
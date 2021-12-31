# 평균

N = int(input())
scores = list(map(int, input().split()))
M = max(scores)
# map을 이용해 list 내의 각 item에 함수(lambda) 적용
new_scores = list(map(lambda x: (x/M)*100, scores))
# print(new_scores)
print(sum(new_scores) / len(new_scores))
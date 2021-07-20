# 평균은 넘겠지

C = int(input())
for x in range(0, C):
    input_list = list(map(int, input().split()))
    N = input_list[0]
    input_list.remove(N) # N이 빠진 새로운 input_list
    average = sum(input_list) / len(input_list)
    num_over_avg = sum(score>average for score in input_list)
    # list(score>average for score in input_list)를 하면 True, False로 이루어진 list
    # True가 1, False가 0이므로, sum()은 곧 score<average인 item의 개수를 의미함
    print("%.3f" % round((num_over_avg/N)*100, 3) + "%")
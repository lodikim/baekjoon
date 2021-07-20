# OX퀴즈

N = int(input())
for x in range(0, N):
    input_OX = list(input())
    score = []
    for answer in range(0, len(input_OX)):
        if input_OX[answer]=='O':
            # 'O'일 경우, 앞의 것을 확인
            if (answer==0) | (input_OX[answer-1]=='X'):
                score.append(1)
            else:   # input_OX[answer-1]=='O'
                score.append(score[answer-1]+1)
        else:
            # input_OX[answer] == 'X'일 경우, score에 변화가 없음
            score.append(0)
    # print(score)
    print(sum(score))
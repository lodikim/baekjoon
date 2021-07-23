# 그룹 단어 체커

N = int(input())
count = 0
for x in range(0, N):
    word_list = list(input())
    continuous_letters = 0    # 연속되는 문자들
    for i in range(0, len(word_list)):
        if (i!=0) & (word_list[i]==word_list[i-1]):
            continuous_letters = continuous_letters + 1
    diff_words_cont = len(word_list) - continuous_letters
    diff_words_all = len(set(word_list))
    if diff_words_cont == diff_words_all:   # 이것이 True면, 그룹 단어
        count = count+1
print(count)
#include <stdio.h>
#include <string.h>

void merge_sort(char (*arr)[51], int index, int len);
void merge(char (*arr)[51], int l_index, int r_index, int l_len, int r_len);
int compare(char (*a)[51], char (*b)[51]);

int main(void){
    int N;
    scanf("%d", &N);

    char words[N][51];  //단어 저장
    for(int i=0; i<N; i++){
        scanf("%s", &words[i]);
    }

    merge_sort(words, 0, N);
    for(int i=0; i<N; i++){
        if(i>0 && !strcmp(words[i], words[i-1]))  //같으면 0 반환
            continue;
        printf("%s\n", words[i]);
    }
}

void merge_sort(char (*arr)[51], int index, int len){
    // Base Case
    if(len==1){
        return;
    }

    // Recursive Case
    // 1. arr을 반으로 나눈다
    int left = index;
    int right = index + len/2;
    int left_len = len/2;
    int right_len = len - len/2;

    // 2. 왼쪽, 오른쪽을 각각 merge_sort 한다
    merge_sort(arr, left, left_len);
    merge_sort(arr, right, right_len);

    // 3. 왼쪽, 오른쪽을 merge 한다
    merge(arr, left, right, left_len, right_len);
}

void merge(char (*arr)[51], int l_index, int r_index, int l_len, int r_len){
    //printf("merge: %d %d\n", l_index, r_index);
    // 1. 임시 배열 선언
    char temp[l_len+r_len][51];
    int count = 0;
    
    // 2. 왼쪽, 오른쪽의 가장 작은 수 비교
    int l_count = 0;
    int r_count = 0;
    while(1){
        int left = l_index + l_count;
        int right = r_index + r_count;
        if(compare(&arr[left], &arr[right])){ //arr[left] < arr[right]이면 1
            strcpy(temp[count], arr[left]);
            count++;
            l_count++;
        }
        else{
            strcpy(temp[count], arr[right]);
            count++;
            r_count++;
        }

    // 3. 왼쪽이나 오른쪽의 끝에 도달하면 break
        if(l_count==l_len || r_count==r_len){
            break;
        }
    }

    // 4. 남은 요소 temp로 복사
    if(l_count==l_len){ // 오른쪽을 복사
        while(count<l_len+r_len){
            strcpy(temp[count], arr[r_index+r_count]);
            count++;
            r_count++;
        }
    }
    else{               // 왼쪽을 복사
        while(count<l_len+r_len){
            strcpy(temp[count], arr[l_index+l_count]);
            count++;
            l_count++;
        }
    }

    // 5. arr에 임시배열 복사
    for(int i=l_index; i<l_index+l_len+r_len; i++){
        strcpy(arr[i], temp[i-l_index]);
    }
}

int compare(char (*a)[51], char (*b)[51]){  //a<b이면 1 반환
    int a_len = strlen(*a);
    int b_len = strlen(*b);
    if(a_len<b_len){
        return 1;
    }
    else if(a_len==b_len){  //사전 순으로 정렬
        for(int i=0; i<a_len; i++){
            if((*a)[i]<(*b)[i])
                return 1;
            else if((*a)[i]>(*b)[i])
                return 0;
        }
    }
    return 0;
}
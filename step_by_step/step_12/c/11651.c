#include <stdio.h>

void merge_sort(int (*arr)[2], int index, int len);
void merge(int (*arr)[2], int l_index, int r_index, int l_len, int r_len);
int compare(int (*a)[2], int (*b)[2]);

int main(void){
    int N;
    scanf("%d", &N);

    int coordinates[N][2];
    for(int i=0; i<N; i++){
        scanf("%d %d", &coordinates[i][0], &coordinates[i][1]);
    }
    
    //Merge Sort
    merge_sort(coordinates, 0, N);

    //출력
    for(int i=0; i<N; i++){
        printf("%d %d\n", coordinates[i][0], coordinates[i][1]);
    }
}

void merge_sort(int (*arr)[2], int index, int len){
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

void merge(int (*arr)[2], int l_index, int r_index, int l_len, int r_len){
    //printf("merge: %d %d\n", l_index, r_index);
    // 1. 임시 배열 선언
    int temp[l_len+r_len][2];
    int count = 0;
    
    // 2. 왼쪽, 오른쪽의 가장 작은 수 비교
    int l_count = 0;
    int r_count = 0;
    while(1){
        int left = l_index + l_count;
        int right = r_index + r_count;
        if(compare(&arr[left], &arr[right])){ //arr[left] < arr[right]이면 1
            temp[count][0] = arr[left][0];
            temp[count][1] = arr[left][1];
            count++;
            l_count++;
        }
        else{
            temp[count][0] = arr[right][0];
            temp[count][1] = arr[right][1];
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
            temp[count][0] = arr[r_index+r_count][0];
            temp[count][1] = arr[r_index+r_count][1];
            count++;
            r_count++;
        }
    }
    else{               // 왼쪽을 복사
        while(count<l_len+r_len){
            temp[count][0] = arr[l_index+l_count][0];
            temp[count][1] = arr[l_index+l_count][1];
            count++;
            l_count++;
        }
    }

    // 5. arr에 임시배열 복사
    for(int i=l_index; i<l_index+l_len+r_len; i++){
        arr[i][0] = temp[i-l_index][0];
        arr[i][1] = temp[i-l_index][1];
    }
}

int compare(int (*a)[2], int (*b)[2]){  //a<b이면 1 반환
    if((*a)[1]<(*b)[1]){
        return 1;
    }
    else if((*a)[1]==(*b)[1]){
        if((*a)[0]<(*b)[0]){
            return 1;
        }
    }
    return 0;
}
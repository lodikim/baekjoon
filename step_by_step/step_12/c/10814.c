#include <stdio.h>
#include <string.h>

void merge_sort(int *arr, char (*name)[101], int index, int len);
void merge(int *arr, char (*name)[101], int l_index, int r_index, int l_len, int r_len);

int main(void){
    int N;
    scanf("%d", &N);

    int age[N];
    char name[N][101];

    for(int i=0; i<N; i++){
        scanf("%d %s", &age[i], name[i]);

    }
    merge_sort(age, name, 0, N);

    for(int i=0; i<N; i++){
        printf("%d %s\n", age[i], name[i]);
    }
}

void merge_sort(int *arr, char (*name)[101], int index, int len){
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
    merge_sort(arr, name, left, left_len);
    merge_sort(arr, name, right, right_len);

    // 3. 왼쪽, 오른쪽을 merge 한다
    merge(arr, name, left, right, left_len, right_len);
}

void merge(int *arr, char (*name)[101], int l_index, int r_index, int l_len, int r_len){
    // 1. 임시 배열 선언
    int temp[l_len+r_len];
    char temp_name[l_len+r_len][101];
    int count = 0;
    
    // 2. 왼쪽, 오른쪽의 가장 작은 수 비교
    int l_count = 0;
    int r_count = 0;
    while(1){
        int left = l_index + l_count;
        int right = r_index + r_count;
        //arr[left] <= arr[right] 사용 -> stable sort
        if(arr[left] <= arr[right]){
            temp[count] = arr[left];
            strcpy(temp_name[count], name[left]);
            count++;
            l_count++;
        }
        else{
            temp[count] = arr[right];
            strcpy(temp_name[count], name[right]);
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
            temp[count] = arr[r_index+r_count];
            strcpy(temp_name[count], name[r_index+r_count]);
            count++;
            r_count++;
        }
    }
    else{               // 왼쪽을 복사
        while(count<l_len+r_len){
            temp[count] = arr[l_index+l_count];
            strcpy(temp_name[count], name[l_index+l_count]);
            count++;
            l_count++;
        }
    }

    // 5. arr에 임시배열 복사
    for(int i=l_index; i<l_index+l_len+r_len; i++){
        arr[i] = temp[i-l_index];
        strcpy(name[i], temp_name[i-l_index]);
    }
}
#include <stdio.h>

void merge_sort(int *arr, int index, int len);
void merge(int *arr, int l_index, int r_index, int l_len, int r_len);
int binary_search(int * arr, int element, int start, int end);

int main(void){
    int N;
    scanf("%d", &N);

    int num[N];
    int num_sort[N];    //정렬시킬 num 배열

    for(int i=0; i<N; i++){
        scanf("%d", &num[i]);
        num_sort[i] = num[i];
    }
    
    merge_sort(num_sort, 0, N); 
    //num: 정렬 전 배열, num_sort: 정렬 후 배열
    //num_order: num_sort 내에서 중복 제거한 배열
    int num_order[N];
    int count=0;
    for(int i=0; i<N; i++){
        if(i>0 && num_sort[i]!=num_sort[i-1])
            count++;
        num_order[count] = num_sort[i];
    }

    for(int i=0; i<N; i++){ //시간 복잡도: O(n)*O(logn)=O(nlogn)
        int idx = binary_search(num_order, num[i], 0, count);    //시간 복잡도: O(logn)
        printf("%d ", idx);
    }
}

void merge_sort(int *arr, int index, int len){
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

void merge(int *arr, int l_index, int r_index, int l_len, int r_len){
    // 1. 임시 배열 선언
    int temp[l_len+r_len];
    int count = 0;
    
    // 2. 왼쪽, 오른쪽의 가장 작은 수 비교
    int l_count = 0;
    int r_count = 0;
    while(1){
        int left = l_index + l_count;
        int right = r_index + r_count;

        if(arr[left] <= arr[right]){
            temp[count] = arr[left];
            count++;
            l_count++;
        }
        else{
            temp[count] = arr[right];
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
            count++;
            r_count++;
        }
    }
    else{               // 왼쪽을 복사
        while(count<l_len+r_len){
            temp[count] = arr[l_index+l_count];
            count++;
            l_count++;
        }
    }

    // 5. arr에 임시배열 복사
    for(int i=l_index; i<l_index+l_len+r_len; i++){
        arr[i] = temp[i-l_index];
    }
}

int binary_search(int * arr, int element, int start, int end){  //arr에서 element의 인덱스 반환
    int mid = (start+end)/2;
    if(arr[mid]==element)
        return mid;
    else if(arr[mid]<element)
        return binary_search(arr, element, mid+1, end);
    else
        return binary_search(arr, element, start, mid-1);
}
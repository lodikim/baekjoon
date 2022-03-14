#include <stdio.h>

int main(void){
    int N;
    scanf("%d\n", &N);

    for(int i=0; i<N; i++){
        int students;
        scanf("%d\n", &students);
        int scores[students];

        int sum = 0;
        for(int j=0; j<students; j++){
            scanf("%d", &scores[j]);
            sum = sum+scores[j];
        }
        float average = (double) sum/students;
        //printf("%f\n", average);

        int counter = 0;
        for(int k=0; k<students; k++){
            if(scores[k]>average){
                counter++;
            }
        }
        printf("%.3f%%\n", ((double) counter/students)*100); // '%'출력을 위해 '%%'
    }
}
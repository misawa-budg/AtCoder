#include <stdio.h>
#include <stdlib.h>

int compare_desc(const void *a, const void *b){
    int int_a = *((int*)a);
    int int_b = *((int*)b);
    if(int_a < int_b) return 1;
    else if(int_a > int_b) return -1;
    else return 0;
}

int main(){
    int N;
    if(scanf("%d", &N)!=1){
        printf("-1\n");
        return 0;
    }
    if(N < 0){
        printf("-1\n");
        return 0;
    }

    int *A = (int *)malloc(N * sizeof(int));
    if(A == NULL){
        printf("-1\n");
        return 0;
    }
    for(int i=0;i<N;i++){
        if(scanf("%d", &A[i])!=1){
            printf("-1\n");
            free(A);
            return 0;
        }
    }

    int M = N-1;
    if(M <0){
        if(N == 0){
            printf("0\n");
        }
        else{
            int max = A[0];
            for(int i=1;i<N;i++) {
                if(A[i] > max) max = A[i];
            }
            printf("%d\n", max);
        }
        free(A);
        return 0;
    }

    int *B = (int*)malloc(M * sizeof(int));
    if(B == NULL){
        printf("-1\n");
        free(A);
        return 0;
    }
    for(int i=0;i<M;i++){
        if(scanf("%d", &B[i])!=1){
            printf("-1\n");
            free(A);
            free(B);
            return 0;
        }
    }

    qsort(A, N, sizeof(int), compare_desc);
    qsort(B, M, sizeof(int), compare_desc);

    int box_ptr = 0;
    int needBoxSize = 0;
    int possible = 1;

    for(int i=0;i<N;i++){
        if(box_ptr < M && B[box_ptr] >= A[i]){
            box_ptr++;
        }
        else{
            if(needBoxSize == 0){
                needBoxSize = A[i];
            }
            else{
                possible = 0;
                break;
            }
        }
    }

    if(possible){
        if(needBoxSize > 0){
            printf("%d\n", needBoxSize);
        }
        else{
            printf("0\n");
        }
    }
    else{
        printf("-1\n");
    }

    free(A);
    free(B);
    return 0;
}

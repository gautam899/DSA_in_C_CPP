// #include<stdio.h>
// #include<stdlib.h>

// int **merge(int (*interval)[2],int n){
//     // Sort the interval.
//     for(int i=0;i<n-1;i++){
//         for(int j=0;j<2;j++){
//             if(*(*(interval+i)+j) > *(*(interval+i+1)+j)){
//                 int temp = *(*(interval+i)+j);
//                 *(*(interval+i)+j) = *(*(interval+i+1)+j);
//                 *(*(interval+i+1)+j) = temp;
//             }
//         }
//     }
//     int **ans = (int **)malloc(n * sizeof(int *)); // Allocate a array of pointer.
//     for(int i=0;i<n;i++){
//         *(ans+i) = (int *)malloc(2 * sizeof(int));
//     }

// }
// int main(){
//     int interval[][2] = {{1,3},{2,6},{8,10},{15,18}};
//     int **ans = merge(interval,4);
//     int n = sizeof(ans)/sizeof(ans[0]);
//     for(int i=0;i<n;i++){
//         printf("%d %d\n",*(*(ans+i)+0), *(*(ans+i)+1));
//     }
// }

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int end;
} Interval;

// Comparator.
int compareIntervals(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return intervalA->start - intervalB->start;
}

Interval* mergeIntervals(Interval* intervals, int intervalsSize, int* returnSize) {
    if (intervalsSize == 0) {
        *returnSize = 0;
        return NULL;
    }
    // Quick sort. Sort the array based on the comparision function.
    qsort(intervals, intervalsSize, sizeof(Interval), compareIntervals);

    Interval* ans = (Interval*)malloc(intervalsSize * sizeof(Interval));
    int ansIndex = 0;

    ans[0] = intervals[0];
    ansIndex = 1;

    for (int i = 1; i < intervalsSize; i++) {
        if (ans[ansIndex - 1].end < intervals[i].start) {
            ans[ansIndex++] = intervals[i];
        } else {
            if (ans[ansIndex - 1].end < intervals[i].end) {
                ans[ansIndex - 1].end = intervals[i].end;
            }
        }
    }

    *returnSize = ansIndex;
    return ans;
}

int main() {
    Interval intervals[] = {
        {1, 3},
        {2, 6},
        {8, 10},
        {15, 18}
    };
    int intervalsSize = sizeof(intervals) / sizeof(intervals[0]);
    int mergedSize = 0;

    Interval* merged = mergeIntervals(intervals, intervalsSize, &mergedSize);

    for (int i = 0; i < mergedSize; i++) {
        printf("%d %d\n", merged[i].start, merged[i].end);
    }

    free(merged);
    return 0;
}
#include<stdlib.h>
#include<stdio.h>

int* find_missing_duplicate(int *arr, int n) {
    // 1. Find xor of all elements of array and elements from 1->n
    //
    int xor_all = 0;
    for(int i=0;i<n;i++) {
    	xor_all^=*(arr+i);
	xor_all^=(i+1);
    }
    // printf("xor_all: %d\n",xor_all);
    // 2. Find the right most set bit
    //
    int right_most_bit = xor_all & ~(xor_all - 1);
    // printf("right_most_bit: %d\n", right_most_bit);
    // 3. Divide elements in two groups. One with set and the other with unset
    //
    int x=0;
    int y=0;
    for(int i=0;i<n;i++) {
    	if(right_most_bit & *(arr+i)){
	    x^=*(arr+i);
	}else {
	    y^=*(arr+i);
	}

	if( (i+1) & right_most_bit){
	    x^=(i+1);
	}else {
	    y^=(i+1);
	}
    }
    // printf("x: %d\n",x);
    // printf("y: %d\n",y);
    int xcnt=0;
    for(int i=0;i<n;i++){
        if(*(arr+i) == x) {
	    xcnt++;
	}
    }
    int *ans = (int*)malloc(2*sizeof(int));

    if(xcnt == 0){
    	*(ans+0) = y;
	*(ans+1) = x;
    }else {
    	*(ans+0) = x;
        *(ans+1) = y;
    }
    return ans;
}

int main() {
    int arr[] = {1,3,3};
    int n = 3;
    int *ans = find_missing_duplicate(arr, n);
    printf("The duplicate and missing numbers are %d and %d\n", *(ans+0), *(ans+1));
    return 0;
}

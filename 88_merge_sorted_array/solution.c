#include<stdio.h>
#include<stdlib.h>

void merge_sorted_array(int *arr1, int m, int *arr2, int n){
    int i,j,k;
    i=m-1;j=n-1;k=m+n-1;
    while(i>=0 && j>=0) {
    	if(*(arr1+i) > *(arr2+j)) {
	    *(arr1+k--) = *(arr1+i--);
	} else {
	    *(arr1+k--) = *(arr2+j--);
	}
    }
    while(i>=0) {
    	*(arr1+k--) = *(arr1+i--);
    }
    while(j>=0){
    	*(arr1+k--) = *(arr2+j--);
    }
}
int main(){
    int arr1[] = {1,2,3,0,0,0};
    int arr2[] = {2,5,6};
    merge_sorted_array(arr1,3,arr2,3);

    for(int i=0;i<6;i++){
    	printf("%d ", *(arr1 + i));
    }
    return 0;
}

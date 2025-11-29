#include<stdio.h>
#include<stdlib.h>

void rotate_image(int (*matrix)[3], int rows, int cols){
    // Find the transpose
    for(int r=0;r<rows;r++){
        for(int c=0;c<r;c++){
            int temp = *(*(matrix+r) + c);
            *(*(matrix+r) + c) = *(*(matrix+c) + r);
            *(*(matrix+c) + r) = temp;
        }
    }

    // Reverse each row.
    for(int r=0;r<rows;r++){
        for(int i=0,j=cols-1;i<j;i++,j--){
            int temp = *(*(matrix+r)+i);
            *(*(matrix+r)+i) = *(*(matrix+r)+j);
            *(*(matrix+j)+j) = temp;
        }
    }
}
int main(){
    // Declare a 2d vector
    int matrix[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    rotate_image(matrix,3,3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            printf("%d ",*(*(matrix+i)+j));
        }
    }
    return 0;
}
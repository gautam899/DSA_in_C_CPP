#include<stdlib.h>
#include<stdio.h>

int **generate(int numRows, int **returnColumnSizes)
{
    // Allocate space for a 1D array of pointers.
    int **res = (int **)malloc(numRows * sizeof(int *));
    // Allocate space for storing the sizes of each row
    *returnColumnSizes = (int *)malloc(numRows * sizeof(int));

    for (int i = 0; i < numRows; i++)
    {
        int col = i + 1;
        // Update the column size array.
        *(*returnColumnSizes + i) = i + 1;
        // Allocate space for each row.
        *(res + i) = (int *)malloc(col * sizeof(int));
        // or
        // res[i] = (int*)malloc(col * sizeof(int));

        // The value of first and last column in the row is 1.
        *(*(res + i) + 0) = 1;
        *(*(res + i) + col - 1) = 1;
        // or
        // res[i][0] = res[i][col - 1] = 1;

        for (int j = 1; j < col - 1; j++)
        {
            *(*(res + i) + j) =
                *(*(res + i - 1) + j - 1) + *(*(res + i - 1) + j);
            // or
            // res[i][j] = res[i - 1][j - 1] + res[i - 1][j];
        }
    }
    return res;
}

int main()
{
    int numRows;
    printf("Enter the number of rows: \n");
    scanf("%d", &numRows);
    int *returnColumnSizes;
    int **res = generate(numRows, &returnColumnSizes);
    // Print the pascal triangle
    printf("Result:\n");
    for(int i=0;i<numRows;i++){
        for(int j=0;j<*(returnColumnSizes+i);j++){
            printf("%d ",*(*(res+i)+j));
            // or
            // printf("%d",res[i][j]);
        }
        printf("\n");
    }
}

/* 
Enter the number of rows:
4
Result:
1
1 1
1 2 1
1 3 3 1
*/
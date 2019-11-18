//
//  118 杨辉三角.cpp
//  leetcode
//
//  Created by slx on 2019/11/13.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int** generate(int numRows, int* returnSize, int** returnColumnSizes);

int main(){
    
    int a, returnSize;
    int * returnColumnSizes;
    int ** b;
    
    scanf("%d", &a);
    b = generate(a, &returnSize, &returnColumnSizes);
//    printf("\nbbb\n");
    
    for(int i=0; i<a; i++){
        for(int j=0; j<=i; j++){
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}


/**
* Return an array of arrays of size *returnSize.
* The sizes of the arrays are returned as *returnColumnSizes array.
* Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
*/
int** generate1(int numRows, int* returnSize, int** returnColumnSizes){
    int ** a, i, j;
    
    *returnSize = numRows;
    * returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    a = (int **)malloc(sizeof(int *) * numRows);
    
    for(i=0; i<numRows; i++){
        (*returnColumnSizes)[i] = i+1;
        a[i] = (int *)malloc(sizeof(int) * (i+1));
        
        a[i][0] = 1;
        a[i][i] = 1;
        for(j=1; j<=i/2; j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
            a[i][i-j] = a[i][j];
        }
    }
    
    return a;
}


int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int ** a, i, j;
    
    *returnSize = **returnColumnSizes = numRows;
//    * returnColumnSizes = (int *)malloc(sizeof(int) * numRows);
    a = (int **)malloc(sizeof(int *) * numRows);
    
    for(i=0; i<numRows; i++){
//        (*returnColumnSizes)[i] = i+1;
        a[i] = (int *)malloc(sizeof(int) * (i+1));
        
        a[i][0] = 1;
        a[i][i] = 1;
        for(j=1; j<=i/2; j++){
            a[i][j] = a[i-1][j-1] + a[i-1][j];
            a[i][i-j] = a[i][j];
        }
    }
    
    return a;
}

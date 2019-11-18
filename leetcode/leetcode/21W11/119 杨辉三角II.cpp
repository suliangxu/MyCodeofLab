//
//  119 杨辉三角II.cpp
//  leetcode
//
//  Created by slx on 2019/11/16.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize);

int main(){
    
    int a, *p, b;
    scanf("%d", &a);
    
    p = getRow(a, &b);
    
    for(int i=0; i<b; i++){
        printf("%d ", p[i]);
    }
    
    return 0;
}

int* getRow(int rowIndex, int* returnSize){
    int *p = (int *)malloc(sizeof(int) * (rowIndex+1));
    *returnSize = rowIndex + 1;
    
//    for(int i = 0;i <= rowIndex;i++)
//        for(int j = i;j >= 0;j--)
//        {
//            if(j == 0 || j == i)
//                p[j] = 1;
//            else
//                p[j] = p[j] + p[j-1];
//        }
    
    for(int i=0; i<=rowIndex; i++)
        p[i] = 1;
    
    for(int i=1; i<rowIndex; i++){
        for(int j=i; j>0; j--)
            p[j] += p[j-1];
    }
    
    return p;
}

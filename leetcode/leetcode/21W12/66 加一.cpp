//
//  66 加一.cpp
//  leetcode
//
//  Created by slx on 2019/11/22.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define M 2

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main(){
    
    int a[M] = {9,9};
    int *p, b;
    
    p = plusOne(a, M, &b);
    
    for(int i=0; i<b; i++){
        printf("%d", p[i]);
    }
    printf("\n");
    
    return 0;
}


int* plusOne(int* digits, int digitsSize, int* returnSize){
    int flag = 0;
    digits[digitsSize-1] += 1;
    
    for(int i=digitsSize-1; i>=0; i--){
        if(digits[i] > 9){
            if(i != 0){
                digits[i-1] += 1;
                digits[i] %= 10;
            }
            else{
                digits[i] %= 10;
                flag = 1;
            }
        }
    }
    
    if(flag == 0){
        *returnSize = digitsSize;
        
        return digits;
    }
    else{
        int *p = (int *)malloc(sizeof(int) * (digitsSize+1));
        *returnSize = digitsSize + 1;
        
        p[0] = 1;
        for(int i=1; i<*returnSize; i++){
            p[i] = digits[i-1];
        }
        
        return p;
    }
}

//
//  946 验证栈序列.cpp
//  leetcode
//
//  Created by slx on 2019/11/24.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <math.h>

#define M (pow(2, 31)-1)

bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize);

int main(){
    
    int a[] = {0,2,1};
    int b[] = {0,1,2};
    
    int *pushed = a, *popped = b;
    int poppedSize = 3, pushedSize = 3;
    
    printf("%d\n", validateStackSequences(pushed, pushedSize, popped, poppedSize));
    
    return 0;
}



bool validateStackSequences1(int* pushed, int pushedSize, int* popped, int poppedSize){
    int p = 0;
    int i, flag;
    
    if(poppedSize == 1)
        return true;
    
    for(i=0; i<poppedSize; i++){
        while(pushed[p] != popped[i]){
            p++;
            if(p>=pushedSize)
                return false;
        }
        
        flag = 0;
        for(int j=p; j<pushedSize-1; j++){
            flag = 1;
            pushed[j] = pushed[j+1];
        }
        if(flag == 1)
            pushedSize--;
        
        if(p>0)
            p--;
    }
    
    return true;
}



bool validateStackSequences(int* pushed, int pushedSize, int* popped, int poppedSize){
    int p = 0;
    int i;
    
    if(poppedSize == 1)
        return true;
    
    for(i=0; i<poppedSize; i++){
        while(pushed[p] != popped[i]){
            p++;
            if(p>=pushedSize)
                return false;
        }
        
        pushed[p] = M;
     
        while(pushed[p] == M && p>0)
            p--;
    }
    
    return true;
}

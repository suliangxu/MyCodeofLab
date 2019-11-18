//
//  202 快乐数.cpp
//  leetcode
//
//  Created by slx on 2019/11/8.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>

typedef struct Value{
    int value[100];
    int length;
}Value;

bool isHappy(int );
bool inValue(Value , int );

int main(){
    
    int n;
    bool a;
    
    scanf("%d", &n);
    a = isHappy(n);
    
    printf("%d", a);
    
    return 0;
}


bool isHappy(int n){
    int k, t;
    Value v1, v2;
    v1.length = 0;
    
    do{
        v1.value[v1.length] = n;
        v1.length ++;
        v2.length = 0;
        
        k = n;
        while (k) {
            t = k%10;
//            printf("%d ", t);
            v2.value[v2.length] = t;
            k /= 10;
            v2.length ++;
        }
        
        n = 0;
        for(k=0; k<v2.length; k++)
            n += v2.value[k] * v2.value[k];
        
//        printf("%d\n", n);
        
        if(n == 1)
            return true;
        
    }while(!inValue(v1, n));
    
    return false;
}


bool inValue(Value v, int n){
    int i;
    
    for(i=0; i<v.length; i++){
        if(v.value[i] == n)
            return true;
    }
    
    return false;
}

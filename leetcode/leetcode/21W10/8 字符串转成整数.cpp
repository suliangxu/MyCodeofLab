//
//  8 字符串转成整数.cpp
//  leetcode
//
//  Created by slx on 2019/11/9.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <math.h>

typedef struct {
    int value[20];
    int length;
}Value;

int myAtoi(char *);
int isUseful(char );

int main(){
    
    char * s;
    int n;
    
    scanf("%s", s);

    n = myAtoi(s);
    printf("\n%d", n);
    
    return 0;
}


int myAtoi(char * str){
    Value v;
    v.length = 0;
    int i = 0, flag = 0, r;
    double t;
    
    while(str[i] == ' ')
        i++;
    
    if(str[i] == '-'){
        flag = -1;
        i++;
    }
        
    else if(str[i] == '+'){
        flag = 1;
        i++;
    }
        
    r = isUseful(str[i]);
    while(r != -1){
        if(r==0 && v.length==0){
            i++;
            r = isUseful(str[i]);
            continue;
        }
        
        v.value[v.length] = r;
        v.length ++;
        i++;
        
        if (v.length > 10){
            if(flag == -1)
                return (int)pow(-2, 31);
            else
                return (int)(pow(2, 31)-1);
        }
        
        if(str[i] == 0)
            break;
        r = isUseful(str[i]);
    }
    
    if(r == -1 && v.length==0)
        return 0;
    
    t = 0;
    for(i=0; i<v.length; i++)
        t += pow(10, v.length-i-1) * v.value[i];
    
    if(flag==-1)
        t = 0-t;
    
    if(t > pow(2, 31)-1)
        t = pow(2, 31) -1;
    
    if(t < pow(-2, 31))
        t = pow(-2, 31);
    
    return int(t);
}


int isUseful(char c){
    if (c>='0' && c<='9'){
            int a = (int)c - 48;
            return a;
        }
    
    else
        return -1;
}

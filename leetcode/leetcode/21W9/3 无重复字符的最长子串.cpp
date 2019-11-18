//
//  3 无重复字符的最长子串.cpp
//  leetcode
//
//  Created by slx on 2019/11/1.
//  Copyright © 2019 slx. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef struct{
    char elem[MAXSIZE];
    int front,rear;
}CSeQueue;

CSeQueue * InitSeQueue();   // 置空队
void InSeQueue(CSeQueue *q, char x); // 入队
void OutSeQueue(CSeQueue *q);  //出队
int EmptySeQueue(CSeQueue *q);  //判队空

int lengthOfLongestSubstring(char * s);

int main()
{
    int a;
    char * s;
    scanf("%s", s);
    
    a = lengthOfLongestSubstring(s);
    
    printf("%d", a);
    
    return 0;
}

int lengthOfLongestSubstring(char * s){
    int i=0, len=0, Mlen=0, flag,j,k;
    CSeQueue *q;
    
    q = InitSeQueue();
    
    while(s[i] != '\0'){
        flag = 0;

        //先判断队中是否有相同的字符
        if (EmptySeQueue(q)){
            InSeQueue(q, s[i]);
            len++;
            Mlen = Mlen>len?Mlen:len;
        }
        
        j = q->front;
        while(flag!=1 && j!=q->rear){  // flag==1表示找到一个相同的字符,j==rear表示走到队尾
            j = (j+1) % MAXSIZE;
            
            if(q->elem[j] == s[i])
                flag = 1;
        }
        
        if(flag == 1){
            k = q->front;
            while(k!=j){
                k = (k+1) % MAXSIZE;
                OutSeQueue(q);
                len--;
            }
        }
        
        InSeQueue(q, s[i]);
        len++;
        Mlen = Mlen>len?Mlen:len;
        
        i++;
    }
    
    return Mlen;
}

CSeQueue * InitSeQueue(){
    CSeQueue *q;
    q = (CSeQueue *)malloc(sizeof(CSeQueue));
    q->front = q->rear = MAXSIZE-1;
    return q;
}

void InSeQueue(CSeQueue *q, char x){
    q->rear = (q->rear+1) % MAXSIZE;
    q->elem[q->rear] = x;
}

void OutSeQueue(CSeQueue *q){
    q->front = (q->front+1) % MAXSIZE;
}

int EmptySeQueue(CSeQueue *q){
    if(q->front == q->rear)
        return 1;
    else
        return 0;
}

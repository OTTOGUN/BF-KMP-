#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXLEN 255      //串的最大长度

//注意：为了更好的说明问题：本章串下标为0的元素闲置！

//串的顺序存储结构：
typedef struct{
    char ch[MAXLEN + 1];    //存储串的一维数组
    int length;             //串的当前长度
}SString;

//串的堆式存储结构：
typedef struct{
    char* ch;           //若为非空串则分配内存
    int length;         //串的当前长度
}HString;

//串的链式存储结构：
#define CHUNKSIZE 80        //可由用户定义块的大小
typedef struct{
    char ch [CHUNKSIZE];
    struct Chunk* next;
}Chunk;

typedef struct{
    Chunk *head,*tail;  //串的头尾指针；
    int length;         //串的当前长度
}LString;

//BF算法
int Index_BF(SString S,SString T,int pos){
    int j = 1;
    int i = pos;
    while(i <= S.length && j <= T.length){
        if(S.ch[i] == T.ch[j]){
            i++;
            j++;
        }else{
            i = i - j + 2;
            j = 1;
        }
    }
    if(j >  T.length){
        return (i - T.length);
    }else{
        return ERROR;
    }
}

int KMP(char * S,char * T){
    int next[10];
    Next(T,next);//根据模式串T,初始化next数组
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) {
        //j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j>strlen(T)) {//如果条件为真，说明匹配成功
        return i-(int)strlen(T);
    }
    return -1;
}

int main() {
    int i=KMP("ababcabcacbab","abcac");
    printf("%d",i);
    return 0;
}
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

typedef int Status;
typedef struct Sstring{
    char ch[MAXLEN + 1];        //储存串的一维数组
    int length;             //串的长度
}Sstring;

int GetLength(char* L){
    char* p = L;        //不会改变原来串的格式
    int n = 0;          //计数器
    while((*p) != '\0'){    //只要不是‘\0’就不会停止
        n++;            //计数器 + 1
        p++;            //p的指针后移一位
    }
    return n;
}

Status InitString(Sstring* S){
    char a[MAXLEN];        //创造辅助函数
    printf("输入数据:\n");
    scanf("%s",a);  //扫描
    char* p = S -> ch;      //定义一个字符指针指向串里面的数组
    strcpy(++p,a);  //在数组下标为1的位置开始赋值(为了使用方便)
    S -> length = GetLength(p); //给长度赋值
}

int Index_BF(Sstring s1,char* s2,int pos,int s2_length){
    int i = pos;
    int j = 1;
    s2 += 1;
    while(i <= s1.length && j <=s2_length) {
        if (s1.ch[i] == *(s2)){
            i++;
            s2++;
            j++;
        } else {
            i = i - j + 2;
            j = 1;
        }
    }
    if(j > s2_length){
        return i - j + 1;
    }else{
        return 0;
    }
}

void Virus_Detection(Sstring person,Sstring virus){
    int flag = 0;
    int m = virus.length;
    char temp[virus.length + 1];

    for(int i = 1;i <= m;i++){
        virus.ch[m + i] = virus.ch[i];
    }
    virus.ch[2*m + 1] = '\0';

    for(int i = 0;i < m;i++){
        for(int j = 1;j <= m;j++){
            temp[j] = virus.ch[i + j];
        }
        temp[m + 1] = '\0';
        flag = Index_BF(person,temp,1,virus.length);
        if(flag)
            break;
    }
    if(flag)
        printf("已经感染病毒\n");
    else
        printf("没有感染病毒\n");
}

int main() {
    while(1){
        Sstring person;
        Sstring virus;

        printf("人类样本\n");
        InitString(&person);
        printf("病毒样本\n");
        InitString(&virus);

        Virus_Detection(person,virus);
    }
}



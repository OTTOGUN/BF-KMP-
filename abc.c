#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define MAXLEN 255      //������󳤶�

//ע�⣺Ϊ�˸��õ�˵�����⣺���´��±�Ϊ0��Ԫ�����ã�

//����˳��洢�ṹ��
typedef struct{
    char ch[MAXLEN + 1];    //�洢����һά����
    int length;             //���ĵ�ǰ����
}SString;

//���Ķ�ʽ�洢�ṹ��
typedef struct{
    char* ch;           //��Ϊ�ǿմ�������ڴ�
    int length;         //���ĵ�ǰ����
}HString;

//������ʽ�洢�ṹ��
#define CHUNKSIZE 80        //�����û������Ĵ�С
typedef struct{
    char ch [CHUNKSIZE];
    struct Chunk* next;
}Chunk;

typedef struct{
    Chunk *head,*tail;  //����ͷβָ�룻
    int length;         //���ĵ�ǰ����
}LString;

//BF�㷨
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
    Next(T,next);//����ģʽ��T,��ʼ��next����
    int i=1;
    int j=1;
    while (i<=strlen(S)&&j<=strlen(T)) {
        //j==0:����ģʽ���ĵ�һ���ַ��ͺ͵�ǰ���Ե��ַ�����ȣ�S[i-1]==T[j-1],�����Ӧλ���ַ���ȣ���������£�ָ��ǰ���Ե�����ָ���±�i��j�������
        if (j==0 || S[i-1]==T[j-1]) {
            i++;
            j++;
        }
        else{
            j=next[j];//������Ե������ַ�����ȣ�i������j��Ϊ��ǰ�����ַ�����nextֵ
        }
    }
    if (j>strlen(T)) {//�������Ϊ�棬˵��ƥ��ɹ�
        return i-(int)strlen(T);
    }
    return -1;
}

int main() {
    int i=KMP("ababcabcacbab","abcac");
    printf("%d",i);
    return 0;
}
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

typedef int Status;
typedef struct Sstring{
    char ch[MAXLEN + 1];        //���洮��һά����
    int length;             //���ĳ���
}Sstring;

int GetLength(char* L){
    char* p = L;        //����ı�ԭ�����ĸ�ʽ
    int n = 0;          //������
    while((*p) != '\0'){    //ֻҪ���ǡ�\0���Ͳ���ֹͣ
        n++;            //������ + 1
        p++;            //p��ָ�����һλ
    }
    return n;
}

Status InitString(Sstring* S){
    char a[MAXLEN];        //���츨������
    printf("��������:\n");
    scanf("%s",a);  //ɨ��
    char* p = S -> ch;      //����һ���ַ�ָ��ָ�����������
    strcpy(++p,a);  //�������±�Ϊ1��λ�ÿ�ʼ��ֵ(Ϊ��ʹ�÷���)
    S -> length = GetLength(p); //�����ȸ�ֵ
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
        printf("�Ѿ���Ⱦ����\n");
    else
        printf("û�и�Ⱦ����\n");
}

int main() {
    while(1){
        Sstring person;
        Sstring virus;

        printf("��������\n");
        InitString(&person);
        printf("��������\n");
        InitString(&virus);

        Virus_Detection(person,virus);
    }
}



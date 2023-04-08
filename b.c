#include<stdio.h>
#include <synchapi.h>
#include<string.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0

typedef int Status;
typedef struct BiTNode{
    char data;
    struct BiTNode *lchild , *rchild;
}BiTNode,*BiTree;

//����һ�ö�������Լ���û�����ǰ������ķ�ʽ��������
Status CreateBiTree(BiTree* T){
    char c;
    scanf("%c",&c);
    if(c == ' '){
        *T = NULL;
    }else{
        *T = (BiTree)malloc(sizeof(BiTNode));
        (*T) -> data = c;
        CreateBiTree(&(*T) -> lchild);
        CreateBiTree(&(*T) -> rchild);
        return OK;
    }
}

//���ʶ��������ľ�������������ʲô
Status visit(char c,int level){
    printf("%c λ�ڵ� %d ��\n",c,level);
}

//����������
Status PreOrderTraverse(BiTree T,int level){
    if(T){
        visit(T -> data,level);
        PreOrderTraverse(T -> lchild,level + 1);
        PreOrderTraverse(T -> rchild,level + 1);
    }
}

int main(){
    int level = 1;
    BiTree T = NULL;

    CreateBiTree(&T);
    PreOrderTraverse(T,level);

    return 0;
}
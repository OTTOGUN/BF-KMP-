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

//创建一棵二叉树，约定用户按照前序遍历的方式输入数据
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

//访问二叉树结点的具体操作，具体干什么
Status visit(char c,int level){
    printf("%c 位于第 %d 层\n",c,level);
}

//遍历二叉树
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
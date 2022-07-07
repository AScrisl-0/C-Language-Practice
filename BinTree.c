#include "stdio.h"
//#include "string.h"
#include "stdlib.h"

//定义二叉树（二叉链式）
typedef struct BTnode{
    char data;
    struct BTnode *lchild;
    struct BTnode *rchild;
}BTnode,*BiTree;

//创建二叉树
BiTree creatT();
//先序遍历
void preorder(BiTree T);
//中序遍历
void inorder(BiTree T);
//后序遍历
void postorder(BiTree T);
//统计二叉树结点的个数
int count(BiTree T);
//统计二叉树叶子结点的个数
int countL(BiTree T);
//菜单
void menu();
int main(){
    int x;
    BiTree T;

    printf("请选择要进行的操作:\n");
    menu();
    scanf("%d",&x);
    getchar();
    while(x){

        switch(x){
            case 1:
                printf("输入二叉树结点的值:\n");
                T=creatT();
                break;
            case 2:
                printf("二叉树的前序遍历序列为:");
                preorder(T);
                printf("\n");
                break;
            case 3:
                printf("二叉树的中序遍历序列为:");
                inorder(T);
                printf("\n");
                break;
            case 4:
                printf("二叉树的后序遍历序列为:");
                postorder(T);
                printf("\n");
                break;
            case 5:
                printf("二叉树的结点总数为:%d\n",count(T));
                break;
            case 6:
                printf("二叉树的叶子结点总数为:%d\n",countL(T));
                break;
            default:exit(0);
        }
        getchar();
        printf("\n请选择要进行的操作:\n");
        menu();
        scanf("%d",&x);
    }

    printf("________________________________________");
    printf("\n\n");
}
BiTree creatT()
{
    BTnode *T;
    char ch;
    scanf("%c",&ch);
    if(ch=='#') T=NULL;
    else{
        T=(BTnode*)malloc(sizeof(BTnode));
        T->data=ch;
        T->lchild=creatT();
        T->rchild=creatT();
    }
    return T;
}
void preorder(BiTree T)
{
    if(T){
        printf("%5c",T->data);
        preorder(T->lchild);
        preorder(T->rchild);
    }
}
void inorder(BiTree T)
{
    if(T){
        inorder(T->lchild);
        printf("%5c",T->data);
        inorder(T->rchild);
    }
}
void postorder(BiTree T)
{
    if(T){
        postorder(T->lchild);
        postorder(T->rchild);
        printf("%5c",T->data);
    }
}
int count(BiTree T)
{
    int num,left,right;
    if(T==NULL) num=0;
    else{
        left=count(T->lchild);
        right=count(T->rchild);
        num=left+right+1;
    }
    return num;
}
int countL(BiTree T)
{
    int num,left,right;
    if(T==NULL) num=0;
    else if(T->lchild==NULL&&T->rchild==NULL)  num=1;
    else{
        left=countL(T->lchild);
        right=countL(T->rchild);
        num=left+right;
    }
    return num;
}
void menu()
{
    printf("*****************************************\n");
    printf("1:创建二叉树；\n");
    printf("2:先序遍历二叉树；\n");
    printf("3:中序遍历二叉树；\n");
    printf("4:后序遍历二叉树；\n");
    printf("5:统计二叉树结点个数；\n");
    printf("6:统计二叉树叶子结点个数；\n");
    printf("0:退出！\n");
    printf("*****************************************\n");
}


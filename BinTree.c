#include "stdio.h"
//#include "string.h"
#include "stdlib.h"

//�����������������ʽ��
typedef struct BTnode{
    char data;
    struct BTnode *lchild;
    struct BTnode *rchild;
}BTnode,*BiTree;

//����������
BiTree creatT();
//�������
void preorder(BiTree T);
//�������
void inorder(BiTree T);
//�������
void postorder(BiTree T);
//ͳ�ƶ��������ĸ���
int count(BiTree T);
//ͳ�ƶ�����Ҷ�ӽ��ĸ���
int countL(BiTree T);
//�˵�
void menu();
int main(){
    int x;
    BiTree T;

    printf("��ѡ��Ҫ���еĲ���:\n");
    menu();
    scanf("%d",&x);
    getchar();
    while(x){

        switch(x){
            case 1:
                printf("�������������ֵ:\n");
                T=creatT();
                break;
            case 2:
                printf("��������ǰ���������Ϊ:");
                preorder(T);
                printf("\n");
                break;
            case 3:
                printf("�������������������Ϊ:");
                inorder(T);
                printf("\n");
                break;
            case 4:
                printf("�������ĺ����������Ϊ:");
                postorder(T);
                printf("\n");
                break;
            case 5:
                printf("�������Ľ������Ϊ:%d\n",count(T));
                break;
            case 6:
                printf("��������Ҷ�ӽ������Ϊ:%d\n",countL(T));
                break;
            default:exit(0);
        }
        getchar();
        printf("\n��ѡ��Ҫ���еĲ���:\n");
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
    printf("1:������������\n");
    printf("2:���������������\n");
    printf("3:���������������\n");
    printf("4:���������������\n");
    printf("5:ͳ�ƶ�������������\n");
    printf("6:ͳ�ƶ�����Ҷ�ӽ�������\n");
    printf("0:�˳���\n");
    printf("*****************************************\n");
}


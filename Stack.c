//
// Created by ASUS on 2021/6/2.
//
#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
struct SNode {
    int * Data;     //�洢Ԫ�ص�����
    int Top;        //ջ��ָ��
    int MaxSize;    //��ջ�������
};
typedef struct SNode * Stack;
Stack CreateStack(int MaxSize);
bool IsFull(Stack S);
bool Push(Stack S,int x);
bool IsEmpty(Stack S);
int Pop(Stack S);


int main()
{
//    Stack S=[12,34,45,5];
//    scanf("%d",&S);
    Stack CreateStack(int MaxSize);
    bool IsFull(Stack S);
    bool Push(Stack S,int x);
    bool IsEmpty(Stack S);
    int Pop(Stack S);
//    printf("%d",S);
    return 0;
}
//�����ն�ջ
Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof (struct SNode));
    S->Data=(int *)malloc(MaxSize*sizeof (int));
    S->Top=-1;
    S->MaxSize=MaxSize;
    return S;
}
//�ж϶�ջ�Ƿ�����
bool IsFull(Stack S)
{
    return (S->Top==S->MaxSize-1);
}
//Ԫ��ѹ���ջ
bool Push(Stack S,int x)
{
    if(IsFull(S))
    {
        printf("��ջ����");
        return false;
    }else{
        S->Data[++(S->Top)]=x;
        return true;
    }
}
//�ж϶�ջ�Ƿ�Ϊ��
bool IsEmpty(Stack S)
{
    return (S->Top==-1);
}
//ɾ��������ջ��Ԫ��
int Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("��ջ�ѿ�");
        return 0;
    } else{
        return (S->Data[(S->Top)--]);
    }
}
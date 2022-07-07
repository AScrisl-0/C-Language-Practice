//
// Created by ASUS on 2021/6/2.
//
#include <stdbool.h>
#include "stdio.h"
#include "stdlib.h"
#include "malloc.h"
struct SNode {
    int * Data;     //´æ´¢ÔªËØµÄÊý×é
    int Top;        //Õ»¶¥Ö¸Õë
    int MaxSize;    //¶ÑÕ»×î´óÈÝÁ¿
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
//´´½¨¿Õ¶ÑÕ»
Stack CreateStack(int MaxSize)
{
    Stack S=(Stack)malloc(sizeof (struct SNode));
    S->Data=(int *)malloc(MaxSize*sizeof (int));
    S->Top=-1;
    S->MaxSize=MaxSize;
    return S;
}
//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÒÑÂú
bool IsFull(Stack S)
{
    return (S->Top==S->MaxSize-1);
}
//ÔªËØÑ¹Èë¶ÑÕ»
bool Push(Stack S,int x)
{
    if(IsFull(S))
    {
        printf("¶ÑÕ»ÒÑÂú");
        return false;
    }else{
        S->Data[++(S->Top)]=x;
        return true;
    }
}
//ÅÐ¶Ï¶ÑÕ»ÊÇ·ñÎª¿Õ
bool IsEmpty(Stack S)
{
    return (S->Top==-1);
}
//É¾³ý²¢·µ»ØÕ»¶¥ÔªËØ
int Pop(Stack S)
{
    if(IsEmpty(S))
    {
        printf("¶ÑÕ»ÒÑ¿Õ");
        return 0;
    } else{
        return (S->Data[(S->Top)--]);
    }
}
//
// Created by ASUS on 2021/6/6.
//
#include <ntsecpkg.h>
#include <vss.h>
#include <stdbool.h>
#include "stdlib.h"
#include "stdio.h"
#define MaxSize 20
#define ERROR -1

typedef int Position;
typedef struct LNode *List;
struct LNode{
    int Data[MaxSize];
    Position Last;
};
List MakeEmpty()
{
    List L;
    L=(List)malloc(sizeof (struct LNode));
    L->Last=-1;
    return L;
}
Position Find(List L,int x)
{
    Position i=0;
    while (i<=L->Last&&L->Data[i]!=x)
    {
        i++;
        if(i>L->Last)
        {
            return ERROR;
        } else{
            return i;
        }
    }
}
bool Insert(List L,int x,Position P)
{
    Position i;
    if(L->Last==MaxSize-1)
    {
        printf("表满");
        return false;
    }
    if(P<0||P>L->Last+1)
    {
        printf("位置不合法");
        return false;
    }
    for (i = L->Last; i >=P ; i--) {
        L->Data[i+1]=L->Data[i];
        L->Data[P]=x;
        L->Last++;
        return true;
    }
}
bool Delete(List L,Position P)
{
    Position i;
    if(P<0||P>L->Last)
    {
        printf("位置%d不存在元素",P);
        return false;
    }
    for(i=P+1;i<=L->Last;i++)
    {
        L->Data[i-1]=L->Data[i];
        L->Last--;
        return true;
    }
}
int main()
{

    return 0;
}

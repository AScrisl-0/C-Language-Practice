//
// Created by ASUS on 2021/6/3.
//
#include <stdbool.h>
#include <malloc.h>
#include "stdio.h"
#define ERROR NULL
typedef struct LNode *PtrToLNode;
struct LNode{
    int Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;        //查找
Position  Find (List L,int x);
bool Insert(List L,int x,Position P);
bool Delete(List L,Position P);
int main()
{

    return 0;
}

Position  Find (List L,int x)
{
    Position p=L;
    while (p&&p->Data!=x){
        p=p->Next;
        if(p)
        {
            return p;
        }else{
            return ERROR;
        }
    }
}
bool Insert(List L,int x,Position P)
{
    Position tmp,pre;
    for (pre = L; pre&&pre->Next!=P ; pre=pre->Next);
    if(pre==NULL)
    {
        printf("插入位置参数错误\n");
        return false;
    } else{
        tmp=(Position)malloc(sizeof (struct LNode));
        tmp->Next=P;
        pre->Next=tmp;
        return true;
    }
}
bool Delete(List L,Position P)
{
    Position pre;
    for(pre=L;pre&&pre->Next!=P;pre->Next);
    if(pre==NULL||P==NULL)
    {
        printf("删除位置参数错误\n");
        return false;
    } else{
        pre->Next=P->Next;
        free(P);
        return true;
    }
}
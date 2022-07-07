//
// Created by ASUS on 2021/6/3.
//

#include <malloc.h>
#include <stdbool.h>
#include "stdio.h"

typedef struct SNode *PtrToSNode;
struct  SNode{
    int Data;
    PtrToSNode Next;
};
typedef PtrToSNode  Stack;
Stack CreateStack();
bool IsEmpty(Stack S);
bool Push(Stack S,int x);
int Pop(Stack S);
int main()
{

    return 0;
}
Stack CreateStack()
{
    Stack S;
    S=(Stack)malloc(sizeof (struct SNode));
    S->Next=NULL;
    return S;
}
bool IsEmpty(Stack S)
{
    return (S->Next==NULL);
}
bool Push(Stack S,int x)
{
    PtrToSNode TmpCell;
    TmpCell=(PtrToSNode) malloc(sizeof (struct SNode));
    TmpCell->Data=x;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
    return true;
}
int Pop(Stack S)
{
    PtrToSNode FirstCell;
    int Top;
    if(IsEmpty(S))
    {
        printf("堆栈为空\n");
        return 0;
    } else{
        FirstCell=S->Next;
        Top=FirstCell->Data;
        S->Next=FirstCell->Next;
        free(FirstCell);
        return Top;
    }
}

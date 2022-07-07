//
// Created by ASUS on 2021/6/6.
//
#include <vss.h>
#include <wingdi.h>
#include <stdlib.h>
#include "stdio.h"

int main()
{
    
    return 0;
}


typedef struct Node *PtrToNode;
struct Node{
    int Data;
    PtrToNode Next;
};
typedef PtrToNode Position;
struct QNode{
    Position Front,Rear;
    int MaxSize;
};
typedef struct QNode *Queue;
bool IsEmpty(Queue Q)
{
    return (Q->Front==NULL);
}
int DeleteQ(Queue Q)
{
    Position FrontCell;
    int Frontint;
    if(IsEmpty(Q))
    {
        printf("队列为空");
        return ERROR;
    } else{
        FrontCell=Q->Front;
        if(Q->Front==Q->Rear)
        {
            Q->Front=Q->Rear=NULL;
        } else{
            Q->Front=Q->Front->Next;
            Frontint=FrontCell->Data;
            free(FrontCell);
            return Frontint;
        }
    }
}
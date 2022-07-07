//
// Created by ASUS on 2021/6/3.
//

#include <malloc.h>
#include <stdbool.h>
#include <stdio.h>

typedef int Position;
struct QNode{
    int *Data;              //存储元素的数组
    Position Front,Rear;    //队列的的头尾指针
    int MaxSize;            //队列的最大容量
};
typedef struct QNode *Queue;
Queue CreateQueue(int MaxSize)
{
    Queue Q=(Queue)malloc(sizeof(struct QNode));
    Q->Data=(int *)malloc(MaxSize*sizeof(int));
    Q->Front=Q->Rear=0;
    Q->MaxSize=MaxSize;
    return Q;
}
bool IsFull(Queue Q)
{
    return ((Q->Rear+1)%Q->MaxSize==Q->Front);
}
bool AddQ(Queue Q,int x)
{
    if(IsFull(Q))
    {
        printf("队列已满\n");
        return false;
    } else{
        Q->Rear=(Q->Rear+1)%Q->MaxSize;
        Q->Data[Q->Rear]=x;
        return true;
    }
}
bool IsEmpty(Queue Q)
{
    return (Q->Front==Q->Rear);
}
int DeleteQ(Queue Q)
{
    if(IsEmpty(Q))
    {
        printf("队列空\n");
        return 0;
    } else{
        Q->Front=(Q->Front+1)%Q->MaxSize;
        return Q->Data[Q->Front];
    }
}

int main()
{
    return 0;
}
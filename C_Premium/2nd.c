//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"
/*
 * 角谷猜想
 * 时间：2022/3/22
 */
int main()
{
    int n,count=0;
    printf("Please enter number: ");
    scanf("%d",&n);
    do {
        if (n%2)
        {
            n=n*3+1;
            printf("[%d]:%d*3+1=%d\n",++count,(n-1)/3,n);
        }else{
            n/=2;
            printf("[%d]:%d/2=%d\n",++count,2*n,n);
        }
    }while(n!=1);

    return 0;
}
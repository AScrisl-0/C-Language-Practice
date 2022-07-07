//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"

/*
 * 杨辉三角
 * 时间：2022/3/22
 */
int c(x,y);
int main()
{
    int i,j,n=13;
//    printf("Please Input enter nums: \n");
//    scanf("%d",&n);
    printf("N=");
    while(n>12)
    {
        scanf("%d",&n);
    }
    for ( i = 0; i <=n; i++) {
        for ( j = 0; j <12-i ; j++) {
            printf("");
        }
        for ( j = 1; j <i+2 ; j++) {
            printf("%6d",c(i,j));
        }
        printf("\n");
    }
    return 0;
}
int c(x,y)
{
    int z;
    if((y==1)||(y==x+1))
    {
        return (1);
    }
    z=c(x-1,y-1)+c(x-1,y);
    return(z);
}
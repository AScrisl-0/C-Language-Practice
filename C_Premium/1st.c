//
// Created by ASUS on 2022/3/22.
//

#include<stdio.h>
/*
 * 斐波那契数列
 * 时间：2022/3/21
 */
int main()
{
    int n,i;
    int f1,f2,f;
    for ( n = 2; n < 3;) {
        printf("Please enter required number of generation:");
        scanf("%d",&n);
        if (n<3)
            printf("\n Enter error！\n");
    }
    f=f2=1;
    printf("The repid increase of rabbits in first %d generation is as felow\n",n);
    printf("1\t1\t");
    for ( i = 3; i <=n ; i++) {
        f1=f2;
        f2=f;
        f=f1+f2;
        printf(i%10 ?"%d\t":"%d\n",f);
    }
    printf("\n");
}
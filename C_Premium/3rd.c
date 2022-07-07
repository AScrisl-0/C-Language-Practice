//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"

/*
 * 求素数
 * 时间：2022/3/22
 */

int main()
{
    int p,q;
    int i,j,flag;
    int count=0;
    do {
        printf("Input START and END : ");
        scanf("%d%d",&p,&q);
    }while(!(p>0 && p<q));
    printf("----------------------------PRIME TABLE (%d-%d)-------------------------\n",p,q);
    if (p==1 || p==2)
    {
        printf("%6d",2);
        p=3;
        count++;
    }
    for ( i = p; i <=q ; i++) {
        if (!(i%2))
        {
            continue;
        }
        for ( flag = 1 ,j =3 ; flag&&j <i/2 ; j+=2) {
            if (!(i%j))
            {
                flag=0;
            }
        }
        if (flag)
        {
            printf(++count%15 ?"%6d":"%6d\n",i);
        }
    }
    return 0;
}
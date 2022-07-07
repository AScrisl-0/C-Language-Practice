//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"

/*
 * 最大公约数与最小公倍数
 * 时间：2022/3/22
 */

int main()
{
    int a,b;
    int num1,num2,temp;
    printf("Input a & b :");
    scanf("%d%d",&num1,&num2);
    if (num1>num2)
    {
        temp =num1;
        num1=num2;
        num2=temp;
    }
    a=num1;
    b=num2;
    while(b!=0)     /*辗转相除法求最大公约数*/
    {
        temp=a%b;
        a=b;
        b=temp;
    }
    printf("The GCD of %d and %d is :%d\n",num1,num2,a);
    printf("The LCM of them is:%d\n",num1 * num2/a);

    return 0;
}
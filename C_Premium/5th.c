//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"
/*
 * 数制转换
 * 时间：2022/3/23
 */
printbin(x,n);

int main() {
    int x;
    printf("Please Input Number: ");
    scanf("%d", &x);
    printf("Number of decimal from :%d\n", x);
    printf("It's binary from: ");
    printbin(x, sizeof(int) * 8);
    putchar('\n');
    return 0;
}

printbin(x,n)
int x,n;
{
    if(n>0)
    {
        putchar('0'+((unsigned )(x&(1<<(n-1)))>>(n-1)));
        printbin(x,n-1);
    }
}
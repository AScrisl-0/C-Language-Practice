#include "stdio.h"
int main()
{
    int n;
    int sum=0;
    int i=1;
    printf("Please Input : ");
    scanf("%d",&n);
    if(n<0){
        printf("Input Error !\n");
    }else {
        while (i <= n) {
            sum+= i;
            i++;
        }
        printf("%d=%d", n, sum);
    }
    return 0;

}
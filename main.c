#include <stdio.h>
#include "stdlib.h"
#include<malloc.h>
#include "windows.h"
#include "time.h"

int main() {
    int a=123;
    int * p=&a;

    printf("%d\n",*p);
    printf("Hello, World!\n");
    return 0;
}

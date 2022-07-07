//
// Created by ASUS on 2021/5/26.
//

#include <stdio.h>

int add(int *x,int *y);
  int main()
  {
      int ADD;
      typedef struct arithmetic{
              int number1;
              int number2;
              int input;
          }Airthmetic;
      struct arithmetic test ;
      test.number1=36;
      test.number2=45;
      printf("%d + %d = ", test.number1, test.number2);
      scanf("%d", &test.input);

      if(test.input == (test.number1 + test.number2)){
          printf("回答正确！\n");
      }else{
          printf("回答错误！\n");
          ADD=add(&test.number1,&test.number2);
          printf("正确答案：%d\n",ADD);

      }
      return 0;
  }
  int add(int *x,int *y)
  {
    int z;
    z=*x+*y;
    return z;
  }

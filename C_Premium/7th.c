//
// Created by ASUS on 2022/3/22.
//

#include "stdio.h"

/*
 * 加法还原
 * 时间：2022/3/22
 */
int main()
{
    int p,e, a,r;
    for(p=1;p<=9;p++)
    {
        for(e=0; e<=9;e++)
        {
            if (p != e)
            {
                for(a=1;a<=9; a++)
                {
                    if (a!=p &&  a!=e)
                    {
                        for(r=0; r<=9; r++)
                        {
                            if(r!=p&&r!=e&&r!=a
                            &&p*1000+e*100+a*10+r-(a*100+r*10+a)
                            == p*100+e*10+a)
                            {
                                printf("   PEAR      %d%d%d%d\n",p,e,a,r);
                                printf("-   ARA    -  %d%d%d\n",a,r,a);
                                printf("---------   ----------\n");
                                printf("    PEA       %d%d%d\n", p, e,a);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}













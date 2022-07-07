#include <stdio.h>
// 库文件和预设定义
#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];
/****-------------------------------------------- *****/
// 函数名:Index(SString S,SString T,int pos)
// 参数:(传出)SString S，字符串
// (传入)SString T，字符串
// (传入)int pos，定位初试位置
// 作用:求子串位置
// 返回值:整型，定位成功返回位置，否则返回0
/****-------------------------------------------- *****/
int Index(SString S,SString T,int pos)
{
    int i=pos, j=1;
    while(i<=S[0]&&j<=T[0]) // 在S和T的长度之内开始查找
    {
        if(S[i]==T[j]) // 若相等，继续比较
        {
            ++i;
            ++j;
        }
        else // 否则从S的下一个字符开始重新和T的字符进行比较
        {
            i=i-j+2;
            j=1; // 指针后退重新开始匹配
        }
    }
    if(j>T[0]) return i-T[0];
    else return 0;
}
/****-------------------------------------------- *****/
// 函数名 : strLengh(SString S)
// 参数 : (传入)SString S，字符串
// 作用 : 得到串的长度，放于下标为0的位置
// 返回值 : 无
/****-------------------------------------------- *****/
void strLengh(SString S)
{
    int m;
    for(m=1;S[m]!='\0';m++);
    S[0]=m-1;
}
void main()
{
    SString S,T;
    int pos; // 1<=pos<=S[0]-T[0]+1;
    int r;
    printf(" 输入主串 S:");
    scanf("%s",S+1); // 跳过下标为0的元素
    printf(" 输入模式串 T:");
    scanf("%s",T+1); // 跳过下标为0的元素
    printf(" 输入起始位置 pos:");
    scanf("%d",&pos);
    //得到两个串的长度，放于下标为0的位置
    strLengh(S);
    strLengh(T);
    if(r = Index(S,T,pos))
        printf("模式串在主串中的位置为 : %d\n", r);
    else printf(" 匹配失败 !");
}
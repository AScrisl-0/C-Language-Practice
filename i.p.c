#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "windows.h"

#define BOOKLEN sizeof(struct BookInfo)
#define READERLEN sizeof(struct ReaderInfo)
//函数声明
void Welcome();
int MainMenu();
void SubMenu1();
int CreateSubMenu1();
void SubMenu2();
int CreateSubMenu2();
void SubMenu3();
int CreateSubMenu3();
void SubMenu4();
int CreateSubMenu4();
void AddBookInfo();         //新增图书信息
void ModifyBookInfo();      //修改图书信息
void DelBookInfo();         //删除图书信息
int CountBook();            //获得图书记录数
int CountReader();          //获得读者记录数
int IsBookExist(char * );   //判断图书是否存在
int IsReaderExist(char * ); //判断读者是否存在
void AddReaderInfo();       //增加读者信息
void ModifyReaderInfo();    //修改读者信息
void DelReaderInfo();       //删除读者信息
void ShowBookInfo();        //显示图书清单
void ShowReaderInfo();      //显示读者清单
int CheckToFloat(char * );  //检查输入的价格是否合法
float ConvertToFloat(char * );//图书价格字符串转换为浮点数
int IsBorrow(char *);       //判断图书是否在借
int IsBorrowed(char *);     //统计读者在借图书册数
void BookBorrow();          //借书
void BookReturn();          //还书
void SearchBook();          //图书查询
void SearchReader();        //读者查询
int GetPosition(char *,struct BookInfo *);      //修改图书信息
int GetRdPosition(char *,struct ReaderInfo *);  //修改读者信息
int InvalidBookPosition();  //查询第一条无效图书信息的位置
int InvalidReaderPosition();//查询第一条无效读者的信息的位置
void ShowAReader(char *);   //显示指定编号的读者详细信息

struct BookInfo
{
    char BookCode[6];       //图书编号
    char BookName[30];      //书名
    char BookAuthor[20];    //作者
    float BookPrice;        //价格
    char BookPress[50];     //出版社
    char PublicationDate[8];//出版年月
    char ISBN[18];          //ISBN号
    char BookStatus;        //图书借阅状态
    char ReaderCode[6];     //读者编号
    char IsAvailable;       //图书是否有效
};
//读者结构定义
struct ReaderInfo
{
    char ReaderCode[6];     //读者编号
    char ReaderName[20];    //读者姓名
    char Sex[3];            //读者性别
    char IsAvailable;       //读者是否生效
};

int MainMenu()              //一级菜单
{
    int m,k;
    while(1)
    {
        printf("\n        主菜单\n");
        printf("            ----------------\n");
        printf("             1.图书信息管理\n");
        printf("             2.读者信息管理\n");
        printf("             3.图书流动\n");
        printf("             4.统计查询\n");
        printf("             0.退出系统\n");
        printf("请选择（0~4）: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=4 && k==1)
        {
            break;
        }else{
            printf("\n 选择错误，请重新选择\n");
        }
    }
    return m;
}
int CreateSubMenu1()        //二级菜单 图书信息管理
{
    int m,k;
    while (1)
    {
        printf("             图书信息管理\n");
        printf("            ----------------\n");
        printf("             1.新增图书信息\n");
        printf("             2.修改图书信息\n");
        printf("             3.删除图书信息\n");
        printf("             0.返回上一级菜单\n");
        printf("请选择（0~3）: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=3 && k==1)
        {
            break;
        }else{
            printf("\n 选择错误，请重新选择\n");
        }
    }
    return m;
}
int CreateSubMenu2()        //二级菜单 读者信息管理
{
    int m,k;
    while (1)
    {
        printf("             读者信息管理\n");
        printf("            ----------------\n");
        printf("             1.新增读者信息\n");
        printf("             2.修改读者信息\n");
        printf("             3.删除读者信息\n");
        printf("             0.返回上一级菜单\n");
        printf("请选择（0~3）: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=3 && k==1)
        {
            break;
        }else{
            printf("\n 选择错误，请重新选择\n");
        }
    }
    return m;
}
int CreateSubMenu3()        //二级菜单 图书借阅
{
    int m,k;
    while (1)
    {
        printf("             图书流通\n");
        printf("            ----------------\n");
        printf("             1.借书\n");
        printf("             2.还书\n");
        printf("             0.返回上一级菜单\n");
        printf("请选择（0~2）: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=2 && k==1)
        {
            break;
        }else{
            printf("\n 选择错误，请重新选择\n");
        }
    }
    return m;
}
int CreateSubMenu4()        //二级菜单 读者信息管理
{
    int m,k;
    while (1)
    {
        printf("             统计查询\n");
        printf("            ----------------\n");
        printf("             1.图书清单\n");
        printf("             2.读者清单\n");
        printf("             3.图书查询\n");
        printf("             4.读者查询\n");
        printf("             0.返回上一级菜单\n");
        printf("请选择（0~4）: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=4 && k==1)
        {
            break;
        }else{
            printf("\n 选择错误，请重新选择\n");
        }
    }
    return m;
}

void main()
{
    system("mode con cols=120 lines=30");//窗口宽度，高度
    int MenuId;
    Welcome();
    while (1)
    {
        MenuId=MainMenu();
        if (MenuId==0)
        {
            printf("\n Proceduce End!\n\n");
            break;
        }
        switch (MenuId) {
            case 1:SubMenu1();break;
            case 2:SubMenu2();break;
            case 3:SubMenu3();break;
            case 4:SubMenu4();break;
        }
    }
}

void Welcome()
{
    system("cls");
    printf("\n  *************************\n");
    printf("     **                     **\n");
    printf("     **    图书信息借阅系统    **\n");
    printf("     **                     **\n");
    printf("     *************************\n");
    printf("\n 现有记录数： 图书%d 册  读者 %d 人\n",CountBook(),CountReader());
}

int CountBook()             //统计已有图书数量（有效图书）
{
    struct BookInfo BookTemp;
    FILE *fp;
    int count=0;
    if((fp = fopen("bookinfo.dat","rb"))==NULL)
    {
        return 0;
    }else{
        while (fread(&BookTemp,BOOKLEN,1,fp))
            if(BookTemp.IsAvailable=='1'){
                count ++;
            }else{
                fclose(fp);
                return count;
            }
    }
}

int CountReader()           //统计已有读者人数（有效读者）
{
    struct ReaderInfo ReaderTemp;
    FILE *fp;
    int count;
    if((fp== fopen("readerinfo.dat","rb"))==NULL)
    {
        return 0;
    }else{
        while (fread(&ReaderTemp,READERLEN,1,fp))
        {
            if (ReaderTemp.IsAvailable=='1'){
                count++;
            }else{
                fclose(fp);
                return count;
            }
        }
    }
}

void SubMenu1()             //图书信息管理
{
    int MenuId;
    while (1)
    {
        MenuId=CreateSubMenu1();
        if (MenuId==0)
            break;
        switch (MenuId) {
            case 1:AddBookInfo();break;
            case 2:ModifyBookInfo();break;
            case 3:DelBookInfo();break;
            case 0:MainMenu();break;
        }
    }
}

void SubMenu2()             //读者信息管理
{
    int MenuId;
    while (1)
    {
        MenuId=CreateSubMenu2();
        if (MenuId==0)
            break;
        switch (MenuId) {
            case 1:AddBookInfo();break;
            case 2:ModifyBookInfo();break;
            case 3:DelBookInfo();break;
            case 0:MainMenu();break;
        }
    }
}

void SubMenu3()             //图书借阅
{
    int MenuId;
    while (1)
    {
        MenuId=CreateSubMenu3();
        if (MenuId==0)
            break;
        switch (MenuId) {
            case 1:BookBorrow();break;  //借书
            case 2:BookReturn();break;  //还书
            case 0:MainMenu();break;
        }
    }
}

void  SubMenu4()            //信息查询
{
    int MenuId;
    while(1)
    {
        MenuId=CreateSubMenu4();
        if (MenuId==0)
        {
            break;
        }else{
            switch (MenuId) {
                case 1:ShowBookInfo();break;
                case 2:ShowReaderInfo();break;
                case 3:SearchBook();break;
                case 4:SearchReader();break;
                case 0:MainMenu();break;
            }
        }
    }
}

//功能：新增一条图书信息记录
void AddBookInfo()
{
    struct BookInfo MyBook;
    char BookPrice[20];
    printf("\n新增图书信息（按提示输入信息）\n");
    printf("图书编号：");
    gets(MyBook.BookCode);
    while(IsBookExist(MyBook.BookCode))
    {
        printf("新增的图书编号%s已存在，请重新输入！\n",MyBook.BookCode);
        printf("图书编号：");
        gets(MyBook.BookCode);
    }
    printf("书名：");
    gets(MyBook.BookName);
    printf("作者：");
    gets(MyBook.BookAuthor);
    printf("价格：");
    while(!CheckToFloat(gets(BookPrice)))     //输入的价格字符串是否正确
    {
        printf("输入的价格不合法！重新输入\n");
        printf("价格：");
    }
    MyBook.BookPrice= ConvertToFloat(BookPrice);    //浮点类型字符串转换为浮点数
    printf("出版社：");
    gets(MyBook.BookPress);
    printf("ISBN :");
    gets(MyBook.ISBN);
    printf("出版日期 ：");
    gets(MyBook.PublicationDate);
    MyBook.BookStatus='0';
    strcpy(MyBook.ReaderCode,'0');
    MyBook.IsAvailable='1';             //新增图书，默认有效

    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    //查询写入文件位置
    int SetPs;
    SetPs=InvalidBookPosition();
    if(SetPs==-1)               //图书记录中不存在无效图书，文件指针定位在文件尾
    {
        fseek(fp,0,SEEK_END);
    }else{
        fseek(fp,(long)BOOKLEN*SetPs,SEEK_SET); //重定位写入起始位置
    }
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("新增图书成功，现有图书%d册 \n",CountBook());
    flushall();
    getchar();
}

//功能：修改图书信息
void ModifyBookInfo()
{
    struct BookInfo MyBook;
    char ModifyBookCode[6];
    if(CountBook()==0)
    {
        printf("库中没有图书信息，无法执行信息！\n");
        return;
    }
    printf("\n---修改图书信息---\n");
    printf("输入要修改的图书编号：");
    gets(ModifyBookCode);
    if (!IsBookExist(ModifyBookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n",ModifyBookCode);
        return ;
    }
    int ModiPosition=0;     //要修改图书在文件中的位置
    //传递结构变量MyBook的地址，获得要修改的图书信息，存储在MyBook结构中
    //图书信息中的图书编号、借阅的状态、是否有效等
    //信息不做修改
    ModiPosition= GetPosition(ModifyBookCode,&MyBook);
    printf("按如下提示编号为%s的图书信息\n",ModifyBookCode);
    printf("书名：");
    gets(MyBook.BookName);
    printf("作者：");
    gets(MyBook.BookAuthor);
    char BookPrice[20];
    printf("价格：");
    while(!CheckToFloat(gets(BookPrice)))     //输入的价格字符串是否正确
    {
        printf("输入的价格不合法！请重新输入！\n");
        printf("价格：");
    }
    MyBook.BookPrice= ConvertToFloat(BookPrice);    //浮点类型字符串转换为浮点数
    printf("出版社：");
    gets(MyBook.BookPress);
    printf("ISBN :");
    gets(MyBook.ISBN);
    printf("出版日期：");
    gets(MyBook.PublicationDate);
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    //写入文件：在原有图书信息存储位置覆盖写入修改信息
    fseek(fp,(long)BOOKLEN*ModiPosition,SEEK_SET);      //重定位写入起始位置
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("修改图书信息成功 \n");
    flushall();
    getchar();
}

//功能：删除图书记录
void DelBookInfo()
{
    char DelBookCode[6];
    if (CountBook()==0)
    {
        printf("库中没有图书信息，无法执行删除!\n");
        return ;
    }
    printf("\n---删除图书信息---\n");
    printf("输入要删除图书信息的编号：");
    gets(DelBookCode);
    if (!IsBookExist(DelBookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n",DelBookCode);
        return;
    }
    //若图书在借在借中不可执行删除操作
    if (IsBorrow(DelBookCode))
    {
        printf("编号为%s的图书已被借阅，不可删除！\n",DelBookCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    //删除图书，将IsAvailable成员置为'0'
    struct BookInfo MyBook;
    int ModiPosition=0;
    ModiPosition= GetPosition(DelBookCode,&MyBook);
    MyBook.IsAvailable='0';
    fseek(fp,(long)BOOKLEN*ModiPosition,SEEK_SET);      //重定位写入起始位置
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("删除图书记录成功，现有图书%d册\n",CountBook());
}

//功能：借书
void BookBorrow()
{
    char BookCode[6];
    char ReaderCode[6];
    if(CountBook()==0||CountReader==0)
    {
        printf("库中没有图书或读者信息，无法执行借阅操作！\n");
        return;
    }
    printf("\n---借书---\n");
    printf("输入图书编码：");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("借阅失败，编号为%s的图书不存在！\n",BookCode);
        return;
    }
    if (IsBorrow(BookCode))
    {
        printf("借阅失败，编号为%s的图书以借出！\n",BookCode);
        return;
    }
    printf("输入读者编码：");
    gets(ReaderCode);
    if(!IsReaderExist(ReaderCode))
    {
        printf("借阅失败，编号为%s的读者不存在！\n",ReaderCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        return;
    }
    //借书
    //1.将图书状态Book Status置为‘1’
    //2.将图书Reader Code置为读者编号
    //3.其他成员信息保持不变
    int Position=0;         //修改图书在文件中的位置
    struct BookInfo MyBook;
    Position = GetPosition(BookCode,&MyBook);
    MyBook.BookStatus='1';
    strcpy(MyBook.ReaderCode,&MyBook);
    fseek(fp,(long)BOOKLEN*Position,SEEK_SET);      //重定位写入起始位置
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("图书借阅成功!\n");
    flushall();
    getchar();
}

//功能：还书
void BookReturn()
{
    char BookCode[6];
    char ReaderCode[6];
    if(CountBook()==0||CountReader==0)
    {
        printf("库中没有图书或读者信息，无法执行借阅操作！\n");
        return;
    }
    printf("\n---还书---\n");
    printf("输入图书编码：");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("还书失败，编号为%s的图书不存在！\n",BookCode);
        return;
    }
    if (IsBorrow(BookCode))
    {
        printf("还书失败，编号为%s的图书以借出！\n",BookCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        return;
    }
    //还书
    //1.将图书状态Book Status置为‘0’
    //2.将图书Reader Code置为‘0’
    //3.其他成员信息保持不变
    int Position=0;         //修改图书在文件中的位置
    struct BookInfo MyBook;
    Position = GetPosition(BookCode,&MyBook);
    MyBook.BookStatus='0';
    strcpy(MyBook.ReaderCode,'0');
    fseek(fp,(long)BOOKLEN*Position,SEEK_SET);      //重定位写入起始位置
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("还书成功!\n");
    flushall();
    getchar();
}

//功能：显示所有图书信息
void ShowBookInfo()
{
    struct BookInfo MyBookInfo;
    int booknum=CountBook();
    if(booknum==0){
        printf("库中没有图书信息！\n");
        return;
    }
    FILE *fp;
    if((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    printf("\n 编号    书名          作者     价格   出版社   出版日期\n");
    printf("---------------------------------------------------------");
    while (fread(&MyBookInfo,BOOKLEN,1,fp))
    {
        if(MyBookInfo.IsAvailable=='1')
        {
            printf("%-7s%-31s%-11s%-7.2f%-20s%-7s\t%c\t%s\t%c\n",MyBookInfo.BookCode,
                   MyBookInfo.BookName,MyBookInfo.BookAuthor,MyBookInfo.BookPrice,MyBookInfo.BookPress,
                   MyBookInfo.PublicationDate,MyBookInfo.BookStatus,MyBookInfo.ReaderCode
                    ,MyBookInfo.IsAvailable);
        }
    }
    fclose(fp);
}

//功能：显示指定编号的图书信息
void SearchBook()   //图书查询
{
    char BookCode[6];
    if(CountBook()==0)
    {
        printf("库中没有图书信息，无法执行查询！\n");
        return ;
    }
    printf("\n--查询图书信息--\n");
    printf("输入查询的图书编号：");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("编号为%s的图书不存在，请核查！\n",BookCode);
        return ;
    }
    struct BookInfo MyBook;
    GetPosition(BookCode,&MyBook);
    printf("编号为%s的图书详细信息\n",MyBook.BookCode);
    printf("-----------------------\n");
    printf("   书名： \t%s\n",MyBook.BookName);
    printf("   作者： \t%s\n",MyBook.BookAuthor);
    printf("   价格： \t%.2f\n",MyBook.BookPrice);
    printf("   出版社： \t%s\n",MyBook.BookPress);
    printf("   出版日期： \t%s\n",MyBook.PublicationDate);
    printf("   ISBN： \t%s\n",MyBook.ISBN);
    if (MyBook.BookStatus=='1')     //若图书已借出，则显示借阅的读者信息
    {
        ShowAReader(MyBook.ReaderCode);
    } else{
        printf("  此书未被借阅\n");
    }
}

//功能:显示读者信息
void SearchReader()
{
    char ReaderCode[6];
    if(CountReader()==0)
    {
        printf("库中没有读者信息，无法执行查询！\n");
        return;
    }
    printf("\n--查询读者信息--\n");
    printf("输入查询的读者编号：");
    gets(ReaderCode);
    if (!IsReaderExist(ReaderCode))
    {
        printf("编号为%s的读者不存在，请核查！\n",ReaderCode);
        return;
    }
    printf("---------------------\n");
    ShowAReader(ReaderCode);
    int BorrowCount= IsBorrowed(ReaderCode);
    if (BorrowCount==0)
    {
        printf("  该读者未借阅图书\n");
    }else{
        printf("  该读者共借阅%d册图书，信息如下：\n",BorrowCount);
        FILE *fp;
        if((fp= fopen("bookinfo.dat","rb"))==NULL)
        {
            printf("can not open file \n");
            exit(0);
        }
        struct BookInfo MyBook;
        int i=0;
        while(fread(&MyBook,BOOKLEN,1,fp))
        {
            if(strcmp(MyBook.ReaderCode,ReaderCode)==0)
            {
                i++;
                printf("   %d 、  %-6s%s (%s) \n",i,MyBook.BookCode,MyBook.BookName,MyBook.BookAuthor);
            }
        }
        fclose(fp);
    }
}

//功能：显示指定编号的读者的详细信息
void ShowAReader (char * ReaderCode)
{
    FILE *fp;
    if((fp= fopen("readerinfo,dat","rb"))==NULL)
    {
        printf("can not open file \n");
        exit(0);
    }
    struct ReaderInfo MyReader;
    while(fread(&MyReader,READERLEN,1,fp))
    {
        if (strcmp(MyReader.ReaderCode,ReaderCode)==0)
            break;
    }
    printf("  借阅读者：\t%s (%s-%s) \n",ReaderCode,MyReader.ReaderName,MyReader.Sex);
    fclose(fp);
}

//功能：查询第一条无效的图书记录在文件的位置

int InvalidBookPosition()
{
    int InvalidPs=-1;
    int count=0;
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb"))==NULL)
    {
        printf("can not open file \n");
        exit(0);
    }
    struct BookInfo MyBook;
    while (fread(&MyBook,BOOKLEN,1,fp))
    {
        if (MyBook.IsAvailable=='0')
        {
            InvalidPs=count;
            break;
        }
        count++;
    }
    fclose(fp);
    return InvalidPs;
}

//功能：查询指定的图书在文件中是否存在
int IsBookExist(char * ChkBookCode)
{
    int IsExist=0;
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb"))==NULL)
    {
        printf("can not open file \n");
        exit(0);
    }
    struct BookInfo Mybook;
    while(fread(&Mybook,BOOKLEN,1,fp))
    {
        if(strcmp(Mybook.BookCode,ChkBookCode)==0&& Mybook.IsAvailable=='1')
        {
            IsExist=1;
            break;
        }
    }
    fclose(fp);
    return IsExist;
}

//功能：判断图书是否被借
int IsBorrow(char * BookCode)
{
    struct  BookInfo temp;
    int IsBorrow=0;
    FILE *fp;
    if((fp= fopen("bookinfo.dat","rb"))!=NULL)
    {
        while(fread(&temp,BOOKLEN,1,fp))
        {
            if(strcmp(temp.BookCode,BookCode)==0&&temp.BookStatus=='1')
            {
                IsBorrow=1;
                break;
            }
        }
    }
    fclose(fp);
    return IsBorrow;
}

//功能：获得待修复改的图书记录在文件中的位置
int GetPosition(char * ModiCode,struct BookInfo * MyBook)
{
    int count=0;
    FILE * fp;
    if ((fp=fopen("bookinfo.dat","rb"))==NULL)
    {
        printf("can not open file\n");
        exit(0);
    }
    while(fread(MyBook,BOOKLEN,1,fp))
    {
        if (strcmp(MyBook->BookCode,ModiCode)==0&& MyBook->IsAvailable=='1')
        {
            break;
        }
        count++;
    }
    fclose(fp);
    return count;
}

//功能：增加读者信息
void AddReaderInfo()
{
    struct ReaderInfo MyReader;
    printf("\n 增加读者信息 （按提示输入信息）\n");
    printf("读者编号（<=5个字符）：");
    gets(MyReader.ReaderCode);
    while(IsReaderExist(MyReader.ReaderCode))
    {
        printf("增加读者编号%s已经存在，请重新输入！\n",MyReader.ReaderCode);
        printf("读者编号 （<=5个字符）：");
        gets(MyReader.ReaderCode);
    }
    printf("读者姓名：");
    gets(MyReader.ReaderName);
    printf("性别：");
    gets(MyReader.Sex);
    MyReader.IsAvailable='1';
    FILE *fp;
    if ((fp=fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    //查询写入文件位置
    int SetPs;
    SetPs=InvalidReaderPosition();
    if (SetPs==-1)
    {
        fseek(fp,0,SEEK_END);
    }else{
        fseek(fp,(long) READERLEN*SetPs,SEEK_SET);
    }
    fwrite(&MyReader,READERLEN,1,fp);
    fclose(fp);
    printf("增加读者成功，现有读者%d人\n",CountReader());
    flushall();
    getchar();
}

//功能：修改读者信息
void ModifyReaderInfo()
{
    struct ReaderInfo MyReader;
    char ModifyCode[6];
    if (CountReader()==0)
    {
        printf("库中没有读者信息，无法执行修改！\n");
        return;
    }
    printf("\n--修改读者信息--\n");
    printf("输入与修改的读者编号：");
    gets(ModifyCode);
    if (!IsReaderExist(ModifyCode))
    {
        printf("编号为%s的读者不存在，请核查！\n",ModifyCode);
        return;
    }
    int ModiPosition=0;
    ModiPosition= GetRdPosition(ModifyCode,&MyReader);
    printf("按如下提示输入编号为%s的读者信息\n",ModifyCode);
    printf("读者姓名：");
    gets(MyReader.ReaderName);
    printf("性别：");
    gets(MyReader.Sex);
    FILE * fp;
    if ((fp= fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    fseek(fp,(long)READERLEN*ModiPosition,SEEK_SET);
    fwrite(&MyReader, READERLEN,1,fp);
    fclose(fp);
    printf("修改读者信息成功\n");
    flushall();
    getchar();
}

//功能：删除一条读者记录
void DelReaderInfo()
{
    char DelCode[6];
    if (CountReader()==0)
    {
        printf("库中没有读者信息。无法执行删除！\n");
        return;
    }
    printf("\n--删除读者信息--\n");
    printf("输入欲删除读者的编号：");
    gets(DelCode);
    if (!IsReaderExist(DelCode))
    {
        printf("编号为%s的读者不存在，请核查！\n",DelCode);
        return ;
    }
    int BorrowedNum;
    BorrowedNum= IsBorrowed(DelCode);
    if (BorrowedNum)
    {
        printf("编号为%s的读者有%d册图书未还，不可删除！\n",DelCode,BorrowedNum);
        return;
    }
    FILE *fp;
    if ((fp= fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    //删除读者信息
    struct ReaderInfo MyReader;
    int ModiPosition=0;
    ModiPosition=GetRdPosition(DelCode,&MyReader);
    MyReader.IsAvailable='0';
    fseek(fp,(long)READERLEN*ModiPosition,SEEK_SET);
    fwrite(&MyReader,READERLEN,1,fp);
    fclose(fp);
    printf("删除读者信息记录成功，现有读者%人\n",CountReader());
}

//功能：判断读者是否有借阅图书未归还
int IsBorrowed(char * ReaderCode)
{
    struct BookInfo temp;
    int BorrowedNum=0;
    FILE *fp;
    if ((fp=fopen("bookinfo.dat","rb"))!=NULL)
    {
        while(fread(&temp,BOOKLEN,1,fp))
        {
            if(strcmp(temp.ReaderCode,ReaderCode)==0&&temp.BookStatus=='1')
                BorrowedNum++;
        }
    }
    fclose(fp);
    return BorrowedNum;
}

//功能：获得待修改的读者记录在文件中的位置
int GetRdPosition(char * ModiCode,struct ReaderInfo * MyReader)
{
    int count=0;
    FILE *fp;
    if ((fp= fopen("reader.dat","rb"))==NULL)
    {
        printf("can not open file \n");
        exit(0);
    }
    while(fread(MyReader,READERLEN,1,fp))
    {
        if (strcmp(MyReader->ReaderCode,ModiCode)==0&&MyReader->IsAvailable=='1')
        {
            break;
        }
        count++;
    }
    fclose(fp);
    return count;
}

//功能：查询读者是否存在
int IsReaderExist(char * ChkCode)
{
    int IsExist=0;
    FILE *fp;
    if ((fp= fopen("readerinfo.dat","rb"))==NULL)
    {
        printf("can not open file\n");
        exit(0);
    }
    struct ReaderInfo MyReader;
    while(fread(&MyReader,READERLEN,1,fp))
    {
        if (strcmp(MyReader.ReaderCode,ChkCode)==0 && MyReader.IsAvailable=='1')
        {
            IsExist=1;
            break;
        }
    }
    fclose(fp);
    return IsExist;
}

//功能：查询第一条无效读者记录的位置
int InvalidReaderPosition()
{
    int InvalidPs=-1;
    int count=0;
    FILE *fp;
    if ((fp= fopen("readerinfo.dat","rb"))==NULL)
    {
        printf("can not open file\n");
        exit(0);
    }
    struct ReaderInfo MyReader;
    while( fread(&MyReader,READERLEN,1,fp))
    {
        if (MyReader.IsAvailable=='0')
        {
            InvalidPs=count;
            break;
        }
        count++;
    }
    fclose(fp);
    return InvalidPs;
}

//功能：显示所有读者信息
void ShowReaderInfo()
{
    struct ReaderInfo MyReader;
    int ReaderNum=CountReader();
    if (ReaderNum==0)
    {
        printf("库中没有读者信息！\n");
        return;
    }
    FILE *fp;
    if ((fp=fopen("readerinfo.dat","rb"))==NULL)
    {
        printf("打开文件错误！\n");
        exit(0);
    }
    printf("\n编号      姓名      性别 \n");
    printf("---------------------------\n");
    while(fread(&MyReader,READERLEN,1,fp))
    {
        if (MyReader.IsAvailable=='1'){
            printf("%-7s%-11s%-5s\n",MyReader.ReaderCode,MyReader.ReaderName,MyReader.Sex);
        }
    }
    fclose(fp);
}

//功能：判断输入图书价格是否正确
int CheckToFloat(char *temp)
{
    int IsOk=1;
    char *pt;
    int DotCount=0;
    pt=temp;
    while(*pt!='\0')
    {
        if (!(*pt>='0'&& *pt<='9')&& *pt!='.')
        {
            IsOk=0;
        }else if (*pt=='.')
        {
            DotCount++;
            pt++;
        }

    }
    if (DotCount>1)
    {
        IsOk=0;
    }
    return IsOk;
}

//功能：将浮点数类型的字符串转化为浮点数
float ConvertToFloat(char *temp)
{
    float BookPrice=0;
    int StringLen;
    int flag=0;
    int count;
    char *pt;
    StringLen= strlen(temp);
    pt=temp;
    while(*pt!='\0')
    {
        if (*pt=='.')
        {
            flag=1;
            pt++;
            count=1;
        }
        if (*pt>='0'&& *pt<='9'&& !flag)
        {
            BookPrice=BookPrice*10+(*pt-'0');
        }else{
            BookPrice=BookPrice+(*pt-'0')* pow(0.1,count);
            count++;
        }
        pt++;
    }
    return BookPrice;
}

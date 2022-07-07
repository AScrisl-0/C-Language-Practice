#include "stdio.h"
#include "conio.h"
#include "stdlib.h"
#include "string.h"
#include "math.h"
#include "windows.h"

#define BOOKLEN sizeof(struct BookInfo)
#define READERLEN sizeof(struct ReaderInfo)
//��������
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
void AddBookInfo();         //����ͼ����Ϣ
void ModifyBookInfo();      //�޸�ͼ����Ϣ
void DelBookInfo();         //ɾ��ͼ����Ϣ
int CountBook();            //���ͼ���¼��
int CountReader();          //��ö��߼�¼��
int IsBookExist(char * );   //�ж�ͼ���Ƿ����
int IsReaderExist(char * ); //�ж϶����Ƿ����
void AddReaderInfo();       //���Ӷ�����Ϣ
void ModifyReaderInfo();    //�޸Ķ�����Ϣ
void DelReaderInfo();       //ɾ��������Ϣ
void ShowBookInfo();        //��ʾͼ���嵥
void ShowReaderInfo();      //��ʾ�����嵥
int CheckToFloat(char * );  //�������ļ۸��Ƿ�Ϸ�
float ConvertToFloat(char * );//ͼ��۸��ַ���ת��Ϊ������
int IsBorrow(char *);       //�ж�ͼ���Ƿ��ڽ�
int IsBorrowed(char *);     //ͳ�ƶ����ڽ�ͼ�����
void BookBorrow();          //����
void BookReturn();          //����
void SearchBook();          //ͼ���ѯ
void SearchReader();        //���߲�ѯ
int GetPosition(char *,struct BookInfo *);      //�޸�ͼ����Ϣ
int GetRdPosition(char *,struct ReaderInfo *);  //�޸Ķ�����Ϣ
int InvalidBookPosition();  //��ѯ��һ����Чͼ����Ϣ��λ��
int InvalidReaderPosition();//��ѯ��һ����Ч���ߵ���Ϣ��λ��
void ShowAReader(char *);   //��ʾָ����ŵĶ�����ϸ��Ϣ

struct BookInfo
{
    char BookCode[6];       //ͼ����
    char BookName[30];      //����
    char BookAuthor[20];    //����
    float BookPrice;        //�۸�
    char BookPress[50];     //������
    char PublicationDate[8];//��������
    char ISBN[18];          //ISBN��
    char BookStatus;        //ͼ�����״̬
    char ReaderCode[6];     //���߱��
    char IsAvailable;       //ͼ���Ƿ���Ч
};
//���߽ṹ����
struct ReaderInfo
{
    char ReaderCode[6];     //���߱��
    char ReaderName[20];    //��������
    char Sex[3];            //�����Ա�
    char IsAvailable;       //�����Ƿ���Ч
};

int MainMenu()              //һ���˵�
{
    int m,k;
    while(1)
    {
        printf("\n        ���˵�\n");
        printf("            ----------------\n");
        printf("             1.ͼ����Ϣ����\n");
        printf("             2.������Ϣ����\n");
        printf("             3.ͼ������\n");
        printf("             4.ͳ�Ʋ�ѯ\n");
        printf("             0.�˳�ϵͳ\n");
        printf("��ѡ��0~4��: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=4 && k==1)
        {
            break;
        }else{
            printf("\n ѡ�����������ѡ��\n");
        }
    }
    return m;
}
int CreateSubMenu1()        //�����˵� ͼ����Ϣ����
{
    int m,k;
    while (1)
    {
        printf("             ͼ����Ϣ����\n");
        printf("            ----------------\n");
        printf("             1.����ͼ����Ϣ\n");
        printf("             2.�޸�ͼ����Ϣ\n");
        printf("             3.ɾ��ͼ����Ϣ\n");
        printf("             0.������һ���˵�\n");
        printf("��ѡ��0~3��: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=3 && k==1)
        {
            break;
        }else{
            printf("\n ѡ�����������ѡ��\n");
        }
    }
    return m;
}
int CreateSubMenu2()        //�����˵� ������Ϣ����
{
    int m,k;
    while (1)
    {
        printf("             ������Ϣ����\n");
        printf("            ----------------\n");
        printf("             1.����������Ϣ\n");
        printf("             2.�޸Ķ�����Ϣ\n");
        printf("             3.ɾ��������Ϣ\n");
        printf("             0.������һ���˵�\n");
        printf("��ѡ��0~3��: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=3 && k==1)
        {
            break;
        }else{
            printf("\n ѡ�����������ѡ��\n");
        }
    }
    return m;
}
int CreateSubMenu3()        //�����˵� ͼ�����
{
    int m,k;
    while (1)
    {
        printf("             ͼ����ͨ\n");
        printf("            ----------------\n");
        printf("             1.����\n");
        printf("             2.����\n");
        printf("             0.������һ���˵�\n");
        printf("��ѡ��0~2��: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=2 && k==1)
        {
            break;
        }else{
            printf("\n ѡ�����������ѡ��\n");
        }
    }
    return m;
}
int CreateSubMenu4()        //�����˵� ������Ϣ����
{
    int m,k;
    while (1)
    {
        printf("             ͳ�Ʋ�ѯ\n");
        printf("            ----------------\n");
        printf("             1.ͼ���嵥\n");
        printf("             2.�����嵥\n");
        printf("             3.ͼ���ѯ\n");
        printf("             4.���߲�ѯ\n");
        printf("             0.������һ���˵�\n");
        printf("��ѡ��0~4��: ");
        k= scanf("%d",&m);
        flushall();
        if(m>=0 && m<=4 && k==1)
        {
            break;
        }else{
            printf("\n ѡ�����������ѡ��\n");
        }
    }
    return m;
}

void main()
{
    system("mode con cols=120 lines=30");//���ڿ�ȣ��߶�
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
    printf("     **    ͼ����Ϣ����ϵͳ    **\n");
    printf("     **                     **\n");
    printf("     *************************\n");
    printf("\n ���м�¼���� ͼ��%d ��  ���� %d ��\n",CountBook(),CountReader());
}

int CountBook()             //ͳ������ͼ����������Чͼ�飩
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

int CountReader()           //ͳ�����ж�����������Ч���ߣ�
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

void SubMenu1()             //ͼ����Ϣ����
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

void SubMenu2()             //������Ϣ����
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

void SubMenu3()             //ͼ�����
{
    int MenuId;
    while (1)
    {
        MenuId=CreateSubMenu3();
        if (MenuId==0)
            break;
        switch (MenuId) {
            case 1:BookBorrow();break;  //����
            case 2:BookReturn();break;  //����
            case 0:MainMenu();break;
        }
    }
}

void  SubMenu4()            //��Ϣ��ѯ
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

//���ܣ�����һ��ͼ����Ϣ��¼
void AddBookInfo()
{
    struct BookInfo MyBook;
    char BookPrice[20];
    printf("\n����ͼ����Ϣ������ʾ������Ϣ��\n");
    printf("ͼ���ţ�");
    gets(MyBook.BookCode);
    while(IsBookExist(MyBook.BookCode))
    {
        printf("������ͼ����%s�Ѵ��ڣ����������룡\n",MyBook.BookCode);
        printf("ͼ���ţ�");
        gets(MyBook.BookCode);
    }
    printf("������");
    gets(MyBook.BookName);
    printf("���ߣ�");
    gets(MyBook.BookAuthor);
    printf("�۸�");
    while(!CheckToFloat(gets(BookPrice)))     //����ļ۸��ַ����Ƿ���ȷ
    {
        printf("����ļ۸񲻺Ϸ�����������\n");
        printf("�۸�");
    }
    MyBook.BookPrice= ConvertToFloat(BookPrice);    //���������ַ���ת��Ϊ������
    printf("�����磺");
    gets(MyBook.BookPress);
    printf("ISBN :");
    gets(MyBook.ISBN);
    printf("�������� ��");
    gets(MyBook.PublicationDate);
    MyBook.BookStatus='0';
    strcpy(MyBook.ReaderCode,'0');
    MyBook.IsAvailable='1';             //����ͼ�飬Ĭ����Ч

    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    //��ѯд���ļ�λ��
    int SetPs;
    SetPs=InvalidBookPosition();
    if(SetPs==-1)               //ͼ���¼�в�������Чͼ�飬�ļ�ָ�붨λ���ļ�β
    {
        fseek(fp,0,SEEK_END);
    }else{
        fseek(fp,(long)BOOKLEN*SetPs,SEEK_SET); //�ض�λд����ʼλ��
    }
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("����ͼ��ɹ�������ͼ��%d�� \n",CountBook());
    flushall();
    getchar();
}

//���ܣ��޸�ͼ����Ϣ
void ModifyBookInfo()
{
    struct BookInfo MyBook;
    char ModifyBookCode[6];
    if(CountBook()==0)
    {
        printf("����û��ͼ����Ϣ���޷�ִ����Ϣ��\n");
        return;
    }
    printf("\n---�޸�ͼ����Ϣ---\n");
    printf("����Ҫ�޸ĵ�ͼ���ţ�");
    gets(ModifyBookCode);
    if (!IsBookExist(ModifyBookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n",ModifyBookCode);
        return ;
    }
    int ModiPosition=0;     //Ҫ�޸�ͼ�����ļ��е�λ��
    //���ݽṹ����MyBook�ĵ�ַ�����Ҫ�޸ĵ�ͼ����Ϣ���洢��MyBook�ṹ��
    //ͼ����Ϣ�е�ͼ���š����ĵ�״̬���Ƿ���Ч��
    //��Ϣ�����޸�
    ModiPosition= GetPosition(ModifyBookCode,&MyBook);
    printf("��������ʾ���Ϊ%s��ͼ����Ϣ\n",ModifyBookCode);
    printf("������");
    gets(MyBook.BookName);
    printf("���ߣ�");
    gets(MyBook.BookAuthor);
    char BookPrice[20];
    printf("�۸�");
    while(!CheckToFloat(gets(BookPrice)))     //����ļ۸��ַ����Ƿ���ȷ
    {
        printf("����ļ۸񲻺Ϸ������������룡\n");
        printf("�۸�");
    }
    MyBook.BookPrice= ConvertToFloat(BookPrice);    //���������ַ���ת��Ϊ������
    printf("�����磺");
    gets(MyBook.BookPress);
    printf("ISBN :");
    gets(MyBook.ISBN);
    printf("�������ڣ�");
    gets(MyBook.PublicationDate);
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    //д���ļ�����ԭ��ͼ����Ϣ�洢λ�ø���д���޸���Ϣ
    fseek(fp,(long)BOOKLEN*ModiPosition,SEEK_SET);      //�ض�λд����ʼλ��
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("�޸�ͼ����Ϣ�ɹ� \n");
    flushall();
    getchar();
}

//���ܣ�ɾ��ͼ���¼
void DelBookInfo()
{
    char DelBookCode[6];
    if (CountBook()==0)
    {
        printf("����û��ͼ����Ϣ���޷�ִ��ɾ��!\n");
        return ;
    }
    printf("\n---ɾ��ͼ����Ϣ---\n");
    printf("����Ҫɾ��ͼ����Ϣ�ı�ţ�");
    gets(DelBookCode);
    if (!IsBookExist(DelBookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n",DelBookCode);
        return;
    }
    //��ͼ���ڽ��ڽ��в���ִ��ɾ������
    if (IsBorrow(DelBookCode))
    {
        printf("���Ϊ%s��ͼ���ѱ����ģ�����ɾ����\n",DelBookCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    //ɾ��ͼ�飬��IsAvailable��Ա��Ϊ'0'
    struct BookInfo MyBook;
    int ModiPosition=0;
    ModiPosition= GetPosition(DelBookCode,&MyBook);
    MyBook.IsAvailable='0';
    fseek(fp,(long)BOOKLEN*ModiPosition,SEEK_SET);      //�ض�λд����ʼλ��
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("ɾ��ͼ���¼�ɹ�������ͼ��%d��\n",CountBook());
}

//���ܣ�����
void BookBorrow()
{
    char BookCode[6];
    char ReaderCode[6];
    if(CountBook()==0||CountReader==0)
    {
        printf("����û��ͼ��������Ϣ���޷�ִ�н��Ĳ�����\n");
        return;
    }
    printf("\n---����---\n");
    printf("����ͼ����룺");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("����ʧ�ܣ����Ϊ%s��ͼ�鲻���ڣ�\n",BookCode);
        return;
    }
    if (IsBorrow(BookCode))
    {
        printf("����ʧ�ܣ����Ϊ%s��ͼ���Խ����\n",BookCode);
        return;
    }
    printf("������߱��룺");
    gets(ReaderCode);
    if(!IsReaderExist(ReaderCode))
    {
        printf("����ʧ�ܣ����Ϊ%s�Ķ��߲����ڣ�\n",ReaderCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        return;
    }
    //����
    //1.��ͼ��״̬Book Status��Ϊ��1��
    //2.��ͼ��Reader Code��Ϊ���߱��
    //3.������Ա��Ϣ���ֲ���
    int Position=0;         //�޸�ͼ�����ļ��е�λ��
    struct BookInfo MyBook;
    Position = GetPosition(BookCode,&MyBook);
    MyBook.BookStatus='1';
    strcpy(MyBook.ReaderCode,&MyBook);
    fseek(fp,(long)BOOKLEN*Position,SEEK_SET);      //�ض�λд����ʼλ��
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("ͼ����ĳɹ�!\n");
    flushall();
    getchar();
}

//���ܣ�����
void BookReturn()
{
    char BookCode[6];
    char ReaderCode[6];
    if(CountBook()==0||CountReader==0)
    {
        printf("����û��ͼ��������Ϣ���޷�ִ�н��Ĳ�����\n");
        return;
    }
    printf("\n---����---\n");
    printf("����ͼ����룺");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("����ʧ�ܣ����Ϊ%s��ͼ�鲻���ڣ�\n",BookCode);
        return;
    }
    if (IsBorrow(BookCode))
    {
        printf("����ʧ�ܣ����Ϊ%s��ͼ���Խ����\n",BookCode);
        return;
    }
    FILE *fp;
    if ((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        return;
    }
    //����
    //1.��ͼ��״̬Book Status��Ϊ��0��
    //2.��ͼ��Reader Code��Ϊ��0��
    //3.������Ա��Ϣ���ֲ���
    int Position=0;         //�޸�ͼ�����ļ��е�λ��
    struct BookInfo MyBook;
    Position = GetPosition(BookCode,&MyBook);
    MyBook.BookStatus='0';
    strcpy(MyBook.ReaderCode,'0');
    fseek(fp,(long)BOOKLEN*Position,SEEK_SET);      //�ض�λд����ʼλ��
    fwrite(&MyBook,BOOKLEN,1,fp);
    fclose(fp);
    printf("����ɹ�!\n");
    flushall();
    getchar();
}

//���ܣ���ʾ����ͼ����Ϣ
void ShowBookInfo()
{
    struct BookInfo MyBookInfo;
    int booknum=CountBook();
    if(booknum==0){
        printf("����û��ͼ����Ϣ��\n");
        return;
    }
    FILE *fp;
    if((fp= fopen("bookinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    printf("\n ���    ����          ����     �۸�   ������   ��������\n");
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

//���ܣ���ʾָ����ŵ�ͼ����Ϣ
void SearchBook()   //ͼ���ѯ
{
    char BookCode[6];
    if(CountBook()==0)
    {
        printf("����û��ͼ����Ϣ���޷�ִ�в�ѯ��\n");
        return ;
    }
    printf("\n--��ѯͼ����Ϣ--\n");
    printf("�����ѯ��ͼ���ţ�");
    gets(BookCode);
    if(!IsBookExist(BookCode))
    {
        printf("���Ϊ%s��ͼ�鲻���ڣ���˲飡\n",BookCode);
        return ;
    }
    struct BookInfo MyBook;
    GetPosition(BookCode,&MyBook);
    printf("���Ϊ%s��ͼ����ϸ��Ϣ\n",MyBook.BookCode);
    printf("-----------------------\n");
    printf("   ������ \t%s\n",MyBook.BookName);
    printf("   ���ߣ� \t%s\n",MyBook.BookAuthor);
    printf("   �۸� \t%.2f\n",MyBook.BookPrice);
    printf("   �����磺 \t%s\n",MyBook.BookPress);
    printf("   �������ڣ� \t%s\n",MyBook.PublicationDate);
    printf("   ISBN�� \t%s\n",MyBook.ISBN);
    if (MyBook.BookStatus=='1')     //��ͼ���ѽ��������ʾ���ĵĶ�����Ϣ
    {
        ShowAReader(MyBook.ReaderCode);
    } else{
        printf("  ����δ������\n");
    }
}

//����:��ʾ������Ϣ
void SearchReader()
{
    char ReaderCode[6];
    if(CountReader()==0)
    {
        printf("����û�ж�����Ϣ���޷�ִ�в�ѯ��\n");
        return;
    }
    printf("\n--��ѯ������Ϣ--\n");
    printf("�����ѯ�Ķ��߱�ţ�");
    gets(ReaderCode);
    if (!IsReaderExist(ReaderCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n",ReaderCode);
        return;
    }
    printf("---------------------\n");
    ShowAReader(ReaderCode);
    int BorrowCount= IsBorrowed(ReaderCode);
    if (BorrowCount==0)
    {
        printf("  �ö���δ����ͼ��\n");
    }else{
        printf("  �ö��߹�����%d��ͼ�飬��Ϣ���£�\n",BorrowCount);
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
                printf("   %d ��  %-6s%s (%s) \n",i,MyBook.BookCode,MyBook.BookName,MyBook.BookAuthor);
            }
        }
        fclose(fp);
    }
}

//���ܣ���ʾָ����ŵĶ��ߵ���ϸ��Ϣ
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
    printf("  ���Ķ��ߣ�\t%s (%s-%s) \n",ReaderCode,MyReader.ReaderName,MyReader.Sex);
    fclose(fp);
}

//���ܣ���ѯ��һ����Ч��ͼ���¼���ļ���λ��

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

//���ܣ���ѯָ����ͼ�����ļ����Ƿ����
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

//���ܣ��ж�ͼ���Ƿ񱻽�
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

//���ܣ���ô��޸��ĵ�ͼ���¼���ļ��е�λ��
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

//���ܣ����Ӷ�����Ϣ
void AddReaderInfo()
{
    struct ReaderInfo MyReader;
    printf("\n ���Ӷ�����Ϣ ������ʾ������Ϣ��\n");
    printf("���߱�ţ�<=5���ַ�����");
    gets(MyReader.ReaderCode);
    while(IsReaderExist(MyReader.ReaderCode))
    {
        printf("���Ӷ��߱��%s�Ѿ����ڣ����������룡\n",MyReader.ReaderCode);
        printf("���߱�� ��<=5���ַ�����");
        gets(MyReader.ReaderCode);
    }
    printf("����������");
    gets(MyReader.ReaderName);
    printf("�Ա�");
    gets(MyReader.Sex);
    MyReader.IsAvailable='1';
    FILE *fp;
    if ((fp=fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    //��ѯд���ļ�λ��
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
    printf("���Ӷ��߳ɹ������ж���%d��\n",CountReader());
    flushall();
    getchar();
}

//���ܣ��޸Ķ�����Ϣ
void ModifyReaderInfo()
{
    struct ReaderInfo MyReader;
    char ModifyCode[6];
    if (CountReader()==0)
    {
        printf("����û�ж�����Ϣ���޷�ִ���޸ģ�\n");
        return;
    }
    printf("\n--�޸Ķ�����Ϣ--\n");
    printf("�������޸ĵĶ��߱�ţ�");
    gets(ModifyCode);
    if (!IsReaderExist(ModifyCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n",ModifyCode);
        return;
    }
    int ModiPosition=0;
    ModiPosition= GetRdPosition(ModifyCode,&MyReader);
    printf("��������ʾ������Ϊ%s�Ķ�����Ϣ\n",ModifyCode);
    printf("����������");
    gets(MyReader.ReaderName);
    printf("�Ա�");
    gets(MyReader.Sex);
    FILE * fp;
    if ((fp= fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    fseek(fp,(long)READERLEN*ModiPosition,SEEK_SET);
    fwrite(&MyReader, READERLEN,1,fp);
    fclose(fp);
    printf("�޸Ķ�����Ϣ�ɹ�\n");
    flushall();
    getchar();
}

//���ܣ�ɾ��һ�����߼�¼
void DelReaderInfo()
{
    char DelCode[6];
    if (CountReader()==0)
    {
        printf("����û�ж�����Ϣ���޷�ִ��ɾ����\n");
        return;
    }
    printf("\n--ɾ��������Ϣ--\n");
    printf("������ɾ�����ߵı�ţ�");
    gets(DelCode);
    if (!IsReaderExist(DelCode))
    {
        printf("���Ϊ%s�Ķ��߲����ڣ���˲飡\n",DelCode);
        return ;
    }
    int BorrowedNum;
    BorrowedNum= IsBorrowed(DelCode);
    if (BorrowedNum)
    {
        printf("���Ϊ%s�Ķ�����%d��ͼ��δ��������ɾ����\n",DelCode,BorrowedNum);
        return;
    }
    FILE *fp;
    if ((fp= fopen("readerinfo.dat","rb+"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    //ɾ��������Ϣ
    struct ReaderInfo MyReader;
    int ModiPosition=0;
    ModiPosition=GetRdPosition(DelCode,&MyReader);
    MyReader.IsAvailable='0';
    fseek(fp,(long)READERLEN*ModiPosition,SEEK_SET);
    fwrite(&MyReader,READERLEN,1,fp);
    fclose(fp);
    printf("ɾ��������Ϣ��¼�ɹ������ж���%��\n",CountReader());
}

//���ܣ��ж϶����Ƿ��н���ͼ��δ�黹
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

//���ܣ���ô��޸ĵĶ��߼�¼���ļ��е�λ��
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

//���ܣ���ѯ�����Ƿ����
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

//���ܣ���ѯ��һ����Ч���߼�¼��λ��
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

//���ܣ���ʾ���ж�����Ϣ
void ShowReaderInfo()
{
    struct ReaderInfo MyReader;
    int ReaderNum=CountReader();
    if (ReaderNum==0)
    {
        printf("����û�ж�����Ϣ��\n");
        return;
    }
    FILE *fp;
    if ((fp=fopen("readerinfo.dat","rb"))==NULL)
    {
        printf("���ļ�����\n");
        exit(0);
    }
    printf("\n���      ����      �Ա� \n");
    printf("---------------------------\n");
    while(fread(&MyReader,READERLEN,1,fp))
    {
        if (MyReader.IsAvailable=='1'){
            printf("%-7s%-11s%-5s\n",MyReader.ReaderCode,MyReader.ReaderName,MyReader.Sex);
        }
    }
    fclose(fp);
}

//���ܣ��ж�����ͼ��۸��Ƿ���ȷ
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

//���ܣ������������͵��ַ���ת��Ϊ������
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

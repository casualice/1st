#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disk{
    char AN[10];            /*登录号*/
    char name[20];          /*影碟名*/
    char type[20];          /*影片类型*/
    char save[10];          /*库存*/
    char company[20];       /*电影公司*/
    char date[20];          /*出版时间*/
    char price[10];         /*价格*/
    struct disk *next;
}list,*Pointer;

int num=0;//全局变量的定义
Pointer Head=NULL;//头指针为空
FILE *fp;//指向文件的指针

int menu();/*主菜单函数*/
void Insert(Pointer * Head);/*录入函数*/
void Scan(Pointer Head);/*显示函数*/
void Search(Pointer Head);/*按影片名查找函数*/
void Delete(Pointer * Head);//删除函数
void Update(Pointer Head);//修改函数
void Save();//用文本文件形式保存函数
void Read();//读入文本文件函数
void Exit();//退出函数

void main(){//主函数
    system("cls");/*运行前清屏*/
    for(;;){
        switch(menu()){
        case 1:Insert(& Head);
            break;
        case 2:Scan(Head);
            break;
        case 3:Search(Head);
            break;
        case 4:Delete(&Head);
            break;
        case 5:Update(Head);
            break;
        case 6:Read();
            break;
        case 0:Exit();
        default:
            putchar('\0');
        }
    }
}

menu()//主菜单函数
{
    int a;
    printf("\n\t\t\t欢迎使用影碟信息管理系统\n\n\n\n\n\t\t        请按任意键进入系统菜单! \n");
    getch();
    system("cls");
    printf("\t\t    1. 录入影碟信息\n");
    printf("\t\t    2. 浏览影碟信息\n");
    printf("\t\t    3. 按名查询影碟信息\n");
    printf("\t\t    4. 删除影碟信息\n");
    printf("\t\t    5. 修改影碟信息\n");
    printf("\t\t    6. 影碟信息文件打开\n");
    printf("\t\t    0. 退出\n");
    do{
        printf("\n\t请选择您所需要的服务：");
        scanf("%d",&a);
    }while (a<0||a>6);
    return a;
}

void Insert(Pointer *Head)  //录入信息函数
{
    char AN[10] ;
    char c;
    Pointer p,q,r;
    printf("\n\t\t请输入影碟信息 \n");/*交互输入*/
    printf("\n\t\t请输入登录号:");
    scanf("%s",AN);
    p=q=*Head;//检测登录号是否重复
    while(p!=NULL){
        if(strcmp(p->AN,AN)==0)//检测登录号是否重复
        {
            printf ("已经有相同的登录号：");
            return;
        }
        else{
            q=p;
            p=p->next;
        }
    }
    r=(Pointer)malloc(sizeof(list));
    r->next=NULL;
    if(r==NULL){
        printf("分配空间失败!");
        return;
    }
    if(q==NULL)
        *Head=r;
    else{
        q->next=r;
    }
    strcpy(r->AN,AN);
    printf("\n\t\t输入影碟名:");
    scanf("%s",r->name);
    getchar();
    printf("\n\t\t输入影片类型:");
    scanf("%s",r->type);
    getchar();
    printf("\n\t\t输入库存:");
    scanf("%s",r->save) ;
    getchar();
    printf("\n\t\t输入电影公司:");
    scanf("%s",r->company);
    getchar();
    printf("\n\t\t输入发行日期:");
    gets(r->date);
    printf("\n\t\t输入价格:");
    scanf("%s",r->price);
    do{
        printf("\n\t\t录入成功!!!!");
        num++;
        printf("选择是否继续录入(Y/N)?：");
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Insert(Head);
        else {
            if(c=='n'||c=='N')
            return;
            else
                printf("\n\t\t输入错误，请重新输入!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');
}

void Scan(Pointer Head)
{
    Pointer p;
    p=Head;
    if(p==NULL)
        printf("记录为空");
    else{
        printf("\n\t共有%d条记录",num);
        while(p!=NULL){
            printf("\n\n\t\t登录号：%-10s",p->AN);
            printf("\n\t\t影碟名：    %-20s",p->name);
            printf("\n\t\t类型：  %-20s",p->type);
            printf("\n\t\t库存：  %-10s",p->save);
            printf("\n\t\t电影公司：%-20s",p->company);
            printf("\n\t\t出版时间：%-20s",p->date);
            printf("\n\t\t价格：    ￥%-10s",p->price);
            if(num == 1)
                return;
            else
                p=p->next;
        }
        printf("\n\t\t请按任意键回到主菜单");
        return;
    }
}

void Search(Pointer Head)  //按书名查找函数
{
    int flag=0;//标记变量的初值
    char name[10];
    Pointer p;
    printf ("\n请输入需要查询的影碟名：");
    scanf("%s",name);
    printf("以下是您查找的信息：\n");
    p=Head;
    while(p!=NULL){
        if(strcmp(p->name,name)==0)//查找符合的图书
        {
            printf("\n\t登录号：  %-10s",p->AN);
            printf("\n\t影碟名：    %-20s",p->name);
            printf("\n\t类型：  %-20s",p->type);
            printf("\n\t库存：  %-10s",p->save);
            printf("\n\t电影公司：%-20s",p->company);
            printf("\n\t出版时间：%-20s",p->date);
            printf("\n\t价格：    ￥%-10s",p->price);
            flag=1;//找到标记变量设为1
            p=p->next;//指针走到下一个节点
        }
        else
            p=p->next;
    }
    if(flag==0)
        printf("\n\t\t\t无对应纪录\n");
    getchar();
}

void Delete(Pointer *Head)/*删除函数*/
{
    int flag=1;
    char AN[10];
    char c,z;
    Pointer p,q;
    printf("\t请输入要删除影碟的信息的登录号：");
    scanf("%s",AN);
    p=q=*Head;/*查找符合条件的图书*/
    while(p!=NULL&&flag){
        if(strcmp(p->AN,AN)==0)/*找到该图书*/
        {
            printf("\t\n登录号：%-10s",p->AN);//显示即将要删除的图书的信息
            printf("\t\n影碟名：%-20s",p->name);
            printf("\t\n影片类型：%-20s",p->type);
            printf("\t\n库存：%-10s",p->save);
            printf("\t\n电影公司：%-20s",p->company);
            printf("\t\n出版时间：%-20s",p->date);
            printf("\t\n价格：￥%-10s\n",p->price);
            printf("确定删除?确定请输Y，其它则不删除");//询问是否删除
            getchar();
            scanf("%c",&z);
            if(z=='Y'||z=='y'){
                    if(p==*Head){
                        *Head=p->next;
                        free(p);
                    }/*删除图书信息*/
                    else{
                        q->next=p->next;
                        free(p);
                    }
                    flag=0;
            }
            else{
                printf("影碟信息未删除，返回主菜单。");
                return;
            }
        }
        else{
            q=p;
            p=p->next;
        }/*指针走到下一个节点*/
        printf("\t\t删除成功！！！\n");
    }
    if(flag)
    printf("\t没有找到可以删除的数据!!!");
    do{
        printf("选择是否继续删除(Y/N)?：");
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Delete(Head);/*继续删除*/
        else{
            if(c=='n'||c=='N')
                return;/*不删除返回主菜单*/
            else
                printf("\n\t\t输入错误，请重新输入!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');
}

void Update(Pointer Head)/*图书信息修改函数*/
{
    int flag=1;
    char AN[10];
    char c;
    Pointer p;
    printf("\t请输入要修改的影碟的登录号：");
    scanf("%s",AN);
    p=Head;
    while(p!=NULL&&flag){
        if(strcmp(p->AN,AN)==0){
            printf("\n\t\t请输入登录号:");/*修改影碟信息*/
            scanf("%s",p->AN);
            printf("\n\t\t输入影碟名:");
            scanf("%s",p->name);
            getchar();
            printf("\n\t\t输入影片类型:");
            scanf("%s",p->type);
            getchar();
            printf("\n\t\t输入库存:");
            scanf("%s",p->save) ;
            getchar();
            printf("\n\t\t输入电影公司:");
            scanf("%s",p->company) ;
            getchar();
            printf("\n\t\t输入出版日期:");
            gets(p->date);
            printf("\n\t\t输入价格:");
            scanf("%s",p->price);
            flag=0;
            printf("修改成功!!\n");
        }
        else
            p=p->next;/*指针走到下一个节点*/
    }
    if(flag)
        printf("\n\t\t没有该影碟记录!");
    do{
        printf("选择是否继续修改(Y/N)?：");     /*连续修改影碟信息*/
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Update(Head);/*继续修改*/
        else{
            if(c=='n'||c=='N')
                return;//不修改，返回菜单
            else
                printf("\n\t\t输入错误，请重新输入!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');//输入错误则继续询问
}

void Exit()/*退出程序的函数*/
{
    char c;
    do{
        printf("\n\t\t退出中......是否保存到文件(Y/N)?"); /*询问是否保存影碟信息，防止丢失*/
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y'){
            Save();
            exit(0);
        }
        else{
            if(c=='n'||c=='N'){
                exit(0);
            }
            else
                printf("\n\t\t输入错误，请重新输入!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');//错误则继续询问
}

void Save()             /*以文本文件形式保存的函数*/
{
    Pointer p;
    p=Head;
    char file[20];    /*用来存放文件保存路径以及文件名*/
    printf("请输入文件路径及文件名:");
    scanf("%s",file);
    if((fp=fopen(file,"w+"))==NULL)/*判断能否打开文件*/
    {
        printf("不能打开文件!\n");
        return;
    }
    while(p!=NULL){
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->AN,p->name,p->type,p->save,p->company,p->date,p->price);//将数据写入文件
        p=p->next;/*下移一个结点*/
    }
    fclose(fp);//写入完成，关闭文件
    printf("文件已经保存!\n");
    return ;
}

void Read()/*读入文本文件的函数*/
{
    Pointer p,q;
    int m=0;
    char file[20],c;
    num = 0;
    printf("请输入文件路径及文件名:");
    scanf("%s",file);/*输入文件路径及名称*/
    if((fp=fopen(file,"r+"))==NULL)//检查文件是否存在
    {
        printf("不能打开文件!\n");
        return;
    }
    m=m+1;
    if(m==1){
        p=(Pointer)malloc(sizeof(list));/*开辟一个新单元*/
        Head=p;//将p的地址赋给头指针Head
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",&p->AN,&p->name,&p->type,&p->save,&p->company,&p->date,&p->price);/*文件读入*/
        if((c=fgetc(fp)) == EOF){
            printf("已读取，文件中仅1条信息");
            num=1;
            p->next = NULL;
            return;
        }
        while(!feof(fp)){
            num=num+1;//记录影碟信息量
            if(num==1) //区别开链表开头与中间的处理方法
                Head->next=p;
            else q->next=p;
                q=p;
            p=(Pointer)malloc(sizeof(list)); /*开辟一个新单元*/
            fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",&p->AN,&p->name,&p->type,&p->save,&p->company,&p->date,&p->price);//读入文件数据
        }//检查文件是否结束，若是则停止读入，否则继续读入
        q->next=p;
        p->next=NULL;//链表结尾处理
        num=num+1;//正确的影碟信息量
    }
    printf("写入数据成功，可返回浏览其信息。");
    fclose(fp);/*结束读入，关闭文件*/
    return;
}

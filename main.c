#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct disk{
    char AN[10];            /*��¼��*/
    char name[20];          /*Ӱ����*/
    char type[20];          /*ӰƬ����*/
    char save[10];          /*���*/
    char company[20];       /*��Ӱ��˾*/
    char date[20];          /*����ʱ��*/
    char price[10];         /*�۸�*/
    struct disk *next;
}list,*Pointer;

int num=0;//ȫ�ֱ����Ķ���
Pointer Head=NULL;//ͷָ��Ϊ��
FILE *fp;//ָ���ļ���ָ��

int menu();/*���˵�����*/
void Insert(Pointer * Head);/*¼�뺯��*/
void Scan(Pointer Head);/*��ʾ����*/
void Search(Pointer Head);/*��ӰƬ�����Һ���*/
void Delete(Pointer * Head);//ɾ������
void Update(Pointer Head);//�޸ĺ���
void Save();//���ı��ļ���ʽ���溯��
void Read();//�����ı��ļ�����
void Exit();//�˳�����

void main(){//������
    system("cls");/*����ǰ����*/
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

menu()//���˵�����
{
    int a;
    printf("\n\t\t\t��ӭʹ��Ӱ����Ϣ����ϵͳ\n\n\n\n\n\t\t        �밴���������ϵͳ�˵�! \n");
    getch();
    system("cls");
    printf("\t\t    1. ¼��Ӱ����Ϣ\n");
    printf("\t\t    2. ���Ӱ����Ϣ\n");
    printf("\t\t    3. ������ѯӰ����Ϣ\n");
    printf("\t\t    4. ɾ��Ӱ����Ϣ\n");
    printf("\t\t    5. �޸�Ӱ����Ϣ\n");
    printf("\t\t    6. Ӱ����Ϣ�ļ���\n");
    printf("\t\t    0. �˳�\n");
    do{
        printf("\n\t��ѡ��������Ҫ�ķ���");
        scanf("%d",&a);
    }while (a<0||a>6);
    return a;
}

void Insert(Pointer *Head)  //¼����Ϣ����
{
    char AN[10] ;
    char c;
    Pointer p,q,r;
    printf("\n\t\t������Ӱ����Ϣ \n");/*��������*/
    printf("\n\t\t�������¼��:");
    scanf("%s",AN);
    p=q=*Head;//����¼���Ƿ��ظ�
    while(p!=NULL){
        if(strcmp(p->AN,AN)==0)//����¼���Ƿ��ظ�
        {
            printf ("�Ѿ�����ͬ�ĵ�¼�ţ�");
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
        printf("����ռ�ʧ��!");
        return;
    }
    if(q==NULL)
        *Head=r;
    else{
        q->next=r;
    }
    strcpy(r->AN,AN);
    printf("\n\t\t����Ӱ����:");
    scanf("%s",r->name);
    getchar();
    printf("\n\t\t����ӰƬ����:");
    scanf("%s",r->type);
    getchar();
    printf("\n\t\t������:");
    scanf("%s",r->save) ;
    getchar();
    printf("\n\t\t�����Ӱ��˾:");
    scanf("%s",r->company);
    getchar();
    printf("\n\t\t���뷢������:");
    gets(r->date);
    printf("\n\t\t����۸�:");
    scanf("%s",r->price);
    do{
        printf("\n\t\t¼��ɹ�!!!!");
        num++;
        printf("ѡ���Ƿ����¼��(Y/N)?��");
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Insert(Head);
        else {
            if(c=='n'||c=='N')
            return;
            else
                printf("\n\t\t�����������������!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');
}

void Scan(Pointer Head)
{
    Pointer p;
    p=Head;
    if(p==NULL)
        printf("��¼Ϊ��");
    else{
        printf("\n\t����%d����¼",num);
        while(p!=NULL){
            printf("\n\n\t\t��¼�ţ�%-10s",p->AN);
            printf("\n\t\tӰ������    %-20s",p->name);
            printf("\n\t\t���ͣ�  %-20s",p->type);
            printf("\n\t\t��棺  %-10s",p->save);
            printf("\n\t\t��Ӱ��˾��%-20s",p->company);
            printf("\n\t\t����ʱ�䣺%-20s",p->date);
            printf("\n\t\t�۸�    ��%-10s",p->price);
            if(num == 1)
                return;
            else
                p=p->next;
        }
        printf("\n\t\t�밴������ص����˵�");
        return;
    }
}

void Search(Pointer Head)  //���������Һ���
{
    int flag=0;//��Ǳ����ĳ�ֵ
    char name[10];
    Pointer p;
    printf ("\n��������Ҫ��ѯ��Ӱ������");
    scanf("%s",name);
    printf("�����������ҵ���Ϣ��\n");
    p=Head;
    while(p!=NULL){
        if(strcmp(p->name,name)==0)//���ҷ��ϵ�ͼ��
        {
            printf("\n\t��¼�ţ�  %-10s",p->AN);
            printf("\n\tӰ������    %-20s",p->name);
            printf("\n\t���ͣ�  %-20s",p->type);
            printf("\n\t��棺  %-10s",p->save);
            printf("\n\t��Ӱ��˾��%-20s",p->company);
            printf("\n\t����ʱ�䣺%-20s",p->date);
            printf("\n\t�۸�    ��%-10s",p->price);
            flag=1;//�ҵ���Ǳ�����Ϊ1
            p=p->next;//ָ���ߵ���һ���ڵ�
        }
        else
            p=p->next;
    }
    if(flag==0)
        printf("\n\t\t\t�޶�Ӧ��¼\n");
    getchar();
}

void Delete(Pointer *Head)/*ɾ������*/
{
    int flag=1;
    char AN[10];
    char c,z;
    Pointer p,q;
    printf("\t������Ҫɾ��Ӱ������Ϣ�ĵ�¼�ţ�");
    scanf("%s",AN);
    p=q=*Head;/*���ҷ���������ͼ��*/
    while(p!=NULL&&flag){
        if(strcmp(p->AN,AN)==0)/*�ҵ���ͼ��*/
        {
            printf("\t\n��¼�ţ�%-10s",p->AN);//��ʾ����Ҫɾ����ͼ�����Ϣ
            printf("\t\nӰ������%-20s",p->name);
            printf("\t\nӰƬ���ͣ�%-20s",p->type);
            printf("\t\n��棺%-10s",p->save);
            printf("\t\n��Ӱ��˾��%-20s",p->company);
            printf("\t\n����ʱ�䣺%-20s",p->date);
            printf("\t\n�۸񣺣�%-10s\n",p->price);
            printf("ȷ��ɾ��?ȷ������Y��������ɾ��");//ѯ���Ƿ�ɾ��
            getchar();
            scanf("%c",&z);
            if(z=='Y'||z=='y'){
                    if(p==*Head){
                        *Head=p->next;
                        free(p);
                    }/*ɾ��ͼ����Ϣ*/
                    else{
                        q->next=p->next;
                        free(p);
                    }
                    flag=0;
            }
            else{
                printf("Ӱ����Ϣδɾ�����������˵���");
                return;
            }
        }
        else{
            q=p;
            p=p->next;
        }/*ָ���ߵ���һ���ڵ�*/
        printf("\t\tɾ���ɹ�������\n");
    }
    if(flag)
    printf("\tû���ҵ�����ɾ��������!!!");
    do{
        printf("ѡ���Ƿ����ɾ��(Y/N)?��");
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Delete(Head);/*����ɾ��*/
        else{
            if(c=='n'||c=='N')
                return;/*��ɾ���������˵�*/
            else
                printf("\n\t\t�����������������!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');
}

void Update(Pointer Head)/*ͼ����Ϣ�޸ĺ���*/
{
    int flag=1;
    char AN[10];
    char c;
    Pointer p;
    printf("\t������Ҫ�޸ĵ�Ӱ���ĵ�¼�ţ�");
    scanf("%s",AN);
    p=Head;
    while(p!=NULL&&flag){
        if(strcmp(p->AN,AN)==0){
            printf("\n\t\t�������¼��:");/*�޸�Ӱ����Ϣ*/
            scanf("%s",p->AN);
            printf("\n\t\t����Ӱ����:");
            scanf("%s",p->name);
            getchar();
            printf("\n\t\t����ӰƬ����:");
            scanf("%s",p->type);
            getchar();
            printf("\n\t\t������:");
            scanf("%s",p->save) ;
            getchar();
            printf("\n\t\t�����Ӱ��˾:");
            scanf("%s",p->company) ;
            getchar();
            printf("\n\t\t�����������:");
            gets(p->date);
            printf("\n\t\t����۸�:");
            scanf("%s",p->price);
            flag=0;
            printf("�޸ĳɹ�!!\n");
        }
        else
            p=p->next;/*ָ���ߵ���һ���ڵ�*/
    }
    if(flag)
        printf("\n\t\tû�и�Ӱ����¼!");
    do{
        printf("ѡ���Ƿ�����޸�(Y/N)?��");     /*�����޸�Ӱ����Ϣ*/
        getchar();
        scanf("%c",&c);
        if(c=='y'||c=='Y')
            Update(Head);/*�����޸�*/
        else{
            if(c=='n'||c=='N')
                return;//���޸ģ����ز˵�
            else
                printf("\n\t\t�����������������!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');//������������ѯ��
}

void Exit()/*�˳�����ĺ���*/
{
    char c;
    do{
        printf("\n\t\t�˳���......�Ƿ񱣴浽�ļ�(Y/N)?"); /*ѯ���Ƿ񱣴�Ӱ����Ϣ����ֹ��ʧ*/
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
                printf("\n\t\t�����������������!!!");
        }
    }while(c!='y'&&c!='n'&&c!='Y'&&c!='N');//���������ѯ��
}

void Save()             /*���ı��ļ���ʽ����ĺ���*/
{
    Pointer p;
    p=Head;
    char file[20];    /*��������ļ�����·���Լ��ļ���*/
    printf("�������ļ�·�����ļ���:");
    scanf("%s",file);
    if((fp=fopen(file,"w+"))==NULL)/*�ж��ܷ���ļ�*/
    {
        printf("���ܴ��ļ�!\n");
        return;
    }
    while(p!=NULL){
        fprintf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\n",p->AN,p->name,p->type,p->save,p->company,p->date,p->price);//������д���ļ�
        p=p->next;/*����һ�����*/
    }
    fclose(fp);//д����ɣ��ر��ļ�
    printf("�ļ��Ѿ�����!\n");
    return ;
}

void Read()/*�����ı��ļ��ĺ���*/
{
    Pointer p,q;
    int m=0;
    char file[20],c;
    num = 0;
    printf("�������ļ�·�����ļ���:");
    scanf("%s",file);/*�����ļ�·��������*/
    if((fp=fopen(file,"r+"))==NULL)//����ļ��Ƿ����
    {
        printf("���ܴ��ļ�!\n");
        return;
    }
    m=m+1;
    if(m==1){
        p=(Pointer)malloc(sizeof(list));/*����һ���µ�Ԫ*/
        Head=p;//��p�ĵ�ַ����ͷָ��Head
        fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",&p->AN,&p->name,&p->type,&p->save,&p->company,&p->date,&p->price);/*�ļ�����*/
        if((c=fgetc(fp)) == EOF){
            printf("�Ѷ�ȡ���ļ��н�1����Ϣ");
            num=1;
            p->next = NULL;
            return;
        }
        while(!feof(fp)){
            num=num+1;//��¼Ӱ����Ϣ��
            if(num==1) //��������ͷ���м�Ĵ�����
                Head->next=p;
            else q->next=p;
                q=p;
            p=(Pointer)malloc(sizeof(list)); /*����һ���µ�Ԫ*/
            fscanf(fp,"%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",&p->AN,&p->name,&p->type,&p->save,&p->company,&p->date,&p->price);//�����ļ�����
        }//����ļ��Ƿ������������ֹͣ���룬�����������
        q->next=p;
        p->next=NULL;//�����β����
        num=num+1;//��ȷ��Ӱ����Ϣ��
    }
    printf("д�����ݳɹ����ɷ����������Ϣ��");
    fclose(fp);/*�������룬�ر��ļ�*/
    return;
}



#include<stdio.h>

#include<stdlib.h>

#include<windows.h>

#include<string.h>

#include<conio.h>

typedef struct 
dog

{

    char
name[30];//名字 

    char
trait[40];//特点  

    char
size[40];//体积 

    char
effect[40];//作用 

    char
price[20];//价格 

    struct
dog *next;

}*Linklist,S;

void print(Linklist head);

void save(Linklist head)//写文件 

{

    FILE *fp;

    S *p;

    fp=fopen("D:\\ztks.txt","wt");

    if(fp==NULL)

    {

        printf("\n写文件出现了错误，按任意键退出！\n");

    //  getchar();

        getch();

        exit(1);


    }

    

       for(p=head->next;p->next!=NULL;p=p->next)

        fprintf(fp,"%s
%s %s %s
%s\n",p->name,p->trait,p->size,p->effect,p->price);

        fprintf(fp,"%s
%s %s %s
%s\n",p->name,p->trait,p->size,p->effect,p->price);

       //fflush(stdin);

       printf("\n文件已保存,请按任意键返回！\n");

    //getch();


    fclose(fp);

    

}

Linklist read()//读取文件 

{

    S
*head,*p,*r;

    FILE *fp;

    if((fp=fopen("D:\\ztks.txt","rt"))==NULL)

    {

        printf("\n读取的文件出现了错误，按任意键退出！\n");

    //  getchar();

        getch();

        exit(1);

    }

    head=(Linklist)malloc(sizeof(Linklist));

    head->next=NULL;

    r=head;

//  fflush(stdin);

    while(!feof(fp))

    {

        p=(S*)malloc(sizeof(S));

        fscanf(fp,"%s
%s %s %s %s",p->name,p->trait,p->size,p->effect,p->price);

        r->next=p;

        r=p;

    }

    r->next=NULL;

    fclose(fp);

    printf("\n文件读取成功，请按任意键退出！\n");

    //getch();

    return
head;

}

Linklist create()//创建 （含头结点） 

{

    S *head;

    S *p,*t;

    int n;

    head=(S*)malloc(sizeof(Linklist));

    head->next=NULL;

    p=head;

    system("cls");

    system("color
1A");

    printf("\t-------------------------------------------------\n");

    printf("\t|     ********添加狗狗管理信息********          |\n");

    printf("\t-------------------------------------------------\n");

    do

    {

        t=(S*)malloc(sizeof(S));

        printf("\t--------------输入狗狗的信息-------------------\n");

        printf("\n输入狗狗的名字:\n");

        scanf("%s",t->name);

        printf("\n输入狗狗的特点:\n");

        scanf("%s",t->trait);

        printf("\n输入狗狗的体积:\n");

        scanf("%s",t->size);

        printf("\n输入狗狗的作用:\n");

        scanf("%s",t->effect);

        printf("\n输入狗狗的价格:\n");

        scanf("%s",t->price);

        p->next=t;

        p=t;

        printf("\t----------是否继续录入信息(1/0)-------------\n");//1代表继续0代表结束    

        fflush(stdin);

        scanf("%d",&n);

    }while(n!=0);

    t->next=NULL;

    return
head;

}

void look(Linklist head)//查找 

{

    S *p;

    char
name2[40],name3[40];

    char
effect2[40],price1[40];

    char
effect1[40],size1[40];

    int m;

    int n;

    system("cls");

    system("color
2B");

    printf("\t-------------------------------------------------------\n");

    printf("\t|           ********查找狗狗管理信息********          |\n");

    printf("\t-------------------------------------------------------\n");

    do

    {

        int
change=0;

        p=head->next;

        printf("\t-----------------------------------------------------------\n");

        printf("\t|----------------------1.按名字查找-----------------------|\n");//一级查找


        printf("\t|---------------------
2.按作用查找-----------------------|\n");//一级查找 

        printf("\t|----------------------3.按价格和姓名查找-----------------|\n");//二级查找


        printf("\t|----------------------4.按作用和体积查找-----------------|\n");//二级查找


        printf("\t-----------------------------------------------------------\n");

        printf("\t******输入要查找的选项*******\n");

        scanf("%d",&n);

        system("pause");

        switch(n)

        {

            case
1://按名字查找 

                {

                   

                   system("cls");

                   system("color
2B");

                   printf("\n请输入要查找的狗狗的姓名\n");

                   scanf("%s",name2);

                   while(p!=NULL)

                   {

                       if(strcmp(name2,p->name)==0)

                        {

                           change=1;

                           printf("\n*********查找成功********\n");

                           system("pause");

                           system("cls");

                           printf("\n********狗狗的信息如下*********\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause") ;

                           system("cls");

                           break;

                       }

                       else

                       {

                           p=p->next;

                           if(p==NULL&&change==0)

                           {

                               printf("\t*******输入数据有误或者该只狗狗的信息不存在********\n");

                           

                           }

                           system("pause") ;

                           system("cls");

                       }

                   }

                   break;

                }

            case
2://按作用查找 

                {

                   system("cls");

                   system("color
2B");

                   printf("\n请输入要查找的狗狗的作用\n");

                   scanf("%s",effect1);

                   while(p!=NULL)

                   {

                       if(strcmp(effect1,p->effect)==0)

                       {

                           change=1;

                           printf("\n*********查找成功********\n");

                           system("pause");

                           system("cls");

                           //print(head);

                           printf("\n********狗狗的信息如下*********\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause");

                           system("cls");

                       break;

                       }

                       else

                       {

                           p=p->next;

                           if(p==NULL&&change==0)

                           {

                               printf("\n*******输入数据有误或者该只狗狗的信息不存在********\n");

                       

                           }

                           system("pause");

                           system("cls");

                       }

                   }

                   break;

                }

            case
3://按价格和姓名查找

                {

                   system("cls");

                   system("color
2B");

                   printf("\n请输入要查找的狗狗的姓名\n");

                   scanf("%s",name3);

                   printf("\n请输入要查找的狗狗的价格\n");

                   scanf("%s",price1);

                   

                   while(p!=NULL)

                   {

                       if(strcmp(name3,p->name)==0&&strcmp(price1,p->price)==0)

                       {

                           change=1;

                           printf("\n*********查找成功********\n");

                           system("pause");

                           system("cls");

                           printf("\t-----------------狗狗所对应的信息如下----------------\n");

                       //  print(head);

                       printf("\n********狗狗的信息如下*********\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause");

                           system("cls");

                            break;

                       }

                       else

                       {

                           p=p->next;

                       

                           if(p==NULL&&change==0)

                           {

                               printf("\n*******输入数据有误或者该只狗狗的信息不存在********\n");

                           

                           }

                           system("pause");

                           system("cls");

                       }

                   }

                   

                   break;

                }

            case
4://按作用和体积查找

                {

                   system("cls");

                   system("color
2B");

                   printf("\n请输入要查找的狗狗的作用\n");

                   scanf("%s",effect2);

                   printf("\n请输入要查找的狗狗的体积\n");

                   scanf("%s",size1);

                   while(p!=NULL)

                   {

                       if(strcmp(size1,p->size)==0&&strcmp(effect2,p->effect)==0)

                       {

                           change=1;

                           printf("\n*********查找成功********\n");

                           system("pause");

                           system("cls");

                       //  print(head);

                           printf("\n********狗狗的信息如下*********\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause");

                           system("cls");

                           break;

                       }

                       else

                       {

                           p=p->next;

                       

                           if(p==NULL&&change==0)

                           {

                               printf("\t*******输入数据有误或者该只狗狗的信息不存在********\n");

                               

                           }

                           system("pause");

                           system("cls");

                       }

                   }

                

            

                   break;

                }

            default
:

            {

                system("cls");

                system("color
2B");

                printf("\t*******你输入的选项有误********\n");

                system("pause");

                system("cls");

                break;

            }

        

        } 

        system("cls");

        system("color
2B");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");   

    printf("\t-------------是否在继续查找(0/1)--------------\n");

    fflush(stdin);

    scanf("%d",&m);


    if(m==0)

    printf("\t*********结束查找************\n");
  

    system("pause");

    system("cls");

    }while(m!=0);


}

Linklist delect(Linklist head)//删除

{

    char
name1[40]; 

    S *p,*t;

    int n;

    system("cls");

    system("color
3C");

    printf("\t------------------------------------------\n");

    printf("\t|     ********删除狗狗管理信息********   |\n");

    printf("\t------------------------------------------\n");

    do

    {

        int
change=0;

        printf("\t------------请输入要删除狗狗的姓名-------\n");

        scanf("%s",name1);

        p=head;

        t=head->next;

        system("pause");

        while(t->next!=NULL)

    {

 

            if(strcmp(name1,t->name)==0)

        {

                p->next=t->next;

                t=p->next;

                change=1;

                system("color
3C");

                printf("\t******删除成功******\n");

                system("pause");

                system("cls");

        }

            else


            {

                p=p->next;

                t=t->next;

                system("color
3C");

                if(change==0&&t==NULL)

                {

                   printf("\t******你的输入有误/不存在此狗狗的信息******\n");

                   system("pause");

                   system("cls");

        

                }

            }

    }

        system("cls");

        system("color 3C");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\t-------是否要继续删除狗狗的信息(0/1)-----------\n");

        scanf("%d",&n);

        if(n==0)

        printf("\t*********结束删除************\n");

    }while(n!=0);

    

return head;

    

} 

void print(Linklist head)//打印 

{

    S *p;

    p=head->next;

    system("cls");

    system("color
4D");

    printf("\t------------------------------------------\n");

    printf("\t|     ********打印狗狗管理信息********   |\n");

    printf("\t------------------------------------------\n");

    while(p->next!=NULL)

    {

        printf("\t--------------------------------------------\n");

        printf("\n狗狗的名字:%s\n",p->name);

        printf("\t|------------------------------------------|\n");

        printf("\n狗狗的特点:%s\n",p->trait);

        printf("\t|------------------------------------------|\n");

        printf("\n狗狗的体积:%s\n",p->size);

        printf("\t|------------------------------------------|\n");

        printf("\n狗狗的作用:%s\n",p->effect);

        printf("\t|------------------------------------------|\n");

        printf("\n狗狗的价格:%s\n",p->price);

        printf("\t--------------------------------------------\n");

        p=p->next;

    }

}

void insert(Linklist head)//按位置插入 

{

    S *p,*l;

    S *t; 

    int n;

    int m;

    //char
name5[40]; 

    system("cls");

    system("color
5E");

    printf("\t------------------------------------------------\n");

    printf("\t|         ********插入狗狗管理信息********     |\n");

    printf("\t------------------------------------------------\n");

    do

    {

        int
change=0;

        //char
name5[40]; 

        int
i=0;

        t=(Linklist)malloc(sizeof(S));

        printf("\t|----------请输入要插入的信息-----------|\n");

        printf("\n输入狗狗的名字:\n");

        printf("\n------------------------------------------\n");

        scanf("%s",t->name);

        printf("\n输入狗狗的特点:\n");

        printf("\n------------------------------------------\n");

        scanf("%s",t->trait);

        printf("\n输入狗狗的体积:\n");

        printf("\n------------------------------------------\n");

        scanf("%s",t->size);

        printf("\n输入狗狗的作用:\n");

        printf("\n------------------------------------------\n");

        scanf("%s",t->effect);

        printf("\n输入狗狗的价格:\n");

        printf("\n------------------------------------------\n");

        scanf("%s",t->price);

        system("pause");   

        system("cls");

        system("color
7E");

        printf("\t|------------请输入要插入在哪个狗狗的后面(姓名)-------------|\n");

        scanf("%d",&m);

        system("pause");

        system("cls");

        for(p=head,l=head->next;p!=NULL;i++,p=p->next,l=l->next)


        {

            if(m==(i+1))

            {

                change=1;

                p->next=t;

                t->next=l;

                printf("\t***********已成功插入*************\n");

                system("pause") ;

                system("cls");

                print(head);

                system("pause") ;

                system("cls");

                break;


            }

            else

            {

                if(change==0&&p==NULL)

                {

                   printf("\t***********你的输入有误*************\n");

                   system("pause") ;

                   system("cls");

                   break;

                }

            }

            

            /*if(strcmp(p->name,name5)==0)

            {

                change=1;

                p->next=t;

                t->next=l;

                printf("\t****************插入成功************\n");

                system("pause") ;

                system("cls");

                print(head);

                system("pause") ;

                system("cls");

                break;

            }

            else

            {

                if(change==0&&p==NULL)

                {

                   printf("\t***********你的输入有误或者链表不存在此节点**********\n");

                   //system("pause")  ;

                   //system("cls");

                   break;

                }

            }

            */

            

        }

            

        system("cls");

        system("color
7E");

        printf("\t---------是否进行继续插入(0~1)---------\n");

        scanf("%d",&n);

        if(n==0)

        printf("\t|-----------结束插入-------------|\n");

    }while(n!=0);

    

}

void revise(Linklist head)//修改

{

    S *p;

    int n;

    char
name4[40];

    char
name5[40],trait2[40],effect2[40],size2[40];

    char
price2[40];

    system("cls");

    system("color
6F");

    printf("\t-------------------------------------\n");

    printf("\t|
********修改狗狗管理信息********  |\n");

    printf("\t-------------------------------------\n");

    do

    {

        int
change=0;

        p=head->next;

        printf("\t|--------请输入需要修改的狗狗的姓名---------|\n");

        scanf("%s",name4);

        system("pause");

        while(p!=NULL)

        {

            if(strcmp(name4,p->name)==0)

            {

                   change=1;

                   system("cls");

                   system("color
6F");

                   printf("\t|-----------------------------------------|\n");


                   printf("\t|-----------------1.修改名字--------------|\n");


                   printf("\t|-----------------2.修改特点--------------|\n");


                   printf("\t|-----------------3.修改价格--------------|\n");

                   printf("\t|-----------------4.修改作用--------------|\n");

                   printf("\t|-----------------5.修改体积--------------|\n");

                   printf("\t|-----------------------------------------|\n");

                   printf("\n******输入要查找的选项*******\n");

                   scanf("%d",&n);

                   system("pasue");

                   switch(n)

                   {

                       case
1://修改名字 

                           {

                               system("color
6F");

                               system("cls");

                               printf("\n********请输入要修改成的名字********\n");

                               scanf("%s",name5);

                               strcpy(p->name,name5);

                               printf("\t************修改成功**************\n");


                               system("pause") ;

                               system("cls");


                               print(head);

                               system("pause") ;

                               system("cls");

                               break;

                           }

                       case
2://修改特点 

                           {

                       

                               system("color
6F");

                               system("cls");

                               printf("\n********请输入要修改成的特点********\n");

                               scanf("%s",trait2);

                               strcpy(p->trait,trait2);

                               printf("\t************修改成功**************\n");


                               system("pause") ;

                               system("cls");


                               print(head);


                               system("pause") ;

                               system("cls");


                               break;

                           }

                       case
3://修改价格 

                           {

                       

                           system("color
6F");

                               system("cls");

                               printf("\n********请输入要修改成的价格********\n");

                               scanf("%s",price2);

                               strcpy(p->price,price2);

                               printf("\t************修改成功**************\n");


                               system("pause") ;

                               system("cls");

                               print(head);


                               system("pause") ;

                               system("cls");

                           

                               break;

                           }

                       case
4://修改作用 

                           {

                               system("cls");

                               system("color
6F");

                               printf("\n********请输入要修改成的作用********\n");

                               scanf("%s",effect2);

                               strcpy(p->effect,effect2);

                               printf("\t************修改成功**************\n");


                               system("pause") ;

                               system("cls");

                               print(head);

                               system("pause") ;

                               system("cls");

                           

                               break;

                           }

                       case
5://修改体积 

                           {

                           system("cls");

                           system("color
6F");

                               printf("\t********请输入要修改成的体积********\n");

                               scanf("%s",size2);

                               strcpy(p->size,size2);

                               printf("\t************修改成功**************\n");


                               system("pause") ;

                               system("cls");

                               print(head);


                               system("pause") ;

                               system("cls");

                               break;

                           }

                       default
:

                           {

                           system("cls");

                           system("color
6F");

                               printf("\t*******你的输入有误*******\n");


                               system("pause") ;

                               system("cls");

                               break;

                           }

                   }

            }

            else

            {

                p=p->next;

                if(p==NULL&&change==0)

                {

                   printf("\t*******你的输入有误*******\n");

                }   ;

                system("pause") ;

                system("cls");  

            }

        } 

        system("cls");

        system("color
6F");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\t----------是否在继续修改(0/1)---\n");

        scanf("%d",&n);


        if(n==0)

        printf("\t*********结束修改************\n");


        }while(n!=0);

 

    

} 

void sort(Linklist head)//按体积大小和姓名排序

{

    S
*p,*r,*m;

    S *tail;

    int n;

    int l; 

    int k;

    system("cls");

    system("color
7A");

    printf("\t-------------------------------------------\n");

    printf("\t|    ********狗狗管理信息排序********     |\n");

    printf("\t-------------------------------------------\n");

    do{

        tail=NULL;

        printf("\t|---------------------------------------------|\n");

        printf("\t|-----------------1.按姓名排序----------------|\n");


        printf("\t|-----------------2.按体积排序(有升序和降序)--|\n");


        printf("\t|---------------------------------------------|\n");

        printf("\n******输入要排序的选项*******\n");

        scanf("%d",&n);

        system("pause");

        switch(n)

            {

                case
1 :

                   {

                   system("cls");

                   system("color
7A");

                    while(head->next->next!=tail)

                         {

                                for
(m=head->next,r=head;m->next!=tail;r=r->next,m=m->next)

                                 {

                                      p=m->next;

                                      if
(strcmp(m->name,p->name)>0)

                                      {

                                          r->next = p;

                                          m->next = p->next;

                                          p->next =m;

                                          m= r->next;

                                      }

                                 }

                                 tail=m;

                           }

                                   printf("\t************排序成功**************\n");


                                   system("pause");

                                   system("cls");

                                   print(head);

                                   system("pause");

                                   system("cls");

                                   break;

                   }

                case
2 :

                   {

                       system("cls");

                       system("color
7A");

                       printf("\t---------------------------------\n");

                       printf("\t-------------1.升序--------------\n");


                       printf("\t-------------2.降序--------------\n");


                       printf("\t---------------------------------\n");

                       printf("\n******输入要排序的选项*******\n");

                       scanf("%d",&l);

                       switch(l)

                       {

                           case
1 :

                           {

                               system("cls");

                               system("color
7A");

                                while(head->next->next!=tail)

                                 {

                                        for
(m=head->next,r=head;m->next!=tail;r=r->next,m=m->next)

                                         {

                                              p=m->next;

                                              if
(strcmp(m->size,p->size)>0)

                                              {

                                                  r->next = p;

                                                  m->next = p->next;

                                                  p->next =m;

                                                  m= r->next;

                                              }

                                         }

                                         tail=m;

                                   }

                                               printf("\t************排序成功**************\n");

                                               system("pause");

                                               system("cls"); 

                                               print(head);


                                               system("pause");

                                               system("cls");

                                   

                           break;

                           }

                           case
2 :

                           {

                               system("cls");

                               system("color
7A");

                                while(head->next->next!=tail)

                                 {

                                        for
(m=head->next,r=head;m->next!=tail;r=r->next,m=m->next)

                                         {

                                              p=m->next;

                                              if
(strcmp(m->size,p->size)<0)

                                              {

                                                  r->next = p;

                                                  m->next = p->next;

                                                  p->next =m;

                                                  m= r->next;

                                              }

                                         }

                                         tail=m;

                                   }

                                   printf("\t************排序成功**************\n");


                                   system("pause");

                                   system("cls");

                                   print(head);

                                   system("pause");

                                   system("cls");

                               

                               break;

                           }

                           default
:

                               {

                               system("cls");

                               system("color
7A");

                               printf("\t*******你的输入有误*******\n");

                               system("pause");

                               system("cls");

                               break;  

                               }

                       }

                       break;

                   }

                default
:

                   {

                       system("cls");

                       system("color
7A");

                       printf("\t*******你的输入有误*******\n");

                       system("pause");

                       system("cls");

                       break;

                   }

            }

        system("cls");

        system("color
7A");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\t----------是否在继续排序(0/1)---\n");

        scanf("%d",&k);

        if(k==0)

        printf("\t---------结束排序---------------n");

    }while(k!=0);

} 

void count(Linklist head)//统计

{

    

    int n;

    int m; 

    S *p;

    char
price3[40],size3[40];

    do

    {

        p=head->next;

        int
change=0 ;

        int
i=0;

        system("cls");

        system("color
8B");

        printf("\t|----------------------------------------|\n");

        printf("\t|-----------1.按价格进行统计-------------|\n");


        printf("\t|-----------2.按体积统计-----------------|\n");


        printf("\t|----------------------------------------|\n");

        printf("\n******输入要排序的选项*******\n");


        scanf("%d",&m);

        system("pause");

        switch(m)

        {

            case
1:

                {

                   system("cls");

                   system("color
8B");

                   printf("\t------请输入你要统计价格的信息----------\n");

                   scanf("%s",price3);

                   while(p!=NULL)

                   {


                       if(strcmp(p->price,price3)==0)

                       {

                           change=1;

                           i=i+1;

                           printf("\t-----------第%d个狗狗的信息-----------------",i);

                           printf("\n*************狗狗的信息如下*****************\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause");

                           system("cls");

                       }

                       else

                       {

                           if(change==0&&p==NULL)

                           {

                               printf("\t--------------你的输入有误--------------\n");


                           }

                       }

                       p=p->next;

                   }

                printf("\t-----------输出你要统计后的的信息------------------\n");

                printf("\t--------你所统计价格为%s的狗有%d个--------\n",price3,i);

                system("pause");

                system("cls");

                   break;

                }

            case
2:

                {

                   system("cls");

                   system("color
8B");

                   printf("\t-----------输入你要统计体积的信息---------\n");

                   scanf("%s",size3);

                   while(p!=NULL)

                   {

                       if(strcmp(p->size,size3)==0)

                       {

                           change=1;

                           ++i;

                           printf("\n********狗狗的信息如下*********\n");

                           printf("\t--------------------------------------------\n");

                           printf("\n狗狗的名字:%s\n",p->name);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的特点:%s\n",p->trait);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的体积:%s\n",p->size);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的作用:%s\n",p->effect);

                           printf("\t|------------------------------------------|\n");

                           printf("\n狗狗的价格:%s\n",p->price);

                           printf("\t--------------------------------------------\n");


                           system("pause");

                           system("cls");

                       }

                       else

                       {

                           if(change==0&&p==NULL)

                           {

                               printf("\t--------------你的输入有误---------\n");


                           }

                           system("pause");

                           system("cls");

                       }

                       p=p->next;

                   }

                   printf("\t-----------输出你要统计后的的信息---------\n");

                   printf("\t-----------你所统计体积为%s的狗有%d个-----\n",price3,i);

                   system("pause");

                   system("cls");

                

                   break;

                }

                default
:

                   {

                       system("cls");

                       system("color
8B");

                       printf("\t-----------你的输入有误!----------\n");


                       system("pause");

                       system("cls");

                       break;

                   }

        }

        system("cls");

        system("color
8B");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");

        printf("\n");


        printf("\t---------是否进行继续查找(0~1)----------\n");

        scanf("%d",&n);

        if(n==0)

        printf("\t----------结束统计---------------\n");

    }while(n!=0);

} 

int main()

{

    Linklist
head;

    Linklist
phead;

    int n;

    do{

    //  Linklist head;

    head=read();

    system("cls");


    system("color
9C");

    printf("\t|                    欢迎使用狗狗管理系统                  |\n");

    printf("\t------------------------------------------------------------\n");

    printf("\t|--------------×××1.输入狗的信息×××------------------|\n");

    printf("\t|--------------×××2.删除狗的信息×××------------------|\n");

    printf("\t|--------------×××3.查找狗的信息×××------------------|\n");

    printf("\t|--------------×××4.修改狗的信息×××------------------|\n");

    printf("\t|--------------×××5.排序狗的信息×××------------------|\n");

    printf("\t|--------------×××6.插入狗的信息×××------------------|\n");

    printf("\t|--------------×××7.统计狗的信息×××------------------|\n");

    printf("\t|--------------×××8.打印输出狗的信息×××--------------|\n");

    printf("\t|--------------×××0.退出×××--------------------------|\n");

    printf("\t------------------------------------------------------------\n");

    //Linklist head;

    printf("\n请输入你要执行的步骤(0~8)\n");

    

    scanf("%d",&n);

    system("pause");

    switch(n)

    {

        case 1://输入信息 

            {

                system("cls");

                head=create();

                save(head);

                break;

                

            }

        case 2://删除信息 

            {

                   system("cls");

                //  head=read();

                   delect(head);

                   save(head);

                   printf("\t------------删除后的结果----------\n");

                   print(head);

                   //save(head);

                    break;

            }

        case 3://查找信息 

            {

                system("cls");

                //head=read();

                look(head);

                //save(head);

                break;

            }

        case 4://修改信息 

            {

                system("cls");

                //head=read();

                revise(head);

                save(head);

                break;

            }

        case 5://排序信息 

            {

                system("cls");

                //head=read();

                sort(head);

                save(head);

                break;

            }

        case 6://插入信息 

            {

                system("cls");

                //head=read();

                insert(head);

                save(head);

                //print(head); 

                break;

            }

        case 7://统计信息 

            {

                system("cls");

                //head=read();

                count(head);

                save(head);

                break;

            }

        case 8://打印输出信息 

            {

                system("cls");

                //head=read(); 

                print(head);

                save(head);

                break;

            }

        case 0://退出

            {

                system("cls");

                break;

            }

        default :

        {

            system("cls");

            printf("\n********您所输入的信息有误********\n");

            break; 

        }

        

        

    }

    system("pause");

    

    } while(n!=0); 

}

 


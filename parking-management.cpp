#include<iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
struct node
{
    int length;
    int flag;
    struct node *next;
    struct node *bott;
};

struct node *first1, *first2, *x, *temp1, *temp2;
char buff;
void firstfit();
void bestfit();
void worstfit();
void display();
int main()
{
    char choice='y';
    int n,m,rows,cols;
    system("cls");
    do
    {
        cout<< "\n\n\t\t\tSize of parking:";
        cout<< "\n\n\t\t\tEnter number of rows in parking:";
        cin>>rows;
        cout<< "\n\n\t\t\tEnter number of columns in parking:";
        cin>>cols;
        first1=new node;
        first1->length=rand()%3;
        first1->flag=rand()%2;
        first1->next=NULL;
        first1->bott=NULL;
        temp1=first1;
        if(cols>1)
        {
            first2=new node;
            first2->length=rand()%3;
            first2->flag=rand()%2;
            first2->next=NULL;
            first2->bott=NULL;
            temp1->next=first2;
            temp2=first2;
            for(int i=2;i<cols;i++)
            {
                x=new node;
                x->length=rand()%3;
                x->flag=rand()%2;
                x->next=NULL;
                x->bott=NULL;
                temp2->next=x;
                temp2=x;
            }
        }
        for(int j=1;j<rows;j++)
        {
            x=new node;
            x->length=rand()%3;
            x->flag=rand()%2;
            x->next=NULL;
            x->bott=NULL;
            temp1->bott=x;
            temp1=x;
            if(cols>1)
            {
                first2=new node;
                first2->length=rand()%3;
                first2->flag=rand()%2;
                first2->next=NULL;
                first2->bott=NULL;
                temp1->next=first2;
                temp2=first2;
                for(int i=2;i<cols;i++)
                {
                    x=new node;
                    x->length=rand()%3;
                    x->flag=rand()%2;
                    x->next=NULL;
                    x->bott=NULL;
                    temp2->next=x;
                    temp2=x;
                }
            }
        }
        display();
        cout<< "\n\n\t\t\tPARKING MANAGEMENT SYSTEM\n\n";
        cout<< "\t\t\t\tMENU \n\t\t\t1.Park according to BEST FIT\n\t\t\t2.Park according to FIRST FIT\n\t\t\t3.Park according to WORST FIT\n\n\t\t\t";
        cin>>n;
        switch(n)
        {
            case 1:{
                cout<< "\n\n\t\t\tPARKING MANAGEMENT SYSTEM\n\n\n";
                cout<<"\n\n\t\t\tEnter number of vehicles:";
                cin>>m;
                for(int i=0;i<m;i++){
                    bestfit();
                }
                break;
            }
            case 2:{
                cout<< "\n\n\t\t\tPARKING MANAGEMENT SYSTEM\n\n\n";
                cout<<"\n\n\t\t\tEnter number of vehicles:";
                cin>>m;
                for(int i=0;i<m;i++){
                    firstfit();
                }
                break;
            }
            case 3:{
                cout<< "\n\n\t\t\tPARKING MANAGEMENT SYSTEM\n\n\n";
                cout<<"\n\n\t\t\tEnter number of vehicles:";
                cin>>m;
                for(int i=0;i<m;i++){
                    worstfit();
                }
                break;
            }
            default:{
                printf("\nWRONG CHOICE..!!");
                exit(0);
            }
        }
        printf("\nWANT MENU AGAIN??(Y/N)");
        cin>>choice;
    }while(choice=='y'||choice=='Y');
    return 0;
}
void display()
{
    cout<<"\n\n\n\n\n\t\tParking structure displaying length of each space with a flag in () indicating empty or occupied space\n\n\n\n";
    temp1=first1;
    temp2=first1;
    while(temp1!=NULL){
        temp2=temp1;
        while(temp2!=NULL){
            if(temp2->flag==1){
                cout<<"\t"<<temp2->length<<"(Occupied)\t";
            }
            else{
                cout<<"\t"<<temp2->length<<"(Not Occupied)\t";
            }
            temp2=temp2->next;
        }
        cout<<"\n\n\n";
        temp1=temp1->bott;
    }
}
void bestfit()
{
    int p,a=0,b=0,posa=-1,posb=-1;
    cout<< "\n\n\tEnter 0 for 2-wheeler 1 for sedan 2 for SUV:";
    cin>>p;
    int mi=3;
    temp1=first1;
    temp2=first1;
    while(temp1!=NULL)
    {
        temp2=temp1;
        a=0;
        while(temp2!=NULL)
        {
            if(temp2->length<mi && temp2->flag==0 && temp2->length>=p)
            {
                mi=temp2->length;
                posa=a;
                posb=b;
            }
            a++;
            temp2=temp2->next;
        }
        b++;
        temp1=temp1->bott;
    }
    if(posa==-1)
    {
        cout<<"\n\n\t\t\tCannot be allocated\n\n";
    }
    else
    {
        cout<<"\n\n\n\t\t\tChange at "<<posb+1<<","<<posa+1;
        temp1=first1;
        for(int i=0;i<posb;i++)
        {
            temp1=temp1->bott;
        }
        for(int j=0;j<posa;j++)
        {
            temp1=temp1->next;
        }
        temp1->flag=1;
        cout<<"\n\t\t\tAllocated\n";
    }
    display();
}
void worstfit()
{
    int p,a=0,b=0,posa=-1,posb=-1;
    cout<< "\n\n\tEnter 0 for 2-wheeler 1 for sedan 2 for SUV:";
    cin>>p;
    int ma=0;
    temp1=first1;
    temp2=first1;
    while(temp1!=NULL)
    {
        temp2=temp1;
        a=0;
        while(temp2!=NULL)
        {
            if(temp2->length>ma && temp2->flag==0 && temp2->length>=p)
            {
                ma=temp2->length;
                posa=a;
                posb=b;
            }
            a++;
            temp2=temp2->next;
        }
        b++;
        temp1=temp1->bott;
    }
    if(posa==-1)
    {
        cout<<"\n\n\t\t\tCannot be allocated\n\n";
    }
    else
    {
        cout<<"\n\n\n\t\t\tChange at "<<posb+1<<","<<posa+1;
        temp1=first1;
        for(int i=0;i<posb;i++)
        {
            temp1=temp1->bott;
        }
        for(int j=0;j<posa;j++)
        {
            temp1=temp1->next;
        }
        temp1->flag=1;
        cout<<"\n\t\t\tAllocated\n";
    }
    display();
}
void firstfit()
{
    int p,a=0,b=0,posa=-1,posb=-1;
    cout<< "\n\n\tEnter 0 for 2-wheeler 1 for sedan 2 for SUV:";
    cin>>p;
    temp1=first1;
    temp2=first1;
    while(temp1!=NULL)
    {
        temp2=temp1;
        a=0;
        while(temp2!=NULL)
        {
            if(temp2->flag==0 && temp2->length>=p)
            {
                posa=a;
                posb=b;
                temp2->flag=1;
                break;
            }
            a++;
            temp2=temp2->next;
        }
        if(posa!=-1)
        {
            break;
        }
        b++;
        temp1=temp1->bott;
    }
    if(posa==-1)
    {
        cout<<"\n\n\t\t\tCannot be allocated\n\n";
    }
    else
    {
        cout<<"\n\n\n\t\t\tChange at "<<posb+1<<","<<posa+1;
        cout<<"\n\t\t\tAllocated\n";
    }
    display();
}

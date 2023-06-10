#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
int n=0;
struct book
{
    char name[100],add[200],num[11],surname[100];
} a[50] ;

void display(struct book a[])
{
    printf("\n\n\t\t----------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t\t\t\t\t\tTHE CONTACT LIST\n\n");
    printf("\t\t----------------------------------------------------------------------------------------------------");
    printf("\n\n\t\t NAME\t\t\tSURNAME\t\t\t       ADDRESS\t\t\t\tNUMBER\n\n");

    for(int i=0; i<n; i++)
    {
        printf("\t\t%s\t\t\t%s    \t\t\t%s\t\t\t\t%s\n",a[i].name,a[i].surname,a[i].add,a[i].num);
    }
}
void addcontact(struct book a[])
{
    int t=0,m;
    printf("\n\n\tHow many contact you want to add : ");
    scanf("%d",&m);
    t=n;
    m=m+t;
    if(m+n>=50)
    {
        printf("\n\n\tSORRY YOU CANNOT ADD MORE CONTACT NOW !!!!!!!!!\n\n");
    }
    else
    {
        for(int i=t; i<m; i++)
        {
            printf("\n\n\tEnter the First Name of the person : ");
            scanf("%s",a[i].name);
            printf("\n\tEnter the SurName of the person : ");
            scanf("%s",a[i].surname);
            printf("\n\tEnter the Address of the person : ");
            scanf("%s",a[i].add);
            printf("\n\tEnter the Number of the person(10 digit Max.) : ");
            scanf("%s",a[i].num);
        }
        t=m;
        n=t+1;
    }
}

void modify(struct book a[])
{
    char mod_name[100],mod_surname[100];
    int flag=1;
    printf("\n\n\tEnter the First name : ");
    scanf("%s",&mod_name);
    printf("\n\tEnter the Surname : ");
    scanf("%s",&mod_surname);
    int ch;
    printf("\n\n\t\tWhat do you want to modify.\n\n\t\t1.NAME\n\n\t\t2.SURNAME\n\n\t\t3.ADDRESS\n\n\t\t4.NUMBER\n\n");
    printf("\n\t\tEnter your choice : ");
    scanf("%d",&ch);
    for(int i=0; i<n; i++)
    {
        if((strcmpi(a[i].name,mod_name)==0)&&(strcmpi(a[i].surname,mod_surname)==0))
        {
            flag=0;
            switch(ch)
            {
            case 1:
                printf("\n\n\tEnter the new name of the person : ");
                scanf("%s",&a[i].name);
                break;
            case 2:
                printf("\n\tEnter the new surname of the person : ");
                scanf("%s",&a[i].surname);
                break;
            case 3:
                printf("\n\tEnter the new Address of the person : ");
                scanf("%s",&a[i].add);
                break;
            case 4:
                printf("\n\tEnter the new number of the person : ");
                scanf("%s",&a[i].num);
                break;
            default :
                printf("\n\n\tINVALID CHOICE !!!!!!!!!!!\n\n");
            }
        }
    }
        if(flag==0)
        {
            printf("\n\n\tRECORD MODIFIED SUCCESSFULLY !!!!!!!! \n\n");

        }
        else
        {
            printf("\n\n\tSORRY RECORD NOT FOUND !!!!! \n\n");
        }


}

int del_rec(struct book b[],char str[100],char str1[100])
{
    int ct=0;
    struct book temp;
    for(int i=0; i<n; i++)
    {
        if((strcmpi(b[i].name,str)==0)&&(strcmpi(b[i].surname,str1)==0))
        {
            for(int j=i; j<=n-1; j++)
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
            ct=1;
            n--;
        }
    }
    return ct;
}

int search(struct book a[],char str[100],char str1[100])
{
    int j=-1;
    for(int i=0; i<n; i++)
    {
        if((strcmpi(a[i].name,str)==0)&&(strcmpi(a[i].surname,str1)==0))
        {
            j=i;
        }
    }
    return j;
}
int main()
{
    int c,choice,tr,s;
    struct book d;
    char sname[100],dname[100],suname1[100],suname[100];
    char ch;
    printf("\t\t-----------------------------------------------------");
    printf("\n\n\t\t\tWELCOME TO THE PHONE BOOK\n\n");
    printf("\t\t-----------------------------------------------------");
    printf("\n\n\t\tGROUP MEMBERS\n\n\t\t1.Shubhankar Ranjan\n\t\t2.Khushi Sinha\n\n");
    printf("\t\t-----------------------------------------------------");
    printf("\n\n\n\n\n\n");
    printf("\n\n\tDo you want to open the PHONE BOOK? (y\\n) : ");
    scanf("%c",&ch);

    while(ch=='y' || ch=='Y')
    {

        printf("\n\n\t\t1.Add contact\n\t\t\n\t\t2.Display contact\n\t\t\n\t\t3.Search contact\n\t\t\n\t\t4.Modify contact\n\t\t\n\t\t5.Delete contact\n\t\t\n\t\t6.Exit\n");
        printf("\n\n\t\tEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            addcontact(a);
            break;
        case 2:
            display(a);
            break;
        case 3:
            printf("\n\n\tEnter the First name : ");
            scanf("%s",&sname);
            printf("\n\tEnter the Surname : ");
            scanf("%s",&suname1);
            s=search(a,sname,suname1);
            if(s==-1)
                printf("\n\n\t\tRecord not found!!!!!\n\n");
            else
            {
                printf("\n\n\t\t----------------------------------------------------------------------------------------------------");
                printf("\n\n\t\t\t\t\t\t\tSEARCHED CONTACT\n\n");
                printf("\t\t----------------------------------------------------------------------------------------------------");
                printf("\n\n\t\t NAME\t\t\tSURNAME\t\t\t        ADDRESS\t\t\t\tNUMBER\n\n");
                printf("\t\t%s\t\t\t%s\t\t\t  %s\t\t\t\t%s\n",a[s].name,a[s].surname,a[s].add,a[s].num);
                printf("\n\n");
            }

            break;
        case 4:
            modify(a);
            break;
        case 5:
            printf("\n\n\tEnter the First name : ");
            scanf("%s",&dname);
            printf("\n\n\tEnter the Surname : ");
            scanf("%s",&suname);
            tr=del_rec(a,dname,suname);
            if(tr==0)
                printf("\n\n\t\tRecord not found!!!!!!\n\n");
            else
                printf("\n\n\t\tRecord deleted successfully\n\n");
            break;
        case 6:
            printf("\n\n\t\t------------------------------------------------------------------------------------");
            printf("\n\n\t\t\t\t\t\tTHANK YOU \n\n");
            printf("\t\t------------------------------------------------------------------------------------");
            printf("\n\n\t\tGROUP MEMBERS\n\n\t\t1.Shubhankar Ranjan\n\t\t2.Khushi Sinha\n\n");
            printf("\t\t------------------------------------------------------------------------------------\n\n\n");

            exit(0);
            break;

        default :
            printf("\n\n\t\t------------------------------------------------------------------------------------\n\n");

            printf("\n\t\t\t\t!!!!!!!!!!!!!!!!! Invalid choice !!!!!!!!!!!!!!!!!\n\n\n");
            printf("\t\t------------------------------------------------------------------------------------");

        }
    }
    getch();
    return 0;
}

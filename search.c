#include "header.h"

void search()
{
    if(count ==0)
    {
        printf("\nNothing to Search for\n");
        return;
    }
    int choice;
    int i,n=0,flag=0;
    printf("1.Search\t2.Multi-Search\nPlease Enter your choice:");
    inputchecker(&choice);
    if(choice==1)
    {
        char key1[20];
        printf("\nSearch\n");
        printf("Please Enter Last Name:");
        scanf("%[^\n]s",key1);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(s[i].lastname,key1)==0)
            {
                if(n==0)
                {
                    printf("\nNumber\tLast Name    First Name\t  Date\t\tAddress\t\t\t\t  Email\t\t\t\t Phone\n");
                    n++;
                }
                printf("%-2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
                if(strlen(s[i].address)<20)
                    printf("%-25s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
                else
                    printf("%-20s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
                flag=1;
            }
        }
        getchar();
    }
    else if(choice==2)
    {
        int d,y,m;
        char key1[20];
        char key2[20];
        char key3[20];
        char key4[20];
        char key5[20];
        char key6[20];
        char key7[20];
        char key8[20];
        printf("\nMulti-Search");
        printf("\nPlease Enter Last Name:");
        gets(key1);
        printf("Please Enter First Name :");
        gets(key2);
        printf("Please Enter Email:");
        gets(key3);
        printf("Please Enter Address:");
        gets(key4);
        printf("Please Enter Phone Number:");
        gets(key5);
        printf("Please Enter Day of Birth:");
        gets(key6);
        printf("Please Enter Month of Birth:");
        gets(key7);
        printf("Please Enter Year of Birth:");
        gets(key8);
        d=atoi(key6);
        m=atoi(key7);
        y=atoi(key8);
        if(strcasecmp(key1,"")==0 && strcasecmp(key2,"")==0 && strcasecmp(key3,"")==0 && strcasecmp(key4,"")==0&& strcasecmp(key5,"")==0 && strcasecmp(key6,"")==0 && strcasecmp(key7,"")==0&&strcasecmp(key8,"")==0)
        {
            printf("Blank Search!!\n");
            return;
        }
        for(i=0; i<count; i++)
        {
            if(strcasecmp(s[i].lastname,key1)==0 || strcasecmp(key1,"")==0)
                if(strcasecmp(s[i].firstname,key2)==0 || strcasecmp(key2,"")==0)
                    if(strcasecmp(s[i].email,key3)==0 || strcasecmp(key3,"")==0)
                        if(strcasecmp(s[i].address,key4)==0 || strcasecmp(key4,"")==0)
                            if(strcasecmp(s[i].phonenum,key5)==0 || strcasecmp(key5,"")==0)
                                if((d==s[i].d.day && m==s[i].d.month && y==s[i].d.year )||(strcasecmp(key6,"")==0||strcasecmp(key7,"")==0||strcasecmp(key8,"")==0))
                                {
                                    if(n==0)
                                    {
                                        printf("\nNumber\tLast Name    First Name\t  Date\t\tAddress\t\t\t\t  Email\t\t\t\t Phone\n");
                                        n++;
                                    }
                                    printf("%-2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
                                    if(strlen(s[i].address)<20)
                                        printf("%-25s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
                                    else
                                        printf("%-20s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
                                    flag=1;
                                }
        }
    }
    else
    {
        printf("You entered wrong choice\n");
        return;
    }

    if(flag==0)
        printf("Not Found\n");
}


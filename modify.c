#include "header.h"

void modify()
{
    if(count ==0)
    {
        printf("\nThere is nothing to modify\n");
        return;
    }
    int i,z=0,flag=0,n=0,key;
    char *name1=malloc(20);
    printf("\nEnter last name: ");
    scanf("%s",name1);
    for(i=0; i<count; i++)
    {
        if(strcasecmp(s[i].lastname,name1)==0)
        {
            if(n==0)
            {
                printf("Number\tLast Name    First Name\t  Date\t\tAddress\t\t\t\t  Email\t\t\t\t Phone\n");
                n++;
            }
            z=i;
            printf("%-2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
            if(strlen(s[i].address)<20)
                printf("%-25s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
            else
                printf("%-20s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
            flag++;
        }
    }
    free(name1);
    if(flag==0)
    {
        printf("Not Found\n");
        return;
    }
    n=0;
    while(flag>1)
    {
        char *name2=malloc(40);
        if(n==0)
            printf("\nPlease Enter Email(Users can't have same email):");
        else
            printf("Please Enter Valid Email from the previous list:");
        scanf("%s",name2);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(s[i].email,name2)==0)
            {
                z=i;
                flag=0;
                break;
            }
        }
        free(name2);
        n++;
    }
    n=1;
    getchar();
    while(n!=2)
    {
        printf("\nModify:\n1.Last Name\n2.First Name\n3.Date\n4.Address\n5.E-mail\n6.Phone Number\n\nEnter Your Choice:");
        inputchecker(&key);
        if(key==1)
        {
            char *buff=malloc(2000);
            i=0;
            do
            {
                if(i==0)
                    printf("Please Enter Modified Last name:");
                else
                    printf("Please Enter Correct Modified Last name:");
                fgets(buff,2000,stdin);
                if(strlen(buff)>10)
                    strncpy(s[z].lastname,buff,10);
                else
                {
                    strtok(buff,"\n");
                    strcpy(s[z].lastname,buff);
                }
                i++;
                *(s[z].lastname+9)=0;
            }
            while(nameval(s[z].lastname)!=1 || strcasecmp(s[z].lastname," ")==0);
            free(buff);
        }
        if(key==2)
        {
            char *buff=malloc(2000);
            i=0;
            do
            {
                if(i==0)
                    printf("Please Enter Modified First name:");
                else
                    printf("Please Enter Correct Modified First name:");
                fgets(buff,2000,stdin);
                if(strlen(buff)>10)
                    strncpy(s[z].firstname,buff,10);
                else
                {
                    strtok(buff,"\n");
                    strcpy(s[z].firstname,buff);
                }
                i++;
                *(s[z].firstname+9)=0;
            }
            while(nameval(s[z].firstname)!=1 || strcasecmp(s[z].firstname," ")==0);
            free(buff);
        }
        else if(key==3)
        {
            i=0;
            do
            {
                if(i>0)
                    printf("Wrong Date Please Try again.\n\n");
                printf("Please Enter Modified Day:");
                inputchecker(&s[z].d.day);
                printf("Please Enter Modified Month:");
                inputchecker(&s[z].d.month);
                printf("Please Enter Modified year:");
                inputchecker(&s[z].d.year);
                if(s[z].d.month==2)
                {
                    if(s[z].d.day>29)
                    {
                        printf("February shouldn't include more than 29 days\n");
                        s[z].d.day=35;
                    }
                }
                i++;
            }
            while(s[z].d.day>31 || s[z].d.day<0 || s[z].d.month<0 || s[z].d.month>12 ||s[z].d.year>2019 || s[z].d.year<1920);
        }
        else if(key==4)
        {
            int addressflag=1;
            char *buff=malloc(2000);
            i=0;
            do
            {
                if(i==0)
                    printf("Please Enter Modified Address:");
                else if(addressflag==0)
                    printf("Address mustn't contain \",\"\n");
                if(i>0)
                    printf("Please Enter Correct Modified Address:");
                fgets(buff,2000,stdin);
                if(strlen(buff)>40)
                    strncpy(s[z].address,buff,40);
                else
                {
                    strtok(buff,"\n");
                    strcpy(s[z].address,buff);
                }
                i++;
                *(s[z].address+39)=0;
                addressflag=addresssubstring(s[z].address);
            }
            while(addressflag==0 || strcasecmp(s[z].address,"\n")==0);
            free(buff);
        }
        else if(key==5)
        {
            i=0;
            char *buff=malloc(1000);
            do
            {
                if(i==0)
                    printf("Please Enter Modified Email:");
                else
                    printf("Please Enter Correct Modified Email:");
                fgets(buff,2000,stdin);
                if(strlen(buff)>30)
                    strncpy(s[z].email,buff,30);
                else
                {
                    strtok(buff,"\n");
                    strcpy(s[z].email,buff);
                }
                i++;
                *(s[z].email+29)=0;
            }
            while(emailval(s[z].email)!=1 || substring(s[z].email,".com")==0 || duplicatechecker(s,z)==0);
            free(buff);
        }
        else if(key==6)
        {
            i=0;
            char *buff=malloc(1000);
            do
            {
                if(i==0)
                    printf("Please Enter Modified Phone Number:");
                else
                    printf("Please Enter Correct Modified Phone Number:");
                fgets(buff,2000,stdin);
                if(strlen(buff)>11)
                    strncpy(s[z].phonenum,buff,11);
                else
                {
                    strtok(buff,"\n");
                    strcpy(s[z].phonenum,buff);
                }
                i++;
                *(s[z].phonenum+11)=0;
            }
            while(phoneval(s[z].phonenum)!=1);
            free(buff);
        }
        n=0;
        while(n>2 || n<1)
        {
            printf("Press 1 to continue modifying or Press 2 to return to menu:");
            inputchecker(&n);
        }
    }
    saveflag=0;
}

#include"header.h"

void add()
{
    int flag=0;
    int i,j;
    char *buff=malloc(2000);
    while(flag==0)
    {
        i=0;
        printf("\nUser=%d\n",count+1);
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Last name:");
            else
                printf("Please Enter Correct Last name:");
            fgets(buff,2000,stdin);
            if(strlen(buff)>10)
                strncpy(s[count].lastname,buff,10);
            else
            {
                strtok(buff,"\n");
                strcpy(s[count].lastname,buff);
            }
            i++;
            *(s[count].lastname+9)=0;
        }
        while(nameval(s[count].lastname)!=1 || strcasecmp(s[count].lastname," ")==0);
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter First name:");
            else
                printf("Please Enter Correct First name:");
            fgets(buff,2000,stdin);
            if(strlen(buff)>10)
                strncpy(s[count].firstname,buff,10);
            else
            {
                strtok(buff,"\n");
                strcpy(s[count].firstname,buff);
            }
            i++;
            *(s[count].firstname+9)=0;
        }
        while(nameval(s[count].firstname)!=1 || strcasecmp(s[count].firstname," ")==0);
        i=0;
        do
        {
            if(i>0)
                printf("Wrong Date. Please Try Again\n\n");
            printf("Please Enter Day:");
            inputchecker(&s[count].d.day);
            printf("Please Enter Month:");
            inputchecker(&s[count].d.month);
            printf("Please Enter Year:");
            inputchecker(&s[count].d.year);
            if(s[count].d.month==2)
            {
                if(s[count].d.day>29)
                {
                    printf("February shouldn't include more than 29 days\n");
                    s[count].d.day=35;  //To Enter the loop once again
                }
            }
            i++;
        }
        while(s[count].d.day>31 || s[count].d.day<0 || s[count].d.month<0 || s[count].d.month>12 ||s[count].d.year>2019 || s[count].d.year<1920);
        int addressflag=1;
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Address:");
            else if(addressflag==0)
                printf("Address mustn't contain \",\"\n");
            if(i>0)
                printf("Please Enter Correct Address:");
            fgets(buff,2000,stdin);
            if(strlen(buff)>40)
                strncpy(s[count].address,buff,40);
            else
            {
                strtok(buff,"\n");
                strcpy(s[count].address,buff);
            }
            i++;
            *(s[count].address+39)=0;
            addressflag=addresssubstring(s[count].address);
        }
        while(addressflag==0 || strcasecmp(s[count].address,"\n")==0);
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Email:");
            else
                printf("Please Enter Correct Email:");
            fgets(buff,2000,stdin);
            if(strlen(buff)>30)
                strncpy(s[count].email,buff,30);
            else
            {
                strtok(buff,"\n");
                strcpy(s[count].email,buff);
            }
            i++;
            *(s[count].email+29)=0;
        }
        while(emailval(s[count].email)!=1 || substring(s[count].email,".com")==0);
        i=0;
        do
        {
            if(i==0)
                printf("Please Enter Phone Number:");
            else
                printf("Please Enter Correct Phone Number:");
            fgets(buff,2000,stdin);
            if(strlen(buff)>11)
                strncpy(s[count].phonenum,buff,11);
            else
            {
                strtok(buff,"\n");
                strcpy(s[count].phonenum,buff);
            }
            i++;
            *(s[count].phonenum+11)=0;
        }
        while(phoneval(s[count].phonenum)!=1);
        printf("\nLoading File To Check for Duplicates..........\n");
        flag=duplicatechecker(s,count);
        if(flag==0)   //Compare with contacts recently added during program execution
        {
            printf("This name has already been added\n");
            printf("Please Try Again\n");
        }
        if(flag==1)
        {
            for(j=0; j<tempcount; j++)  //Compare with contacts in files
            {
                if (strcasecmp(temp[j].email,s[count].email)==0)
                {
                    printf("%s %s already exists in file\n",s[count].firstname,s[count].lastname);
                    flag=0;
                    printf("Please Try Again\n");
                    break;
                }
            }
        }
    }
    printf("\n");
    saveflag=0;
    count++;
}

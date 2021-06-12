#include "header.h"

void print()
{
    int i;
    printf("\n===========================================================");
    printf("===================================================================\n");
    printf("Number\tLast Name    First Name\t  Date\t\tAddress\t\t\t\t  Email\t\t\t\t Phone\n");
    printf("============================================================");
    printf("==================================================================\n");
    for(i=0; i<count; i++)
    {
        printf("%-2d\t%-10s   %-10s   %.2d-%.2d-%d\t",i+1,s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
        if(strlen(s[i].address)<20)
            printf("%-25s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
        else
            printf("%-20s\t  %-24s\t %s\n",s[i].address,s[i].email,s[i].phonenum);
    }
    printf("============================================================");
    printf("==================================================================\n");
    saveflag=0;
}

#include "header.h"

void save()
{
    FILE *fp;
    fp=fopen("data.txt","w");//append in case of adding contacts
    if(fp==NULL)
    {
        printf("File doesn't exist\n");
        exit(-1);
    }
    int i;
    for(i=0; i<count; i++)
    {
        fprintf(fp,"%s,%s,%d-%d-%d,",s[i].lastname,s[i].firstname,s[i].d.day,s[i].d.month,s[i].d.year);
        fprintf(fp,"%s,%s,%s",s[i].address,s[i].email,s[i].phonenum);
        fprintf(fp,"\n");
    }
    fclose(fp);
}

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void  str_find(char *str,int n)
{
    int i;
    char r;
    getchar();
    printf("\n Enter Replace Character  : ");
    scanf("%c",&r);
    for (i = 0; str[i] != '\0'; i++)
    {
        if(i == n)
        {
            str[i] = r;
        }
    }
    printf("\n Change String is %s",str);
}

void main()
{
    char *str,c;
    int n;
    str=(char*)malloc(50*sizeof(char));
    printf("\n Enter String : ");
    gets(str);
    printf("\n Enter index no : ");
    scanf("%d",&n);
    str_find(str,n);
}

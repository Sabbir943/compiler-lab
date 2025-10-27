#include<stdio.h>
#include<string.h>
#include<ctype.h>


char *keyword[]= {"int" ,"if","for","while","else","return","float"} ;
int keywordCount=7;

int isKeyword(char *str)
{
    for(int i=0;i<keywordCount;i++)
    {
        if(strcmp(str,keyword[i])==0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    char str[100];
    printf("provided the code :");
    gets(str);

  //full code travas
    int i=0;
    while(str[i]!=NULL)
    {

        if(isspace(str[i]))
        {
            i++;
            continue;;
        }

        // keyword and identifier
        if(isalpha(str[i] ))
        {
            char temp[50];
            int k =0;

            while(isalnum(str[i])){
                temp[k++]=str[i++];
            }

            temp[k]='\0';

            if (isKeyword(temp)){
                printf("keyword --> %s\n",temp);

            }
            else{
                printf("Indentifier -->%s\n",temp);
            }

        }
    }
}

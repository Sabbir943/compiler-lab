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

int isOperator(char ch)
{
    return (ch=='-'||ch=='+'||ch=='*'||ch=='/'||ch=='%'||ch=='='||ch=='<'||ch=='>'||ch=='!');
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
        //number
        else if(isdigit(str[i])){
            char temp[50];
            int k=0;

            while(isdigit(str[i])){
                temp[k++]=str[i++];
            }
            temp[k]='\0';

            printf("Number --> : %s\n", temp);
        }
        //operator

        else if(isOperator(str[i])){
            char op =str[i];

            //multi operator
            if((op=='='||op=='<'||op=='>'||op=='!')
               && str[i+1]=='=')
               {
                   printf("Operator -->%c%c\n", str[i],str[i++]);
                   i+=2;
               }
               else{
                 printf("Operator -->%c\n", str[i]);
                 i++;
               }

        }
        //parenthesis/punchuator

        else if(str[i]=='('||str[i]==')'||str[i]=='{'||str[i]=='}'||str[i]==';'){
                printf("Punchuator --> %c\n", str[i]);
                i++;

        }

        else{
            printf("Symbol -->%c\n", str[i]);
            i++;
        }
    }







}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

char *keyword[] = {"int", "if", "for", "while", "else", "return", "float"};
int keywordCount = 7;

int isKeyword(char *str)
{
    for (int i = 0; i < keywordCount; i++)
    {
        if (strcmp(str, keyword[i]) == 0)
        {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch)
{
    return (ch == '-' || ch == '+' || ch == '*' || ch == '/' ||
            ch == '%' || ch == '=' || ch == '<' || ch == '>' || ch == '!');
}

int main()
{
    char str[100];
    printf("Provide the code: ");
    fgets(str, sizeof(str), stdin); // safer than gets()

    int i = 0;
    while (str[i] != '\0') //
    {
        if (isspace(str[i]))
        {
            i++;
            continue;
        }

        // Keyword or Identifier
        if (isalpha(str[i]))
        {
            char temp[50];
            int k = 0;

            while (isalnum(str[i]))
            {
                temp[k++] = str[i++];
            }

            temp[k] = '\0';

            if (isKeyword(temp))
                printf("Keyword --> %s\n", temp);
            else
                printf("Identifier --> %s\n", temp);
        }

        // Number
        else if (isdigit(str[i]))
        {
            char temp[50];
            int k = 0;

            while (isdigit(str[i]))
            {
                temp[k++] = str[i++];
            }
            temp[k] = '\0';

            printf("Number --> %s\n", temp);
        }

        // Operator
        else if (isOperator(str[i]))
        {
            char op = str[i];

            // Multi-character operators like <=, >=, ==
            if ((op == '=' || op == '<' || op == '>' || op == '!') && str[i + 1] == '=')
            {
                printf("Operator --> %c%c\n", str[i], str[i + 1]);
                i += 2;
            }
            else
            {
                printf("Operator --> %c\n", str[i]);
                i++;
            }
        }

        // Parenthesis / Punctuation
        else if (str[i] == '(' || str[i] == ')' || str[i] == '{' ||
                 str[i] == '}' || str[i] == ';' || str[i] == ',')
        {
            printf("Punctuator --> %c\n", str[i]);
            i++;
        }

        else
        {
            printf("Symbol --> %c\n", str[i]);
            i++;
        }
    }

    return 0;
}


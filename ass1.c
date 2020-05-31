/*
1) Keywords: 
Examples- for, while, if etc.

2) Identifier
Examples- Variable name, function name etc.

3) Operators:
Examples- '+', '++', '-' etc.

4) Separators:
Examples- ', ' ';' etc
*/

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define OPERATOR_TOK 0
#define KEYWORD_TOK 1
#define ID_TOK 2
#define INT_TOK 3
#define DELIM_TOK 4


bool isDelimiter(char ch) //parenthesis,curly braces
{
    if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' ||  
        ch == '/' || ch == ',' || ch == ';' || ch == '>' ||  
        ch == '<' || ch == '=' || ch == '(' || ch == ')' ||  
        ch == '[' || ch == ']' || ch == '{' || ch == '}')
        return (true);
    return (false);
}
 
// Returns 'true' if the character is an OPERATOR.
bool isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' ||  
        ch == '/' || ch == '>' || ch == '<' ||
        ch == '=')
        return (true);
    return (false);
}
 
// Returns 'true' if the string is a VALID IDENTIFIER.
bool validIdentifier(char* str)
{
    if (str[0] == '0' || str[0] == '1' || str[0] == '2' ||
        str[0] == '3' || str[0] == '4' || str[0] == '5' ||  
        str[0] == '6' || str[0] == '7' || str[0] == '8' ||  
        str[0] == '9' || isDelimiter(str[0]) == true)
        return (false);
    return (true);
}
 
// Returns 'true' if the string is a KEYWORD.
bool isKeyword(char* str)
{
    if (!strcmp(str, "if") || !strcmp(str, "else") ||
        !strcmp(str, "while") || !strcmp(str, "do") ||  
        !strcmp(str, "break") || !strcmp(str, "for") || 
         !strcmp(str, "continue") || !strcmp(str, "int")
        || !strcmp(str, "double") || !strcmp(str, "float")
        || !strcmp(str, "return") || !strcmp(str, "char")
        || !strcmp(str, "case") || !strcmp(str, "char")
        || !strcmp(str, "sizeof") || !strcmp(str, "long")
        || !strcmp(str, "short") || !strcmp(str, "typedef")
        || !strcmp(str, "switch") || !strcmp(str, "unsigned")
        || !strcmp(str, "void") || !strcmp(str, "static")
        || !strcmp(str, "struct") || !strcmp(str, "goto"))
        return (true);
    return (false);
}
 
// Returns 'true' if the string is an INTEGER.
bool isInteger(char* str)
{
    int i, len = strlen(str);
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2'
            && str[i] != '3' && str[i] != '4' && str[i] != '5'
            && str[i] != '6' && str[i] != '7' && str[i] != '8'
            && str[i] != '9' || (str[i] == '-' && i > 0))
            return (false);
    }
    return (true);
}
 
// Returns 'true' if the string is a REAL NUMBER.
bool isRealNumber(char* str)
{
    int i, len = strlen(str);
    bool hasDecimal = false;
 
    if (len == 0)
        return (false);
    for (i = 0; i < len; i++) {
        if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] !='7' && str[i] != '8'&& str[i] != '9' && str[i] != '.' ||  
            (str[i] == '-' && i > 0))
            return (false);
        if (str[i] == '.')
            hasDecimal = true;
    }
    return (hasDecimal);
}
 
// Extracts the SUBSTRING.
char* subString(char* str, int left, int right)
{
    int i;
    char* subStr = (char*)malloc(sizeof(char) * (right - left + 2));
    for (i = left; i <= right; i++)
        subStr[i - left] = str[i];
    subStr[right - left + 1] = '\0';
    return (subStr);
}
 
// Parsing the input STRING.
void yylex(char* str)
{
    int low = 0, high = 0;
    int len = strlen(str);
 
    while (high <= len && low <= high)
     {
        if (isDelimiter(str[high]) == false)
            high++;
        if (isDelimiter(str[high]) == true && low == high)
         {
            if(isOperator(str[high]) == true && isOperator(str[high+1]) == true && str[high] == str[high+1])
            {
                    printf("'%c%c' is an OPERATOR and the id is %d\n", str[high],str[high],OPERATOR_TOK);
                    high++;
            }
            if (isOperator(str[high]) == true)
                printf("'%c' is an OPERATOR and the id is %d\n", str[high],OPERATOR_TOK);

            else if(str[high]!=' ')
               printf("'%c' is an Delimiter and the id is %d\n", str[high],DELIM_TOK);

            high++;
            low = high;
        }
	
        else if (isDelimiter(str[high]) == true && low != high || (high == len && low != high))
          {
            char* subStr = subString(str, low, high - 1);
           
            if (isKeyword(subStr) == true)
                printf("'%s' is a KEYWORD and the id is %d\n", subStr,KEYWORD_TOK);
 
            else if (isInteger(subStr) == true)
                printf("'%s' is an INTEGER and the id is %d\n", subStr,INT_TOK);
 
            else if (isRealNumber(subStr) == true)
                printf("'%s' is a REAL NUMBER\n", subStr);
 
            else if (validIdentifier(subStr) == true && isDelimiter(str[high - 1]) == false)
                printf("'%s' is a VALID IDENTIFIER and the id is %d\n", subStr,ID_TOK);
 
            else if (validIdentifier(subStr) == false && isDelimiter(str[high - 1]) == false)
                printf("'%s' is not a VALID IDENTIFIER\n", subStr);
            low = high;
        }
    }
    return;
}
 

int main()
{
  int l;
  char str[1000],ch;
  FILE * fp;
  fp=fopen("lex1.c","r");  
  if (fp == NULL)
  {
     printf("Error while opening the file.\n");
     exit(1);
  }

  l=0;
  while(1)//reading the lex file
  {
     ch=fgetc(fp);
     if(ch!=EOF)
      {
        if(ch!='\n')
        str[l++]=ch;
      }
    if(ch==EOF)
      break;
  }

   str[l]='\0';
   yylex(str);
}

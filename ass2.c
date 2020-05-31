#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#define ID_TOK 1
#define KEY_TOK 2
#define INCR_TOK 3
#define DCR_TOK 4
#define GET 5
#define LET 6
#define ET 7
#define NET 8
#define AND 9
#define OR 10
#define NUM_TOK 11
#define STR_TOK 12

FILE *yyin;
char str[100];

char nextchar()
{
  return((char)fgetc(yyin));
}

int fail()
{
  return -1;
}
  
bool isletter(char c)
{
 if((c>=65 && c<=90) || (c>=97 && c<=122))
     return (true);
 return (false);
}

bool isDigit(char c)
{
 if(c>=48 && c<=57)
   return (true);
 return (false);
}

bool isKeyword(char* str) 
{ 
    if (!strcmp(str, "if") || !strcmp(str, "else") || 
        !strcmp(str, "while") || !strcmp(str, "do") ||  
        !strcmp(str, "break") || !strcmp(str, "for") ||
         !strcmp(str, "continue") || !strcmp(str, "int") 
        || !strcmp(str, "double") || !strcmp(str, "float") 
        || !strcmp(str, "return") || !strcmp(str, "char") 
        || !strcmp(str, "case") 
        || !strcmp(str, "sizeof") || !strcmp(str, "long") 
        || !strcmp(str, "short") || !strcmp(str, "typedef") 
        || !strcmp(str, "switch") || !strcmp(str, "unsigned") 
        || !strcmp(str, "void") || !strcmp(str, "static") 
        || !strcmp(str, "struct") || !strcmp(str, "goto")) 
        return (true); 
    return (false); 
} 

bool isdelimiter(char ch) 
{ 
    if (ch == ',' || ch == ';' || ch == '(' || ch == ')' ||  
        ch == '[' || ch == ']' || ch == '{' || ch == '}') 
        return (true); 
    return (false); 
} 
  
int yylex()
{
  int state=0;
  char c;
  int i=0;
  while(1){
    switch(state){
      case 0: c = nextchar();
        if(c==EOF)
         return 0;
        if (c== ' ' || c== '\t' || c=='\n'){
        state = 0;
        }
        else if (c == '+') state = 1;
        else if (c == '-') state = 2;
        else if (c == '*') return '*';
        else if (c == '/') return '/';
        else if (c == '%') return '%';
        else 
            {
              state = 3;
              fseek(yyin,-1,SEEK_CUR);
             }
        break;
      case 1:c=nextchar();
             if(c=='+')
                return INCR_TOK;
             fseek(yyin,-1,SEEK_CUR);
             return '+';
      case 2:c=nextchar();
             if(c=='-')
                return DCR_TOK;
             return '-';
      case 3: c = nextchar();
               if (isletter(c))
               {
                 state = 4;
                 str[i]=c;
                 i++;
               }
               else
                {
                  state = 5;
                  fseek(yyin,-1,SEEK_CUR);
                 }
               break;
      case 4: c = nextchar();
              if (isletter(c)||isDigit(c))
              {
                state = 4;
                str[i]=c;
                i++;
              }
              else 
              {
               fseek(yyin,-1,SEEK_CUR);
               str[i]='\0';
               if(isKeyword(str))
                 return KEY_TOK;
               else
                 return ID_TOK;
               }
              break;
      case 5:c=nextchar();
             if(isDigit(c))
             {
               state=6;
               str[i]=c;
               i++;
              }
              else
              {
                fseek(yyin,-1,SEEK_CUR);
                state=7;
              }
              break;
     case 6:c=nextchar();
            if(isDigit(c))
            {
              state = 6;
              str[i]=c;
              i++;
             }
             else if(isletter(c))
               state=fail();
             else
             {
               fseek(yyin,-1,SEEK_CUR);
               str[i]='\0';
               return NUM_TOK;
               }
              break;
     
     case 7:c=nextchar();
            if(c=='>')
              state=8;
            else if(c=='<')
              state=9;
            else if(c=='=')
              state=10;
            else if(c=='!')
              state=11;
            else if(c=='&')
              state=12;
            else if(c=='|')
              state=13;
            else if(c=='\"')
              state=14;
            else if(isdelimiter(c))
	    {
		printf("Delimiter");
              return c;
	    }
            break;
     case 8:c=nextchar();
            if(c=='=')
              return GET;
            else
              {
                 fseek(yyin,-1,SEEK_CUR);
                 return '>';
              }
            break;
    case 9: c=nextchar();
            if(c=='=')
              return LET;
            else
              {
                 fseek(yyin,-1,SEEK_CUR);
                 return '<';
              }
             break;
    case 10:c=nextchar();
            if(c=='=')
              return ET;
            else
              {
                 fseek(yyin,-1,SEEK_CUR);
                 return '=';
               }
             break;
    case 11:c=nextchar();
            if(c=='=')
              return NET;
            else
              {
                 fseek(yyin,-1,SEEK_CUR);
                 return '!';
               }
             break;
    case 12:c=nextchar();
            if(c=='&')
              return AND;
            else
            {
               fseek(yyin,-1,SEEK_CUR);
               return '&';
             }
    case 13:c=nextchar();
            if(c=='|')
              return OR;
            else
            {
              fseek(yyin,-1,SEEK_CUR);
              return '|';
             } 
    case 14:c=nextchar();
            if(c=='\"')
            {
              str[i]='\0';
              return STR_TOK;
             }
            else
            {
              str[i]=c;
              i++;
            }    

}
}
}
void print(int token)
{
  if(token==1)
  {
    printf("Identifier ");
    puts(str);
  }
  else if(token==2)
  {
    printf("Keyword ");
    puts(str);
  }
  else if(token==3)
    printf("Operator ++\n");
    
  else if(token==4)
    printf("Operator --\n");
  else if(token==5)
    printf("Operator >=\n");
  else if(token==6)
    printf("Operator <=\n");
  else if(token==7)
    printf("Operator ==");
  else if(token==8)
    printf("Operator !=");
  else if(token==9)
    printf("Operator &&");
  else if(token==10)
    printf("Operator ||");
  else if(token==11)
  {
    printf("Integer ");
    puts(str);
  }
  else if(token==12)
  {
    printf("String ");
    puts(str);
  }
  else if(token==-1)
    printf("Invalid Identifier\n");
  else
    printf("%c\n",token);
  
}
   
void main(int argc, char *argv[])
{
   int token;
   if (argc != 2)
   {
      printf("enter the filename");
    }
   else
   {
     yyin = fopen(argv[1], "r");
     while(!feof(yyin))
     {
      token = yylex();
      print(token); 
     }
     fclose(yyin);
   }
}


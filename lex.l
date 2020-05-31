%{
#include<stdio.h>
#include "tokendef_LEX.h"

%}
%option noyywrap
digit     [0-9]

%%
{digit}+                            {return(NUM_TOK);}
[.]                                {return(PT_TOK);}
[;]                                {return(SEMICOLON_TOK);}
[,]                               {return COMMA_TOK;}
[\{]                              {return(LCURLY_TOK);}
[\}]                               {return(RCURLY_TOK);}
[\(]                 {return(LPAREN_TOK);}
[\)]                 {return(RPAREN_TOK);}
[\[]                               {return(LSQBKT_TOK);}
[\]]                               {return(RSQBKT_TOK);}
[\\n]                              {return(NXT_LINE_TOK);}
int                              {return(INT_TOK);}
void                             {return(VOID_TOK);}
char                             {return(CHAR_TOK);}
float                            {return(FLOAT_TOK);}
main                             {return(MAIN_TOK);}
for                              {return(FOR_TOK);}
([a-z]|[A-Z])([a-z]|[A-Z]|[0-9])* {return (ID_TOK);}
[=]                   {return(EQ_TOK);}
[>]                   {return(GT_TOK);}
[<]                   {return(LT_TOK);}
[+]                  {return(PLUS_TOK);}
[-]                  {return(MINUS_TOK);}
[*]                  {return(MUL_TOK);}
[/]                  {return(DIV_TOK);}

%%

int main(int argc, char* argv[])
{
    int val;
   
    if(argc==2){
        yyin = fopen(argv[1],"r");
    }
    
   
    while((val = yylex()) > 0)
    {
       
        printf("Token ===%s; Token ID ====%d\n", yytext, val);
       
    }
   
    return(0);
}



/**
WRITE A FLEX PROGRAM THAT WILL RECOGNIZE VALID IDENTIFIERS HAVING ALL THE PRE-REQUISITES
*/
%{

%}


%%
([a-zA-Z_][a-zA-Z0-9_]*) { printf("The word is a valid identifier\n");return 0;} 
. {printf("the word is an invalid identifier\n");return 0;} 

%%
main(int argc, char **argv) 
{
yylex();
}




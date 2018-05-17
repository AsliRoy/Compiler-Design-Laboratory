/**
*WRITE A FLEX PROGRAM THAT WILL IDENTIFY CHARACTER AND STRING CONSTANTS AS DEFINED IN C LANGUAGE
*/
%{

%}


%%
\"(\\.|[^"\\])*\" {printf("String constants\n");} /** *FOR STRING CONSTANTS */
\'(\\.|[^"\\])\' {printf("Character constants\n");} /** *FOR CHARACTER CONSTANTS */

%%
main(int argc, char **argv) /** *BEGINNING OF THE MAIN FUNCTION */
{
yylex();
}




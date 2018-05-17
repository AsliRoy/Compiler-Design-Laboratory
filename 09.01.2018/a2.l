/**
*WRITE A FLEX APPLICATION THAT WILL RECOGNIZE STRINGS OF ODD NUMBERS OF ZEROS AND EVEN NUMBERS OF ONES
*/
%{
int noz=0;
int noo=0;
%}
%%
[0] {noz++;}
[1] {noo++;}
. {printf("invalid");}

%%

main(int argc, char **argv) /** *BEGINNING OF THE MAIN FUNCTION */
{
yylex();
if(noz%2 !=0 && noo%2==0)
printf("This is a valid string\n");
else 
printf("This is an invalid string\n");
}






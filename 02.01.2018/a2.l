%{

%};

%%
[a-zA-Z_]+[a-zA-Z_0-9]* {printf("Valid identifier");return 0;}
[-,.;:+*@$%/] {printf("Invalid identifier");return 0;}
. {printf("Invalid identifier");return 0;}
%%


main(int argc, char **argv)
{
  yylex();


}

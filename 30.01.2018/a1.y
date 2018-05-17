%{
#include <stdio.h>
int yylex();

void yyerror(const char *s);

extern int flag;
%}


%token D ID E CO EOL I X Y
%%
S:
| D ID X Z Y E { printf(" The given function declaration is correct  \n"); return 0;} 
| D F E EOL{ if(flag==0)printf(" The given variable declaration is correct  \n"); else printf("The given variable declaration is incorrect \n"); return 0;}
| D EOL{printf("Incorrect\n Incomplete Statement \n"); return 0;}
| D F EOL{printf("Incorrect\n Incomplete Statement \n" ); return 0;}
| D IN F IN E EOL 
;
Z: D ID CO Z { } 
| D ID { }
| { }
;
F: ID CO F {  }
| ID {  }
;
IN: I {  }
;
%%

main(int argc, char **argv) {
    yyparse();
}

void yyerror(const char *s) {
	printf("%s \n", s);
}

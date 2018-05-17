/* T3 */
%{
#include "a1.tab.h"
#include <string.h>
extern int yylex(void);

int yylval;
int count = 0;

char cc[100][100];
int n = 0;
int c = 0;
int i;
int l;
int flag=0;
%}

%%
("int")|("float")|("char")|("void") { return D;}
[ ][a-zA-Z_][a-zA-Z0-9]* {  
	c=1;
	for(i=0;i<n;i++){
    		if(strcmp(cc[i],yytext)==0){
			printf("Identifier Already Declared\n");
			c=0;
			flag=1;
		}
	}
	if(c==1){
		strcpy(cc[n],yytext);
		n=n+1;
		count++;
	}
	return ID;
}
"(" {return X;}
")" {return Y;}
";" { return E;}
"," { return CO;}
[\n] { return EOL;}
[ \t] { }
. { printf("Invalid Identifier\n");
	return I;}
%%

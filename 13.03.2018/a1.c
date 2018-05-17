#include<stdio.h>
#include<string.h>
char str[50];//user input string,a proposition logic expression
char lex[50];//stores the output of lex_ana 
char token[50];
char postfix[50];//holds the postfix expression
char stack[50];//stack used for parsing,postfix generation and evaluation
int lex_ana();//token generation 
int syn_ana();//syntax analysis with the help of an LR(0) parser.
unsigned long int mask[130];//masks out the bit position of a variable
char var[20];//holds the variable names
int lex_ana()
{
    char*p,*q,*t;
	int i,j,flag=1;
	p=str;
	q=lex;
	t=token;
	for(i=1,j=1;*p;i++)
	   {

          if(((*p>='A')&&(*p<='Z'))||((*p>='a')&&(*p<='z')))
               *q++=*p++,*t++='i';
		  else
          if((*p==')')||(*p=='(')||(*p=='~'))
			       *t++=*q++=*p++;
		  else
           if((*p=='/')&&(*(p+1)=='\\'))
			*t++=*q++='.',p+=2;
		   else
           if((*p=='\\')&&(*(p+1)=='/'))
			 *t++=*q++='+',p+=2;
		   else
           if((*p=='-')&&(*(p+1)=='>'))
			 *t++=*q++='*',p+=2;
		   else
           if((*p=='<')&&(*(p+1)=='-')&&(*(p+2)=='>'))
			  *t++=*q++='/',p+=3;
           else
		   {
			   printf("\nLexical Error:%d.At position %d,%c is an invalid token.",j,i,*p);  
                flag=0;
				p++;j++;
           }
  
	   } 
		   *t++=*q++='$';
		   *t=*q='\0';
return flag;
}
int syn_ana()
{
  int j,prev,k,l;
  char*p,*top,S[50],A[50],B[20];
  char sym,q='0';
  int pos=1,error=0,t=0,state=0,accept=0;
   p=token;top=stack;*top=0;prev=0;
  printf("\nSTACK                               STRING              ACTION\n");
   for(sym=*p,state=0,j=0;!accept;j++)
  {  
	 printf("\n");	  
    for(k=0,l=0;(stack+k)<=top;k++)
	{
	   if((stack[k]>=0)&&(stack[k]<=14))
	   {
	       if(stack[k]>9)
			   S[l++]='1';
		   S[l++]=q+stack[k]%10;
	   }

		   // printf("%d",stack[k]);
	   else
       if(stack[k]=='.')
         S[l++]='/',S[l++]='\\'; // printf("/\\");
	   else
       if(stack[k]=='+')
		  S[l++]='\\',S[l++]='/';//printf("\\/");
	    else
       if(stack[k]=='*')
		  S[l++]='-',S[l++]='>'; //printf("->");
        else
       if(stack[k]=='/')
		  S[l++]='<',S[l++]='-',S[l++]='>'; //printf("<->");
        else
       if(stack[k]=='i')
		  S[l++]='i',S[l++]='d';// printf("id");
        else
         S[l++]=stack[k];// printf("%c",stack[k]);
   }
 	S[l]='\0';
	for(k=0,l=0;*(p+k);k++)
		{
        if(p[k]=='.')
           A[l++]='/',A[l++]='\\';//printf("/\\");
	   else
       if(p[k]=='+')
		  A[l++]='\\',A[l++]='/'; //printf("\\/");
	    else
       if(p[k]=='*')
		  A[l++]='-',A[l++]='>'; //printf("->");
        else
       if(p[k]=='/')
		   A[l++]='<',A[l++]='-',A[l++]='>';//printf("<->");
        else
       if(p[k]=='i')
         A[l++]='i',A[l++]='d'; //printf("id");
	   else
        if((p[k]=='$')||(p[k]=='(')||(p[k]==')'))
		  A[l++]=p[k];//printf("%c",p[k]);
   	}
		A[l]='\0';
    //printf("\t%-10s",A);
	   switch(state)
	   {
	      case 0:
			  
			switch(sym)
			{
			 case 'E':*(++top)=1;t++;state=1;sym=*p;sprintf(B,"goto  1");break;
             case 'T':*(++top)=2;t++;state=2;sym=*p;sprintf(B,"goto  2");break;
             case '(':*(++top)='(';*(++top)=4;pos++;state=4;sprintf(B,"Shift   (,goto  4");*p=' ';sym=*(++p);break;
             case 'i':*(++top)='i';*(++top)=5;pos++;state=5;sprintf(B,"Shift  id,goto  5");*p=' ';sym=*(++p);break;
             case '~':*(++top)='~';*(++top)=3;pos++;state=3;sprintf(B,"Shift   ~,goto  3");*p=' ';sym=*(++p);break;
            /*error handler*/
			 case ')':printf("Parse Error %d at position 
No ( for ).\n",++error,pos++);break;
             case '$':printf("Parse Error %d at position 
Incomplete expression.\n",++error,pos++);break;
             case '+' :printf("Parse Error %d at position 
Left side operand of binary operator /\\ not found.\n",++error,pos++);break;
             case '.' :printf("Parse Error %d at position 
Left side operand of binary operator \\/ not found.\n",++error,pos++);break;
             case '*' :printf("Parse Error %d at position 
Left side operand of binary operator -> not found.\n",++error,pos++);break;
             case '/' :printf("Parse Error %d at position 
Left side operand of binary operator <-> not found.\n",++error,pos++);
			}
        break;
		case 1:
			switch(sym)  
			{
             case '$':*(++top)='$';*(++top)=6;pos++;state=6;sprintf(B,"Shift   $,goto  6");*p=' ';sym=*(++p);break;             
			 case '.':*(++top)='.';*(++top)=7;pos++;state=7;sprintf(B,"Shift /\\,goto  7");*p=' ';sym=*(++p);break;
             case '+':*(++top)='+';*(++top)=8;pos++;state=8;sprintf(B,"Shift \\/,goto  8");*p=' ';sym=*(++p);break;
             case '*':*(++top)='*';*(++top)=9;pos++;state=9;sprintf(B,"Shift  ->,goto  9");*p=' ';sym=*(++p);break;
             case '/':*(++top)='/';*(++top)=10;pos++;state=10;sprintf(B,"Shift   <->,goto 10");*p=' ';sym=*(++p);break;
			 /*error handler*/
             case ')':printf("Parse Error %d at position 
( missing for ).\n",++error,pos++);break;
			 default :printf("Parse Error %d at position 
Binary operator missing.\n",++error,pos++);
			}
        break;
			case 2://reduce by E->T
				*(--top)='E';state=*(top-1);t--;sym='E';sprintf(B,"Reduce by E->T");
		break;		
			case 3:
     		  switch(sym)
			  {		
                 case 'T':*(++top)=11;t++;state=11;sprintf(B,"goto  11");sym=*p;break;
                 case '(':*(++top)='(';*(++top)=4;pos++;state=4;sprintf(B,"Shift   (,goto  4");*p=' ';sym=*(++p);break;
                 case 'i':*(++top)='i';*(++top)=5;pos++;state=5;sprintf(B,"Shift  id,goto  5");*p=' ';sym=*(++p);break;
                 case '~':*(++top)='~';*(++top)=3;pos++;state=3;sprintf(B,"Shift   ~,goto  3");*p=' ';sym=*(++p);break;
			     /*error handler*/
				 case '$':printf("Parse Error %d at position 
Incomplete expression.\n",++error,pos++);break;
			     default :printf("Parse Error %d at position 
Operand of Unary operator ~ missing.\n",++error,pos++); 			
              }
		break;
			 case 4:
				    switch(sym)
					{
                      case '(':*(++top)='(';*(++top)=4;pos++;state=4;sprintf(B,"Shift   (,goto  4");*p=' ';sym=*(++p);break;
                      case '~':*(++top)='~';*(++top)=3;pos++;state=3;sprintf(B,"Shift   ~,goto  3");*p=' ';sym=*(++p);break;
                      case 'i':*(++top)='i';*(++top)=5;pos++;state=5;sprintf(B,"Shift  id,goto  5");*p=' ';sym=*(++p);break;
           			  case 'E':*(++top)=12;t++;state=12;sprintf(B,"goto  12");sym=*p;break;
                      case 'T':*(++top)=2;t++;state=2;sprintf(B,"goto  2");sym=*p;break;
        			  /*error handler*/
					  case '+':printf("Parse Error %d at position 
Left operand of \\/ missing.\n",++error,pos++);break;
					  case '.':printf("Parse Error %d at position 
Left operand of /\\ missing.\n",++error,pos++);break;
					  case '*':printf("Parse Error %d at position 
Left operand of ->  missing.\n",++error,pos++);break;
					  case '/':printf("Parse Error %d at position 
Left operand of <-> missing.\n",++error,pos++);break;
					  case '$':printf("Parse Error %d at position 
Incomplete expression.\n",++error,pos++);break;
					  case ')':printf("Parse Error %d at position 
No expression between ().\n",++error,pos++);
					}
        break;
			 case 5://reduce by T->i
				 *(--top)='T';state=*(top-1);t--;sym='T';sprintf(B,"Reduce by T->id");
		break;
			 case 6://accept
				 accept=1;sprintf(B,"Accept.");
		break;  
             case 7: case 8: case 9: case 10:
                    switch(sym)
					{
					 case 'T':*(++top)=13;state=13;sprintf(B,"goto  13");sym=*p;break;
                     case '(':*(++top)='(';*(++top)=4;pos++;state=4;sprintf(B,"Shift   (,goto  4");*p=' ';sym=*(++p);break; 
                     case 'i':*(++top)='i';*(++top)=5;pos++;state=5;sprintf(B,"Shift  id,goto  5");*p=' ';sym=*(++p);break;
                     case '~':*(++top)='~';*(++top)=3;pos++;state=3;sprintf(B,"Shift   ~,goto  3");*p=' ';sym=*(++p);break;//NEW
                      /*error handler*/
                     case ')':printf("Parse Error %d at position 
Right side operand of binary operator missing.\n",++error,pos++);break;
                     case '$':printf("Parse Error %d at position 
Incomplete expression.\n",++error,pos++);break;
                     default :printf("Parse Error %d at position 
Two consecutive binary operators.\n",++error,pos++);
					}
        break;
			 case 11://reduce by T->~T		
				 top-=3;t-=3;*top='T',state=*(top-1);sym='T';sprintf(B,"Reduce by T->~T");
		break;     
			 case 12:
				 switch(sym)
				 {
                  case '.':*(++top)='.';*(++top)=7;t+=2;state=7;sprintf(B,"Shift   /\\,goto  7");*p=' ';sym=*(++p);break;
                  case '+':*(++top)='+';*(++top)=8;pos++;state=8;sprintf(B,"Shift  \\/,goto  8");*p=' ';sym=*(++p);break;
                  case '*':*(++top)='*';*(++top)=9;pos++;state=9;sprintf(B,"Shift   ->,goto  9");*p=' ';sym=*(++p);break;
                  case '/':*(++top)='/';*(++top)=10;pos++;state=10;sprintf(B,"Shift   <->,goto  10");*p=' ';sym=*(++p);break;
                  case ')':*(++top)=')';*(++top)=14;pos++;state=14;sprintf(B,"Shift   ),goto  14");*p=' ';sym=*(++p);break;
				 /*error handler*/
				  case '~': case '(':
					       printf("Parse Error %d at position 
Binary operator missing.\n",++error,pos++);break;
				  case 'i':printf("Parse Error %d at position 
Binary operator or ) missing.\n",++error,pos++);break;
                  case '$':printf("Parse Error %d at position 
Incomplete expression.\n",++error,pos++);
                 }
		break;
			 case 13://reduce by E->E/\T,E->E\/T,E->E->T,E->E<->T
				 //printf(B,"Reduce by E->E");
			    B[0]='R',B[1]='e',B[2]='d',B[3]='u',B[4]='c',B[5]='e',B[6]=' ',B[7]='b',B[8]='y';
				B[9]=' ',B[10]='E',B[11]='-',B[12]='>',B[13]='E';
				 if(*(top-3)=='.')
				  B[14]='/',B[15]='\\',B[16]='T',B[17]='\0';//printf("/\\");
					 else
			     if(*(top-3)=='+')
                   B[14]='\\',B[15]='/',B[16]='T',B[17]='\0';//printf("\\/");
					 else
                 if(*(top-3)=='*')
					  B[14]='-',B[15]='>',B[16]='T',B[17]='\0';//printf("->");
					 else
                      B[14]='<',B[15]='-',B[16]='>',B[17]='T',B[18]='\0';//printf("<->");
                 //printf("T");
				 top-=5;t-=5;*top='E',state=*(top-1);sym='E';				
		break;		
             case 14://reduce by T->(E)
				 top-=5;t-=5;*top='T',state=*(top-1);sym='T';sprintf(B,"Reduce by T->(E)");break;
			}
			printf("%-35s %-15s %s",S,A,B);
   if((!(*p))&&(error)) break;
   else
   if(prev<error){state=0;top=stack;prev=error;sym=*(++p);}
  }
  return error;
}
int main()
{
 int i;
 printf("LR(0) PARSER BASED ON THE GRAMMAR G=(V,T,R,S) \n\n V={S,E,T} T={id,~,/\\,\\/,(,),->,<->}\n\n");
 printf("R={S->E$ ,E->T , E->E/\\T , E->E\\/T , E->E->T , E->E<->T ,T->(E) ,T->~T ,T->id}\n\n");
 
  //printf("Enter an logic expression(w.f.f.):");
  //scanf("%s",str);
  strcpy(str,"((a/\\b\\/c)->(d/\\~e))<->(~f->(g/\\h)/\\~i<->j/\\k\\/l)");
  printf("Evaluating string: %s\n",str);
  for(i=1;i<=1000;i++)
  { 
  if(lex_ana())
   {
	  if(!syn_ana())
	   printf("\n\nThe given expression is a valid w.f.f."); 
	  else
	   printf("\nThe given expression is not a w.f.f.");
   }
   printf("\n%d\n",i);
  }
 return 0;
}


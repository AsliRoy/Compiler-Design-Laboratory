%{
	int sum = 0;
%}

%%
"zero"			{sum+=0;}
"one"			{sum+=1;}
"two"			{sum+=2;}
"three"			{sum+=3;}
"four"			{sum+=4;}
"five"			{sum+=5;}
"six"			{sum+=6;}
"seven"			{sum+=7;}
"eight"			{sum+=8;}
"nine"			{sum+=9;}
"hundred"		{sum*=100;}
"ten"			{sum+=10;}
"eleven"		{sum+=11;}
"twelve"		{sum+=12;}
"thirteen"		{sum+=13;}
"fourteen"		{sum+=14;}
"fifteen"		{sum+=15;}
"sixteen"		{sum+=16;}
"seventeen"		{sum+=17;}
"eighteen"		{sum+=18;}
"nineteen"		{sum+=19;}
"twenty"		{sum+=20;}
"thirty"		{sum+=30;}
"forty"			{sum+=40;}
"fifty"			{sum+=50;}
"sixty"			{sum+=60;}
"seventy"		{sum+=70;}
"eighty"		{sum+=80;}
"ninety"			{sum+=90;}
			

%%

main(int argc, char **argv)
{
	yylex();
	if((sum>=0) && (sum<=999))
		printf("correct%8d\n", sum);
	else
		printf("incorrect%8d\n", sum);


}


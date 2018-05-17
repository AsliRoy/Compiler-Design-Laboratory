#include "ctype.h"
#include "string.h"
#include "stdio.h"
char gram[10][10];
char vFirst[10];
char nonT[10];
char vFollow[10];
int m = 0;
int p;
int i = 0;
int j = 0;
int elem[10];
int size;
int fPt;
int k = 0;
int getGram() {
char ch;
int i;
int j;
int k;
printf("\nEnter Number of Rule : ");
scanf("%d", &size);
printf("\nEnter Grammar as E=E+B \n");
for(i = 0; i < size; i++){
scanf("%s%c", gram[i], &ch);
elem[i] = strlen(gram[i]);
}
}
int funcFirst(char victim){
int j;
int i;
if(!(isupper(victim)))
vFirst[k++] = victim;
else {
for(j = 0; j < size; j++) {if(gram[j][0] == victim) {
if(gram[j][2] == '$')
vFirst[k++] = '$';
else if(islower(gram[j][2]))
vFirst[k++] = gram[j][2];
else
funcFirst(gram[j][2]);
}
}
}
}
void funFollow(char);
void first(char victim) {
int k;
if(!(isupper(victim)))
vFollow[m++] = victim;
for(k = 0; k < size; k++) {
if(gram[k][0] == victim) {
if(gram[k][2] == '$')
funFollow(gram[i][0]);
else if(islower(gram[k][2]))
vFollow[m++] = gram[k][2];
else
first(gram[k][2]);
}
}
}
void funFollow(char victim) {
if(gram[0][0] == victim)
vFollow[m++] = '$';
for(i = 0; i < size; i++) {
for(j = 2; j < strlen(gram[i]); j++) {
if(gram[i][j] == victim) {
if(gram[i][j+1] != '\0')
first(gram[i][j+1]);if(gram[i][j+1] == '\0' && victim != gram[i][0])
funFollow(gram[i][0]);
}
}
}
}
int main() {
int i;
int j;
int l = 0;
getGram();
for(i = 0; i < size; i++) {
for (j = 0; j < i; j++) {
if (gram[i][0] == gram[j][0])
break;
}
if (i == j) {
nonT[l] = gram[i][0];
l++;
}
}
for(i = 0; i < l; i++) {
k = 0;
funcFirst(nonT[i]);
printf("\nFIRST(%c){ ", nonT[i]);
for(j = 0; j < strlen(vFirst); j++)
printf(" %c", vFirst[j]);
printf(" }\n");
}
int s = 0;
for(s = 0; s < l; s++) {
m = 0;
printf("\nFOLLOW(%c){ ", nonT[s]);
funFollow(nonT[s]);
for(i = 0; i < m; i++)
printf("%c ", vFollow[i]);
printf(" }\n");
}
}

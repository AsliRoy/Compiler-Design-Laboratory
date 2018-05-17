#include <bits/stdc++.h>
using namespace std;

struct production
{
            char lf;
            char rt[10];
            int prod_rear;
            int fl;
};
struct production prodn[20],prodn_new[20];     //Creation of object

//Variables Declaration for left factoring
 
int b=-1,d,q,f,n,m=0,c=0;
char terminal[20],nonterm[20],alpha[10],extra[10];
char epsilon='^';

void left_fact(vector<string > &prod, int n)
{
   int cnt, cnt3;
   char lp;
   string d = "->";
   //Input of Productions
   cout<<"Note: Here ^ denotes epsillon\n";
   for(cnt=0;cnt<=n-1;cnt++)
   {
     int pos = prod[cnt].find(d);
     lp = prod[cnt][0];
     prodn[cnt].lf = lp;
     for(int i=pos+2; i<=prod[cnt].length()-1; i++)
     {
     	prodn[cnt].rt[i-(pos+2)] = prod[cnt][i];
     }
     prodn[cnt].prod_rear=strlen(prodn[cnt].rt);
     prodn[cnt].fl=0;
   }

   //Condition for left factoring
   int cnt1 = 0, cnt2 = 0;
   for(cnt1=0;cnt1<n;cnt1++)
   {
     for(cnt2=cnt1+1;cnt2<n;cnt2++)
     {
            if(prodn[cnt1].lf==prodn[cnt2].lf)
            {
              cnt=0;
              int p=-1;
              while((prodn[cnt1].rt[cnt]!='\0')&&(prodn[cnt2].rt[cnt]!='\0'))
              {
                if(prodn[cnt1].rt[cnt]==prodn[cnt2].rt[cnt])
                {
                  extra[++p]=prodn[cnt1].rt[cnt];
                  prodn[cnt1].fl=1;
                  prodn[cnt2].fl=1;
                }
                else
                {
                  if(p==-1)
                          break;
                  else
                  {
                          int h=0,u=0;
                          prodn_new[++b].lf=prodn[cnt1].lf;
                          strcpy(prodn_new[b].rt,extra);
                          //prodn_new[b].rt[p+1]=alpha[c];
                          prodn_new[b].rt[p+1]=prodn[cnt1].lf;
                          //prodn_new[++b].lf=alpha[c];
                          prodn_new[++b].lf=prodn[cnt1].lf;
                          for(q=cnt;q<prodn[cnt2].prod_rear;q++)
                           prodn_new[b].rt[h++]=prodn[cnt2].rt[q];
                           //prodn_new[++b].lf=alpha[c];
                           prodn_new[++b].lf=prodn[cnt1].lf;
                          for(q=cnt;q<=prodn[cnt1].prod_rear;q++)
                           prodn_new[b].rt[u++]=prodn[cnt1].rt[q];
                           m=1;
                           break;
                   }
                 }
                 cnt++;
               }
               if((prodn[cnt1].rt[cnt]==0)&&(m==0))
               {
                         int h=0;
                         prodn_new[++b].lf=prodn[cnt1].lf;
                         strcpy(prodn_new[b].rt,extra);
                         //prodn_new[b].rt[p+1]=alpha[c];
                         prodn_new[b].rt[p+1]=prodn[cnt1].lf;
                         //prodn_new[++b].lf=alpha[c];
                         prodn_new[++b].lf=prodn[cnt1].lf;
                         prodn_new[b].rt[0]=epsilon;
                         //prodn_new[++b].lf=alpha[c];
                         prodn_new[++b].lf=prodn[cnt1].lf;
                         for(q=cnt;q<prodn[cnt2].prod_rear;q++)
                         prodn_new[b].rt[h++]=prodn[cnt2].rt[q];
               }
               if((prodn[cnt2].rt[cnt]==0)&&(m==0))
               {
                 int h=0;
                 prodn_new[++b].lf=prodn[cnt1].lf;
                 strcpy(prodn_new[b].rt,extra);
                 //prodn_new[b].rt[p+1]=alpha[c];
                 prodn_new[b].rt[p+1]=prodn[cnt1].lf;
                 //prodn_new[++b].lf=alpha[c];
                 prodn_new[++b].lf=prodn[cnt1].lf;
                 prodn_new[b].rt[0]=epsilon;
                 //prodn_new[++b].lf=alpha[c];
                 prodn_new[++b].lf=prodn[cnt1].lf;
                 for(q=cnt;q<prodn[cnt1].prod_rear;q++)
                  prodn_new[b].rt[h++]=prodn[cnt1].rt[q];
               }
               c++;
               m=0;
             }
       }
    }

   //Display of Output

    cout<<"\n      After Left Factoring       \n";
    cout<<endl;
	for(cnt3=0;cnt3<=0;cnt3++)
            {
                        cout<<"Production "<<cnt3+1<<" is: ";
                        cout<<prodn_new[cnt3].lf;
                        cout<<"->";
                        cout<<prodn_new[cnt3].rt<<"'";
                        cout<<endl<<endl;
            }
    for(cnt3=1;cnt3<=b;cnt3++)
            {
                        cout<<"Production "<<cnt3+1<<" is: ";
                        cout<<prodn_new[cnt3].lf<<"'";
                        cout<<"->";
                        cout<<prodn_new[cnt3].rt;
                        cout<<endl<<endl;
            }
	cnt3 = b+2;
    for(int cnt4=0;cnt4<n;cnt4++)
    {
    if(prodn[cnt4].fl==0)
    {
    cout<<"Production  "<<cnt3<<" is: ";
    cout<<prodn[cnt4].lf;
    cout<<"->";
    cout<<prodn[cnt4].rt;
    cout<<endl<<endl;
    cnt3++;
    }
    }	
}
int main()
{
	int n;
	cout<<"Enter number of productions: ";
	cin>>n;
	vector<string > prod(n, "0");
	cout<<"\nEnter the production in the from A->A+B\n";
	int i;
	for(i=0; i<n; i++)
	{
		cin>>prod[i];
	}
	//remove_left_recur(prod, n);
	left_fact(prod, n);
	return 0;
}

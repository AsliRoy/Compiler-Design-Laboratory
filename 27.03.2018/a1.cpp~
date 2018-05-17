#include<bits/stdc++.h>
#include<string>

using namespace std;

char stac[100],val1[100],sym[100];
int val[100];
int top1=-1,top2=-1,top3=-1;
string input;
string line;

void threeAddressCode(){
	int i=0;
	string p;
	while(input[i] != ' ')
	{
	i++;
	}
	for(int k=0;k<i;k++)
	p[k]=input[i];

	cout<<p;

	/*stac[0] = '$';top1=0;top2=-1;
	int x=1;
	vector<vector<string> > v;
	input[input.length()]='$';
	cout<<"Stack\tPlace\tGenerated Code\n---------------------------------\n";
	for(int i=0;i<input.length();i++){
		if(input[i]>='0' && input[i]<='9'){
			stac[top1+1] = 'd';
			top1+=1;
			val[top2+1] = int(input[i])-48;
			top2+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		else{
			stac[top1+1] = input[i];
			top1+=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d' && stac[top1-1]=='I'){
			stac[top1-1] = 'I';
			top1-=1;
			val[top2-1] = 10*val[top2-1] + val[top2];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='d'){
			stac[top1]='I';
			
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='I' && (input[i+1]<'0' || input[i+1]>'9')){
			stac[top1] = 'E';
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]==')' && stac[top1-1]=='E' && stac[top1-2]=='('){
			stac[top1-2]='E';
			top1-=2;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='+' && stac[top1-2]=='E'){
			print_stac();
			cout<<"\t";
			print_val();
			if(x>1)
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" + T"<<x-1;
			else
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" + "<<val[top2];
			x++;
			cout<<endl;
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]+val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		if(stac[top1]=='E' && stac[top1-1]=='*' && stac[top1-2]=='E'){
			print_stac();
			cout<<"\t";
			print_val();
			if(x>1)
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" * T"<<x-1;
			else
				cout<<"\tT"<<x<<" := "<<val[top2-1]<<" * "<<val[top2];
			x++;
			cout<<endl;
			stac[top1-2]='E';
			top1-=2;
			val[top2-1] = val[top2]*val[top2-1];
			top2-=1;
			print_stac();
			cout<<"\t";
			print_val();
			
			cout<<endl;
		}
		if(stac[top1]=='$' && stac[top1-1]=='E'){
			stac[top1-1]='S';
			top1-=1;
			print_stac();
			cout<<"\t";
			print_val();
			cout<<endl;
		}
		
	}*/
}

int main()
{
	cout<<"Enter the input : ";
	while (getline(cin, line))
	{
    		if (line == "^D")
        	break;

    		input += "\n"+line;
	}
	cout<<"Three Address Code Generation for SWITCH-CASE CONSTRUCT\n================================\n\n\n";
	cout<<"The original switch case construct that is input by the user is:\n";
	cout<<input<<"\n";	
	threeAddressCode();
	return 0;
}

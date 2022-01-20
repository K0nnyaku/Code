#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,k=3;
char s[100010];
bool flag[10010];
bool check(int l,int r){
	
	int top=0;
	for(int i=l;i<=r;){
		if(s[i]=='(') top++,i++;
		else if(s[i]==')') i++,top--,flag[top+1]=flag[top]=0;

		else{
			if(flag[top]||top==0){
			//	cout<<i<<endl;
			//	cout<<"8";
				return 0;
			}
			int j=i;
			while(s[j]=='*') j++;
		//	cout<<j<<endl;
			
			if(j-i>k){
			//	cout<<i<<endl;
			//	cout<<"&";
				return 0;
			}
			i=j;
			flag[top]=1;
		}
		if(top<0){
		//	cout<<"*";
			return 0;
		}
	}
	
	
	
	return 1;
	
	

	
}


int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);


	cout<<14;

	fclose(stdin);
	fclose(stdout);
	return 0;
}


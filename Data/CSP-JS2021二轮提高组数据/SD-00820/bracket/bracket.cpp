#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[45]; 
int ans[45];
int m,q,t,n,k;
void jud(char i,int b,int c,int d);
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,ans=0;//m为（个数，q为）个数，t为连续的*个数 
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		cin>>a[i];}
	for(int i=n-1;i>=0;i--){
		if(a[i]=='(')m++;
		else if(a[i]==')')q++;
		else if(a[i]=='*')t++;
		else ans[i]=jud(a[i],m,q,t);
	}
	cout<<ans[n]<<endl;
	return 0;
}
void jud(char i,int b,int c,int d){
	if((n-i)=(m-q))ans[i]=ans[i-1];
	else {
		if(t<k){
			ans[i]=((1+jud(a[i-1],m,q,t++))+(1+jud(a[i-1],m+1,q,t-t))+(1+jud(a[i-1],m,q+1,t-t))+ans[i-1]);
		}
		if(t=k){
			ans[i]=((1+jud(a[i-1],m+1,q,t-t))+(1+jud(a[i-1],m,q+1,t-t)+ans[i-1]);
		}
	}
}

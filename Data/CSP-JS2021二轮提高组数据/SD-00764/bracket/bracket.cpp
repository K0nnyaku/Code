#include<iostream>
#include<cstdio>
using namespace std;
const int MOD=1000000007;
char a[510];
int n,k,ans=0;
void dfs(char p[]){
	int flag=-1,x=0,qu[101]={0},top=0;
	for(int i=0;i<n;i++){
		if(p[i]=='?'){
			flag=i;
			break;
		}
		if(p[i]=='(') {top++; qu[top]=0; x=0; continue;}
		if(p[i]==')') {qu[top]=0; top--;if(top<0) return ; x=0; continue;}
		if(p[i]=='*') {
			if(i==0||i==n-1||x>=k||(qu[top]==1&&p[i-1]!='*')){return ;}
			if(p[i-1]=='(') qu[top]=1;
			x++;
		}
//		for(int j=1;j<=top;j++)
//			cout<<qu[j]<<" @ ";
//		cout<<endl; 
	}
	if(flag==-1){
		if(top!=0) return ;
//		cout<<p<<"     <--"<<endl;
		ans++;
		ans%=MOD;
		return ;
	}
	if(top!=0){
		p[flag]=')';
		dfs(p);
		p[flag]='?';
	}
	if(x<k){
		p[flag]='*';
		dfs(p);
		p[flag]='?';
	}
	p[flag]='(';
	dfs(p);
	p[flag]='?';
	return ;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	dfs(a);
	cout<<ans<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
/*
7 2
???????
*/
/*

*/

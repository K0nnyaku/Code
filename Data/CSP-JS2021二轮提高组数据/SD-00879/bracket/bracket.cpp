#include<bits/stdc++.h>
using namespace std;
long long n,k,ans,mod=1e9+7;
string s;
char t[5005];
void dfs(int ci,int lkh,int rkh,int xh){
	if(xh>k)return ;
	if(lkh<rkh)return ;
	if(s[ci]!='?'){
		dfs(ci+1,lkh,rkh,xh+1);
		return ;
	}
	if(ci+1==n){
		rkh++;
		if(lkh!=rkh)return ;	
		ans++;
		ans%=mod;
		return ;
	}
	t[ci]='(';
	dfs(ci+1,lkh+1,rkh,0);
	t[ci]=')';
	dfs(ci+1,lkh,rkh+1,0);
	t[ci]='*';
	dfs(ci+1,lkh,rkh,xh+1);
	return ;
}
int main(){
	freoepn("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=0;i<n;i++)t[i]=s[i];
	if(s[0]!='?'&&s[0]!='('){
		cout<<0<<endl;
		return 0;
	}
	t[0]='(';t[n-1]=')';
	if(n<=40){
		dfs(1,1,0,0);
		cout<<ans<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

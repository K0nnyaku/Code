#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 505
int a[N],n,k,num1;
ll ans;
int d[4]={0,1,2,3};
void dfs(int now,int t0,int t1,int tk){
	if(tk>k) return;
	if(now==n){
		if(t0==1&&(a[now]==3||a[now]==1))
			ans++;
		return;
	}
	if(tk==k&&a[now]==2) return;
	if(a[now]==0) dfs(now+1,t0+1,t1,0);
	else if(a[now]==1) dfs(now+1,t0-1,t1,0);
	else if(a[now]==2) dfs(now+1,t0,t1,tk+1);
	else dfs(now+1,t0+1,t1-1,0),dfs(now+1,t0-1,t1-1,0),dfs(now+1,t0,t1,tk+1);
	return;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	string s;
	cin>>s;
	for(int i=0;i<n;i++)
		if(s[i]=='?') a[i+1]=3,num1++;
		else if(s[i]=='(') a[i+1]=0;
		else if(s[i]==')') a[i+1]=1;
		else if(s[i]=='*') a[i+1]=2;
	dfs(1,0,num1,0);
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

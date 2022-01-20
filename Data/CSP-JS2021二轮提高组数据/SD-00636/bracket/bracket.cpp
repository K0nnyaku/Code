#include<bits/stdc++.h>
using namespace std;
const int N=510,P=1e9+7;
struct node{
	int nxt;
	char c;
}q[N];
string s;
int n,k,f=-1,h,ans,top;
char st[N];
void judge()
{
	int cnt=0;
	if(s[0]!='('||s[n-1]!=')') return;
	for(int i=0;i<n;i++)
	{ 
	    if(s[i]=='(') st[++top]=s[i];
		if(s[i]==')'){ if(top==-1) return; else top--; } 
	    if(s[i]=='*') cnt++;
		else if(cnt>=k) return;
		else cnt=0;
	}
	if(top) {
		top=0;
		return;
	}
	ans++;
	ans%=P;
}
void dfs(int x)
{
	for(int i=1;i<=3;i++)
	{
		if(i==1) s[x]='(';
		if(i==2) s[x]=')';
		if(i==3) s[x]='*';
		if(x!=f) dfs(q[x].nxt);
		else{judge();}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    scanf("%d %d\n",&n,&k);
    cin>>s;
    for(int i=0;i<n;i++)
    {
    	if(s[i]=='?') {
    		if(f==-1) {f=i;h=i;}
    		else{q[f].nxt=i;f=i;}
    	}	 
	}
	dfs(h);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


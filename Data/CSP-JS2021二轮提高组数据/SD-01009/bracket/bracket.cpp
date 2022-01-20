#include<bits/stdc++.h>
using namespace std;
char ch[500];
int n,k;
long long ans=0;
bool d=true;
void dfs(int m,int cnt1,int cnt2)
{
	for(int i=m;i<n&&d;i++)
	{
		if(cnt2>k&&i-m+1>k)
			d=false;
		if(cnt1<0||cnt2>k)
			break;
		if(ch[i]=='(')
		{
			cnt1++;
			cnt2=0;
		}
		else if(ch[i]==')')
		{
			cnt1--;
			cnt2=0;
		}
		else if(ch[i]=='*')
			cnt2++;
		else if(ch[i]=='?')
		{
			ch[i]='(';
			dfs(i+1,cnt1+1,0);
			ch[i]=')';
			dfs(i+1,cnt1-1,0);
			ch[i]='*';
			dfs(i+1,cnt1,cnt2+1);
			ch[i]='?';
			break;
		}
		if(i==n-1&&cnt1==0)
			ans++;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>ch[i];
	if(ch[0]=='?')
		ch[0]='(';
	else if(ch[0]!='(')
		d=false;
	if(ch[n-1]=='?')
		ch[n-1]=')';
	else if(ch[n-1]!=')')
		d=false;
	if(d)
		dfs(0,0,0);
	cout<<ans%1000000007;
	return 0;
}

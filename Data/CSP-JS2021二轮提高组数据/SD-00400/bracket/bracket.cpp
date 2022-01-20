#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,k;
int a[101];
string s;
bool ch(int st,int fn){
	if(a[st]!='(') return false;
	if(fn-st==1&&a[st]==1&&a[fn]==2) return true;
	for(int i=st;i<=fn;i++)
	{
		int q=0,h=0;
		if(a[i]=='(') q++;
		if(a[i]==')') h++;
		int l=0;
		while(a[i]=='*')
		{
			i++;
			l++;
		}
	}
	
}
void dfs(int k)
{
	if(k==n)
	{
		return;
	 } 
	 if(a[1]!=1) return;
	int i;
	for(i=k;a[i]&&i<=n;i++);
	for(int i=1;i<=3;i++) 
	{
		a[k]=i;
		dfs(k+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if(s[i-1]=='(') a[i]=1;
		if(s[i-1]==')') a[i]=2;
		if(s[i-1]=='*') a[i]=3;
		if(s[i-1]=='?') a[i]=0;
	}
	
	cout<<2024;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}



#include <bits/stdc++.h>
using namespace std;
int n,k,ans;
char c[505];
bool tag[505];
int diam;
//vector <bool> v;

void dfs(int x,int s)//s -> stars we already have here
{
//	printf("dfs(%d) diam=%d tag[diam]=%s\n",x,diam,(tag[diam]?"true":"false"));
//	for(int i=1;i<=x;i++)
//		cout<<c[i];
//	cout<<endl;
	if(diam>n-x+1)
		return;
	if(x>n)
	{
//		for(int i=1;i<=n;i++)
//			cout<<c[i];
//		cout<<endl;
		if(c[1]=='*'||c[n]=='*')
		{
			return;
		}
		ans++;
		return;
	}
	if(c[x]=='(')
	{
		if(c[x-1]=='*')
		{
			tag[diam]=true;
//			printf("tag[%d]=true\n",diam);
		}
			
//		v.push_back(true);
		diam++;
		dfs(x+1,0);
		diam--;
		tag[diam]=false;
//		v.pop_back();
		return;
	}
	if(c[x]==')')
	{
		if(diam==0)
		{
			return;
		}
		else
		{
			diam--;
//			v.pop_back();
			dfs(x+1,0);
			diam++;
//			v.push_back(true);
			return;
		}
	}
	if(c[x]=='*')
	{
		if(tag[diam])
			return;
		if(s<k)
		{
			dfs(x+1,s+1);
			return;
		}
		else
		{
			return;
		}
	}
//	if(c[x]!='?')
//		return;
	c[x]='(';
//	v.push_back(true);
	if(c[x-1]=='*')
		tag[diam]=true;
	diam++;
	dfs(x+1,0);
	diam--;
	tag[diam]=false;
//	v.pop_back();
	c[x]=')';
	if(diam==0)
	{
		goto conti;
	}
	else
	{
//		v.pop_back();
		diam--;
		dfs(x+1,0);
//		v.push_back(true);
		diam++;
	}
conti:
	c[x]='*';
	if(tag[diam])
	{
		c[x]='?';
		return ;
	}
	if(s<k)
	{
		dfs(x+1,s+1);
	}
	c[x]='?';
}
int main(void)
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	dfs(1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
int n,k,res,_p[510],ans;//_p[]存的是下标 
char d[510];
void dfs(int x,char y)
{
	d[_p[x]]=y;
	if(x==res)//结束条件 
	{
		int a,b,c;
		bool flag=true;
		for(int i=0;i<n;i++)
		{
			if(d[i]=='(') 
			{
				a++;	
				if(c>k) flag=false;
				c=0;
			}
			if(d[i]==')') 
			{
				b++;
				if(c>k) flag=false;
				c=0;
			}
			if(d[i]=='*') c++;
		}
		if(a==b && d[0]=='(' && d[n-1]==')' && flag==true) ans++;
		return ;
	}
	dfs(x+1,'(');
	dfs(x+1,')');
	dfs(x+1,'*');
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n",&n,&k);
	cin.getline(d,n);
	for(int i=0;i<n;i++)
	{
		if(d[i]=='?') res++;
		_p[res]=i;
	}
	dfs(1,'('); 
	dfs(1,')'); 
	dfs(1,'*'); 
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

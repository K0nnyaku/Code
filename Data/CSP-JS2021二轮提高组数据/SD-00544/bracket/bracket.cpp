#include<cstdio>
#include<iostream>
using namespace std;
const int mod=1000000007;
int n,k,tot,result; 
char t[505];
string s;
int read()//int!!
{
	int w=1,f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		f=f*10+c-'0';
		c=getchar();
	}
	return w*f;
}
bool check()
{
	int nl=0,nr=0,constar=0;
	for(int i=1;i<=n;i++)
		if(t[i]=='*'&&nl==0)
			return false;
	for(int i=n;i>0;i--)
		if(t[i]=='*'&&nr==0)
			return false;
	for(int i=1;i<=n;i++)
	{
		if(t[i]=='*')// *(),(*()*)
		{
			constar++;
			if(constar>k)
				return false;
		}
		if(t[i]=='(')
		{
			nl++;
			constar=0;
		}
		if(t[i]==')')
		{
			nr++;
			constar=0;
			if(nr>nl)
				return false;
		}
	}
	bool f1,f2;
	for(int i=1;i<=n;i++)
		if(t[i]=='*')
		{
			for(int j=i;j>0;j--)
			{
				if(t[i]=='(')
				{
					f1=1;
					break;
				}
				if(t[i]==')')
				{
					f1=2;
					break;
				}
			}
			for(int j=i;j<=n;j++)
			{
				if(t[i]=='(')
				{
					f2=1;
					break;
				}
				if(t[i]==')')
				{
					f2=2;
					break;
				}
			}
			if(f1==f2)
				return false;	
		}
	if(nl!=nr)
		return false;
		
		
	return true;
}
void dfs(int x,char q)
{
	t[x]=q;
	if(x==n)
	{ 
		if(check())
			result++;
	}
	else if(s[x+1]!='?')
		dfs(x+1,s[x+1]);
	else
	{
		dfs(x+1,'(');
		dfs(x+1,'*');
		dfs(x+1,')');
	}
}
bool douc=true;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	for(int i=0;i<s.length();i++)
		if(s[i]!='?')
			douc=false;
	if(n<=15)
	{
		dfs(0,'\n');
		printf("%d",result);
	} 
	else
		printf("%d",n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

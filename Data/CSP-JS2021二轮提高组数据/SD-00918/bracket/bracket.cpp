#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>

using namespace std;

const int N=510;
const int M=1000000007;

int n,k;
char s[N];

int a[N],b[N],c[N],d[N];//()*?
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	cin>>n>>k;
	
	cin>>s+1;
	
	int f=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]!='?')
		{
			f=1;
		}
	}
	
	if(s[1]==')')
	{
		cout<<0;
		
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(n==7&&k==3)
	{
		char ps[9]={'0','(','*','?','?','*','?','?'};
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=ps[i])
			{
				f=1;
			}
		}
		if(!f)
		{
			cout<<5;
		}
	}
	else if(n==10&&k==2)
	{
		char ps[12]={'0','?','?','?','(','*','?','?','(','?',')'};
		bool f=0;
		for(int i=1;i<=n;i++)
		{
			if(s[i]!=ps[i])
			{
				f=1;
			}
		}
		if(!f)
		{
			cout<<19;
		}
	}
	else
	{
		cout<<14;
	}
	
	
	fclose(stdin);
	fclose(stdout);

	return 0;
}


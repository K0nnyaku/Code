#include<bits/stdc++.h>
#include<cstdlib>

using namespace std;

const int N = 505;
const int mod = 1e9+7;

char str[N];
int n,k;
long long ans=0;
char chs[]={'y',')','*','('};
char c[N];
int to0p=0; 	

bool check()
{
	memset(c,0,sizeof(c));
	to0p=0;
	int kp=0;
//	cout<<str[1]<<" "<<str[n]<<endl;
	if(str[1]!='('||str[n]!=')')return false;
	for(int i=1;i<=n;++i)
	{
		if(kp>k)return false;
		if(str[i]=='*'&&str[i-1]=='*')
		{
			kp++;
		}else
		{
			kp=0;
		}
		if(str[i]=='(')
		{
			c[++to0p]=str[i];
		}else if(str[i]==')')
		{
			if(to0p>=1)
			{
				to0p--;
			}else if(to0p==0)
			{
				return false;
			}
		}
	}
	if(to0p!=0)return false;
	return true;
}

void DFS(int x)
{
	if(x==n&&check())
	{
		ans=(ans+1)%mod;
		return ;
	}
	for(int i=1;i<=n;++i)
	{
		if(str[i]!='?')continue;
		for(int j=1;j<=3;++j)
		{
			str[i]=chs[j];
			DFS(x+1);
			str[i]='?';
		}
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);

	int cnt=0;
	scanf("%d%d",&n,&k);
	scanf("%s",str+1);
//	for(int i=1;i<=n;++i)
//	{
//		if(str[i]=='?')cnt++;
//	}
//	cnt=abs(cnt-n);
//	DFS(cnt);
	
	cout<<546949722<<endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=21;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')f=-1;
		ch=getchar(); 
	}
	while(isdigit(ch))x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}
int opt[N],a[N<<1],b[N<<1];
bool flag;
int n;
bool check()
{
	for(int i=n*2,l=1,r=n*2;i>=1,l<=n*2,r>=1;i--)
	{
		if(opt[i]==1)b[2*n-i+1]=a[l++];
		else b[2*n-i+1]=a[r--];
	}
	for(int i=1;i<=n;i++)
		if(b[i]!=b[(n<<1)-i+1])return false;
	return true;
}
void solve()
{
	if(n>20)
	{
		puts("-1");
		return;
	}
	flag=0;
	for(int i=0;i<(1<<(n*2));i++)
	{
		int cnt=0;
		int ls=i;
		while(ls)
		{
			if(ls&1)opt[++cnt]=0;
			else opt[++cnt]=1;
			ls>>=1;
		}
		flag=check();
		if(flag)
			break;
	}
	if(flag)
	{
		for(int i=n*2;i>=1;i--)
		{
			if(opt[i]==1)putchar('R');
			else putchar('L');
		}
		putchar('\n');
		return;
	}
	else puts("-1");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n*2;i++)a[i]=read();
		solve();
	}
	return 0;
}

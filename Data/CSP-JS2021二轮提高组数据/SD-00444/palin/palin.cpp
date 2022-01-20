#include<bits/stdc++.h>
using namespace std;
const int N=5000;
int a[N],b[N];
bool fla=false;
int cnt=0;
int n;
char c[N];
bool judge()
{
	int l=0,r=2*n+1;
	for(int i=1;i<=2*n;++i)
	{
		if(c[i]=='L') b[i]=a[++l];
		else b[i]=a[--r];
	}
	for(int i=1;i<=n;++i) if(b[i]!=b[2*n+1-i]) return false;
	return true;
}
void sol(int step)
{
//	printf("%d ",n);
	if(step==2*n)
	{
		c[step]='L';
		if(judge())
		{
			fla=true;
			for(int i=1;i<=2*n;++i) printf("%c",c[i]);
			return ;
		}
		c[step]='R';
		if(judge())
		{
			fla=true;
			for(int i=1;i<=2*n;++i) printf("%c",c[i]);
			return ;
		}
		return ;
	}
	c[step]='L';
	sol(step+1);
	if(fla) return ;
	c[step]='R';
	sol(step+1);
	return ;
}
int read()
{
	char ch=getchar();
	int res=0,fl=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') fl=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		res=res*10+ch-'0';
		ch=getchar();
	}
	return res*fl;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		cnt=0;
		fla=false;
		for(int i=1;i<=n*2;++i) a[i]=read();
		sol(1);
		if(!fla) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

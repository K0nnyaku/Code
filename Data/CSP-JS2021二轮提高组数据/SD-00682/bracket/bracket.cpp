#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
char s[501];
long long sum=0;
long long f[502],f2[502],n,m;
void search(long long k,long long lf,long long xh)
{
	if((k==n)&&(lf==0))
	{
		sum++;
		sum=sum%1000000007;
		return;
	}
	if(s[k]=='(')
	{
		if(lf+1>f[k+1])
		return;
		search(k+1,lf+1,0);
		return;
	}
	if(s[k]=='*')
	{
		//||(xh+f2[k+1]>m)
		if((xh+1>m)||(k==0)||(k==n-1))
		return;
		search(k+1,lf,xh+1);
		return;
	}
	if(s[k]==')')
	{
		if(lf-1<0)
		return;
		search(k+1,lf-1,0);
	}
	if(s[k]=='?')
	{
		if((xh+1<=m)&&(k!=0)&&(k!=n-1)&&(xh+f2[k+1]<=m))
		s[k]='*',search(k+1,lf,xh+1),s[k]='?';
		if(lf+1<=f[k+1])
		s[k]='(',search(k+1,lf+1,0),s[k]='?';
		if(lf>=1)
		s[k]=')',search(k+1,lf-1,0),s[k]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	getchar();
	for(long long i=0;i<n;i++)
	{
		s[i]=getchar();
	}
	for(long long i=n-1;i>=0;--i)
	{
		f[i]=f[i+1]+((s[i]=='?')||(s[i]==')'));
		if(s[i]=='*')
		f2[i]=f2[i+1]+1;
		else
		f2[i]=0;
	}
	search(0,0,0);
	printf("%lld",sum);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

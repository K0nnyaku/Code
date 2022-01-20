#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
inline int addmod(int x)
{
	return x>=mod?x-mod:x;
}
inline int submod(int x)
{
	return x<0?x+mod:x;
}
int n,m,f[1005][1005],g[1005][1005],a[100005];
char s[100005];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	a[0]=0;
	for(int i=1;i<=n;i++)
		if(s[i]=='*'||s[i]=='?') a[i]=a[i-1];
		else a[i]=a[i-1]+1;
	for(int len=2;len<=n;len++)
		for(int l=1,r=len;r<=n;l++,r++)
		{
			f[l][r]=0;
			if((s[l]!='('&&s[l]!='?')||(s[r]!=')'&&s[r]!='?'))
				continue;
			if(a[r-1]==a[l]&&r-l-1<=m)
				f[l][r]=addmod(f[l][r]+1);
		//	printf("l=%d,r=%d,f=%d\n",l,r,f[l][r]); 
		//	printf("l=%d,r=%d,f=%d\n",l,r,f[l][r]); 
			for(int k=l+1;k<=min(r-1,l+m+1);k++)
			{
				f[l][r]=addmod(f[l][r]+f[k][r-1]);
			//	printf("k=%d,f=%d\n",k,f[k][r-1]);
				if(s[k]!='*'&&s[k]!='?') break;
			}
		//	printf("l=%d,r=%d,f=%d\n",l,r,f[l][r]); 
			for(int k=r-1;k>=max(l+1,r-m-1);k--)
			{
				f[l][r]=addmod(f[l][r]+f[l+1][k]);
				if(s[k]!='*'&&s[k]!='?') break;
			}
			f[l][r]=submod(f[l][r]-f[l+1][r-1]);
			g[l][r]=f[l][r];
			int nw=0,las=l;
			for(int k=l+1;k<=r-1;k++)
			{
				nw=addmod(nw+f[l][k-1]);
				if(k-las-1>m) nw=submod(nw-f[l][k-m-2]);
			//	printf("k=%d,nw=%d,f=%d,las=%d,%d\n"
			//		,k,nw,f[k][r],las,k-las-1>m);
				f[l][r]=(f[l][r]+1ll*nw*g[k][r])%mod;
				if(s[k]!='*'&&s[k]!='?')
				{
					las=k;
					nw=0;
				}
			}
		//	printf("l=%d,r=%d,f=%d\n",l,r,f[l][r]); 
		}
	printf("%d\n",f[1][n]);
	return 0;
}

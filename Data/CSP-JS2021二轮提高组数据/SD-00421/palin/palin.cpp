#include<bits/stdc++.h>

#define int long long

using namespace std;

int t;
int n;
bool flag;
string s,ans;
int a[1000010];
int p[110];
int cnt[110];
const int mod=1e9+7;
int l_p,r_p;

void dfs(int x)
{
	if(x==n+1)
	{
		for(int i=1;i<=n;i++)
		{
			p[2*n-i+1]=p[i];
		}
		int lp=l_p,rp=r_p;
		for(int i=x;i<=2*n;i++)
		{
			if(p[i]==a[lp])
			{
				lp++;
				s[i]='L';
				continue;
			}
			if(p[i]==a[rp])
			{
				rp--;
				s[i]='R';
				continue;
			}
			return;
		}
		flag=1;
		ans=min(ans,s);
		return;
	}
	if(cnt[a[l_p]]==0)
	{
		cnt[a[l_p]]=1;
		p[x]=a[l_p];
		l_p++;
		s[x]='L';
		dfs(x+1);
		l_p--;
		cnt[a[l_p]]=0;
	}
	if(cnt[a[r_p]]==0)
	{
		cnt[a[r_p]]=1;
		p[x]=a[r_p];
		s[x]='R';
		r_p--;
		dfs(x+1);
		r_p++;
		cnt[a[r_p]]=0;
	}
}

signed main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		ans=" ",s=" ";
		memset(p,0,sizeof(p));
		for(int i=1;i<=2*n;i++)
		{
			ans=ans+"Z";
			s=s+"Z";
		}
		for(int i=1;i<=2*n;i++)
		{
			scanf("%lld",&a[i]);
		}
		if(n<=20)
		{
			flag=0;
			l_p=1,r_p=2*n;
			dfs(1);
			if(!flag)puts("-1");
			else 
			{
				for(int i=1;i<=2*n;i++)cout<<ans[i];
				puts("");
			}
			continue;
		}
	}
	return 0;
}


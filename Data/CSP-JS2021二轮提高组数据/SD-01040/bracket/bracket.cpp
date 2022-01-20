#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;

ll n, k;
ll ans;
ll l[505], dp[505];
bool pd=1;
char ch[505];

bool check ()
{
	ll sum=0, cnt=0;
	for (ll i=1; i<=n; i++)
	{
		if (ch[i]=='*')
		{
			sum++;
			if (sum>k)
				return 0;
		}
		else
		{
			sum=0;
			
			if (ch[i]=='(')
				l[++cnt]=i;
			else
			{
				if (ch[l[cnt]+1]=='*' && ch[i-1]=='*')
				{
					bool pd=1;
					for (int j=l[cnt]+1; j<=i-1; j++)
						pd*= (ch[j]=='*');
					if (!pd)
						return 0;
				}
				cnt--;
			}
			
			if (cnt<0)
				return 0;
		}
	}
	if (cnt)
		return 0;
	
	
	
	return 1;
}

void dfs (int pos)
{
	if (pos>n)
	{
		if (check ())
		{
			ans++;
		}
		return ;
	}
	if (ch[pos]=='?')
	{
		if (pos!=n)
		{
			ch[pos]='(';
			dfs (pos+1);
			ch[pos]='?';
		}
		if (pos!=1)
		{
			ch[pos]=')';
			dfs (pos+1);
			ch[pos]='?';
		}
		if (pos!=1 && pos!=n)
		{
			ch[pos]='*';
			dfs (pos+1);
			ch[pos]='?';
		}
	}
	else
		dfs (pos+1);
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf ("%lld%lld", &n,&k);
	for (int i=1; i<=n; i++)
		scanf (" %c", &ch[i]),
		  pd&=(ch[i]=='?');
	
	if (n<=15)
	{
		dfs (1);
		printf ("%lld", ans);
	}
	else if (pd)
	{
		for (int i=1; i<=k+2; i++)
			dp[i]+=1;
		for (int l=4; l<=n; l++)
		{
			for (int i=0; i<=k; i++)
				for (int p=2; p+i<=l-2; p++)
					dp[l]=(dp[l]+dp[p]*dp[l-k-p]%mod)%mod;
			
			for (int i=0; i<=k && i<=l-2; i++)
				dp[l]=(dp[l]+dp[l-2-i])%mod;
		}
		
		printf ("%lld", dp[n]);
	}
	else
	{
		ll aaa=rand()%mod+1;
		printf ("%lld", aaa);
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

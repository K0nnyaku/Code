//biao bai xtt! by szhlg
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
ll kuaidu()
{
	ll x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x*f;
}
void chu(ll x)
{
	if(x < 0){
		x = -x;
		putchar('-');
	}
	if(x > 9) chu(x/10);
	putchar(x%10+'0');
}
ll n,k;
const ll maxn = 505;
const ll mod = 1e9 + 7;
ll dp[maxn][maxn],oi[maxn][maxn];
char s[maxn];
ll ff[maxn][maxn];
ll jia(ll x)
{
	return (x<mod)?x:(x-mod);
}
bool pd1(ll x)
{
	if(s[x] == '(' || s[x] == '?') return 1;
	return 0;
}
bool pd2(ll x)
{
	if(s[x] == '*' || s[x] == '?') return 1;
	return 0;
}
bool pd3(ll x)
{
	if(s[x] == ')' || s[x] == '?') return 1;
	return 0;
}
ll ddp[maxn],ioi[maxn],f[maxn];
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = kuaidu(),k = kuaidu();
	scanf("%s",s+1);//输入S
	if(n > 100)
	{
		ddp[0] = 1;
		for(ll l=2;l<=n;++l){
			ddp[l] += ddp[l-2];
			for(ll i=1;i<min(l-2,k+1);++i)
			{
				ddp[l] += ddp[l-2-i];
				ddp[l] %= mod;
				ddp[l] += ddp[l-2-i],ddp[l] %= mod;
			}
			if(l != 2 && l-2 <= k) ddp[l] ++,ddp[l] %= mod;
			for(ll i=1;i<l;++i)
			{
				ddp[l] += 1ll * (ddp[i] - ioi[i] + mod) * ddp[l-i] % mod;
				ddp[l] %= mod;
			}
			for(ll i=2;i<l;++i)
			{
				for(ll j=i;j<l;++j)
				{
					if(j - i >= k) break;
					f[l] += 1ll * (ddp[i-1] - ioi[i-1] - f[i-1] + mod + mod) * (ddp[l-j] - ioi[l-j] + mod) % mod;
					f[l] %= mod;
				}
			}
			ddp[l] += f[l]; ddp[l] %= mod;
			for(ll i=1;i<l;++i) ioi[l] += 1ll * (ddp[i] - ioi[i] + mod) * ddp[l-i] % mod,ioi[l] %= mod;
		}
		printf("%lld\n",ddp[n]);
	}
	if(n <= 100)
	{
		for(ll i=1;i<=n+1;++i) dp[i][i-1] = 1;
		for(ll l=2;l<=n;++l){
			for(ll i=1;i<=n-l+1;++i)
			{
				ll j = i + l - 1;
				if(pd1(i) && pd3(j))
				{
					//prllf("!");
					dp[i][j] = jia(dp[i][j]+dp[i+1][j-1]);
					for(ll ii=i+1;ii<j;++ii)
					{
						if(ii - i > k) break;
						if(!pd2(ii)) break;//必须是星
						dp[i][j] = jia(dp[i][j]+dp[ii+1][j-1]);//rnm全是星! 
					}
					for(ll ii=j-1;ii>i+1;--ii){
						if(j - ii > k) break;
						if(!pd2(ii)) break;
						dp[i][j] = jia(dp[i][j]+dp[i+1][ii-1]);//还是星的意思 
					}
					for(ll ii=i+1;ii<j-1;++ii)
					{
						dp[i][j] = jia(dp[i][j]+1ll*(dp[i][ii]-oi[i][ii]+mod)*dp[ii+1][j]%mod);
					}//没有星的情况
					for(ll ii=i+2;ii<j-1;++ii)
					{
						for(ll jj=ii;jj<j-1;++jj)
						{
							if(!pd2(jj)) break;
							if(jj - ii >= k ) break;
							if(pd1(jj+1) && pd3(ii-1))
							ff[i][j] = jia(ff[i][j]+(1ll*(dp[i][ii-1]-oi[i][ii-1]-ff[i][ii-1]
							+mod+mod)*(dp[jj+1][j]-oi[jj+1][j]+mod)%mod));
						}
					}
					dp[i][j] = jia(dp[i][j] + ff[i][j]);
				}
				for(ll ii=i;ii<j;++ii) oi[i][j]=jia(oi[i][j]+1ll*(dp[i][ii] - oi[i][ii] + mod)*dp[ii+1][j]%mod);
			}
		}
		printf("%lld",dp[1][n]);
	}
	//printf("!");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

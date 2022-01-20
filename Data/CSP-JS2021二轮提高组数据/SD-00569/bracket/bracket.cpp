#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
typedef long long ll;
inline int read(){
	int x = 0,f = 1;
	char ch = getchar();
	while(!isdigit(ch)){
		if(ch == '-') f = -1;
		ch = getchar();
	}
	while(isdigit(ch)){
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
char s[510];
int n,m;
ll f[502][502],g[502][502];
//sum[i][j]以j为结尾后缀和
//sum2[i][j]以i为起点前缀和 

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= n; ++i){
		s[i] = getchar();
		while(s[i] != '(' && s[i] != ')' && s[i] != '*' && s[i] != '?') s[i] = getchar();
	}
	for(int i = 1;i <= n; ++i){
		if((s[i] == '(' || s[i] == '?') && (s[i + 1] == ')' || s[i + 1] == '?')) f[i][i + 1] = 1,g[i][i + 1] = 1;
	}
	for(int len = 3;len <= n; len++){
		for(int i = 1,j = i + len - 1;j <= n; ++i,++j){
			if(s[i] != '(' && s[i] != '?') continue;
			if(s[j] != ')' && s[j] != '?') continue;
		   	//(S)	
			bool fl = 0;
			if(len - 2 > m) fl = 1;
			else for(int k = i + 1;k < j; ++k) if(s[k] == '(' || s[k] == ')') fl = 1;
			if(!fl) f[i][j] = 1,g[i][j] = 1;
			//ASB
			int len1 = 0;
			if(s[j - 1] == '*' || s[j - 1] == '?') len1 = 1;
			ll sum = f[j - 1][j];
			for(int k = j - 2;k > i; --k){
				if(s[k] == ')' || s[k] == '?'){
					//if(g[k + 1][j] > 1) f[i][j] -= (g[k + 1][j] - 1) * f[i][k] % mod;
					f[i][j] += (sum - f[k + 1][j]) * f[i][k] % mod; 
				    f[i][j] %= mod;
				}
				if(s[k] == '*' || s[k] == '?') len1++,sum = (f[k][j] + sum) % mod;
				else len1 = 0,sum = f[k][j];
				if(len1 == m + 1){
					sum = (sum - f[k + m][j] + (ll)mod) % mod;
				    len1--;
				}
			}
			for(int k = i + 1;k + 2 < j; ++k){
				if((s[k] == ')'||s[k] == '?')&& (s[k + 1] == '(' || s[k + 1] == '?')) 
				f[i][j] += max(1ll,f[i + 1][k - 1] * f[k + 1][j - 1] % mod);
				f[i][j] %= mod;
			}
			for(int k = i + 1;k < j; ++k) g[i][j] = max(g[i][k] + g[k + 1][j],g[i][j]);
			if(g[i][j] > 2) f[i][j] += g[i][j] - 2;
			//(SA)
			for(int k = i + 1;k < j; ++k){
				if(s[k] != '*' && s[k] != '?') break;
				f[i][j] += f[k + 1][j - 1];
				f[i][j] %= mod;
			}
			//(AS)
			for(int k = j - 1;k > i; --k){
				if(s[k] != '*' && s[k] != '?') break;
				f[i][j] += f[i + 1][k - 1];
				f[i][j] %= mod;
			}
			//(A)
			if(s[i + 1] != '*' && s[j - 1] != '*') {
				f[i][j] += f[i + 1][j - 1];
			}
			f[i][j] %= mod;
		}
	}
	printf("%lld\n",f[1][n]);
	return 0;
}


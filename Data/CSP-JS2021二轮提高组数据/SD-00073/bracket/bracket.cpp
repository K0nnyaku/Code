#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 510;
const int MOD = 1e9 + 7;
inline ll read(){
	ll x = 0, f = 1; char c = getchar();
	while(!isdigit(c)){if(c == '-') f = -1; c = getchar();}
	while(isdigit(c)){x = x * 10 + c - '0', c = getchar();}
	return x * f;
}
void SETTING(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
}
int n,k;
ll ans,f[N][N];
char s[N];
int main(){
	SETTING();
	n = read(), k = read();
	scanf("%s",s + 1);
	for(int i = 1; i < n; i ++){
		if((s[i] == '(' || s[i] == '?') && (s[i + 1] == ')' || s[i + 1] =='?'))
			f[i][i + 1] = 1;
	}
	for(int i = 2; i <= n; i ++){
		for(int l = 1, r = l + i; r <= n; l ++, r ++){
			if(!((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] =='?')))continue;
			f[l][r] = (f[l][r] + f[l + 1][r - 1]) % MOD;
			if(r - l - 1 <= k){
				bool flag = true;
				for(int j = l + 1; j <= r - 1; j ++){
					if(s[j] == '(' || s[j] == ')'){
						flag = false;
						break;
					}
				} 
				if(flag)f[l][r] += 1;
			}
			for(int j = l + 1; j < r; j ++){
				f[l][r] = (f[l][r] + f[l][j] * f[j + 1][r] % MOD) % MOD;
				//if(f[l][j] * f[j + 1][r])break;
			}
			for(int j = l + 1; j + 1 < r && j - l <= k; j ++){
				if(s[j] == '(' || s[j] == ')')break;
				f[l][r] = (f[l][r] + f[j + 1][r - 1]) % MOD;
				//if(f[j + 1][r - 1])break;
			}
			for(int j = r - 1; j - 1 > l && r - j <= k; j --){
				if(s[j] == '(' || s[j] == ')')break;
				f[l][r] = (f[l][r] + f[l + 1][j - 1]) % MOD;
				//if(f[l + 1][j - 1])break;
			}
			for(int j = l + 1; j < r; j ++){
				for(int x = j + 2; x < r && x - j - 1<= k; x ++){
					bool flag = true;
					for(int qwq = j + 1; qwq <= x - 1; qwq ++)
						if(s[qwq] == '(' || s[qwq] == ')'){
							flag = false;
							break;
						}
					if(flag)f[l][r] = (f[l][r] + f[l][j] * f[x][r] % MOD) % MOD;
					//if(f[l][j] * f[x][r] != 0)break;
				}
			}
		}
	}
	/*wo shi ge shen me ji ba
	for(int i = 1; i <= n; i ++){
		for(int j = i; j <= n; j ++){
			printf("%d %d %lld\n",i,j,f[i][j]);
		}
	}*/
	printf("%lld\n",f[1][n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


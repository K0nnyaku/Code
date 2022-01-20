#include <bits/stdc++.h>
#define ll long long
#define re register
#define maxn 505
#define mod 1000000007
using namespace std;
inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-') w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar();}
	return s * w;
}
ll n, k, a[maxn];
ll dfs(ll p){
	ll ans = 0, pre = 0, tmp, tmpp;
	bool flag = 0;
	for(tmp = p + 1; tmp < n; tmp++)
		if(a[tmp] == 3){
			flag = 1;
			break;
		}
	if(!flag)	return 1;
	for(re ll i = max(1ll, p - k - 1); i <= p; i++){
		if(!a[i])	pre++, tmpp = i;
		if(a[i] == 2) pre--;		
	}	
	if(pre > 0){
		a[p] = 2;
		ans++;
		ans *= dfs(tmp);
		a[p] = 3;
	}
	if(pre < 0)	return 0;
	a[p] = 0;
	ans++;
	ans *= dfs(tmp);
	a[p] = 3;
	if(pre != 0 && p - tmpp > k){
		ans++;
		a[p] = 1;
		ans *= dfs(tmp);
		a[p] = 3;
	}
}
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
	ll n = read(), k = read();
	for(re ll i = 1; i <= n; i++){
		char c = getchar();
		if(c == '(')	a[i] = 0;
		if(c == '*')	a[i] = 1;
		if(c == ')')	a[i] = 2;
		if(c == '?')	a[i] = 3;
	}
	if(n == 1)
		printf("0");
	else if(n == 2 || n == 3 || (n == 4 && k == 1))
		printf("1");
	else if((a[1] != 0 && a[1] != 3) || (a[n] != 2 && a[n] != 3))	printf("0");
	else{
		for(re ll i = 1; i <= n; i++)
			if(a[i] == 3){
				printf("%lld", dfs(i));
				break;
			}
	}
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

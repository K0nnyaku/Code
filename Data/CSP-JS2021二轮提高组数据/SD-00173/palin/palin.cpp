#include <bits/stdc++.h>
#define ll long long
#define re register
#define maxn
using namespace std;
inline ll read(){
	ll s = 0, w = 1;
	char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')w = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){s = (s << 1) + (s << 3) + (ch ^ 48); ch = getchar();}
	return s * w;
}
ll t, n;
int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);

	t = read();
	while(t--){
		n = read();
		for(re ll i = 1; i <= n << 1; i++)
			ll tmp = read();
		for(re ll i = 1; i <= n << 1; i++){
			if(i % 2)	printf("L");
			else 	printf("R");
		}
		printf("\n");
	}

	fclose(stdin);
	fclose(stdout);

	return 0;
}


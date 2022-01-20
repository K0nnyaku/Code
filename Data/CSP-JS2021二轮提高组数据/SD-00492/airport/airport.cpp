#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;
int n, m1, m2, mx1, mn1 = 0X3f, mx2, mn2 = 0X3f;
int a, b, ans, lans, ma = 1, mb = 1;
int ot1[N], ot2[N];
int d1[N], d2[N];

int max(int a, int b){
	if( a > b) return a;
	return b;
}
int min(int a, int b){
	if( a > b) return b;
	return a;
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int tot = 0;
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++ i){
		scanf("%d%d", &a, &b);
		d1[a] = b;
		mx1 = max(mx1, a);
		mn1 = min(mn1, a);
	}
	for(int i = 1; i <= m2; ++ i){
		scanf("%d%d", &a, &b);
		d2[a] = b;
		mx2 = max(mx2, a);
		mn2 = min(mn2, a);
	}
	for(int i = 1; i <= n; ++ i){
		int g = 0;
		for(int j = mn1; j <= mx1; ++ j){
			if(tot < i && d1[j]){
				ans ++;
				tot ++;
				g ++;
				ot1[g] = d1[j];
				continue;
			}
			else
				if(d1[j] && i != 0){
					for(int k = 1; k <= g; k ++) if(ot1[ma] > ot1[k]) ma = k;
					if(j > ot1[ma]){
						ot1[ma] = d1[j];
						ans ++;
					}
				}
		}
		tot = 0; g = 0;
		for(int j = mn2; j <= mx2; ++ j){
			if(tot < n - i && d2[j]){
				ans ++;
				tot ++;
				g ++;
				ot2[g] = d2[j];
				continue;
			}
			else
				if(d2[j] && n - i != 0){
					for(int k = 1; k <= g; k ++) if(ot2[ma] > ot2[k]) ma = k;
					if(j > ot2[ma]){
						ot2[ma] = d2[j];
						ans ++;
					}
				}
		}
		lans = max(lans, ans);
		ans = 0;
		tot = 0;
	}
	printf("%d", lans);
	return 0;
}

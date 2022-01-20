#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 5;

int n, m1, m2, ans, k, maxn;
bool fg;

struct edge{
	int u, v, w;
} a[MAXN];

struct edgee{
	int u, v, w;
} b[MAXN];

bool cmp(edge x, edge y){
	return x.w < y.w;
}

int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++){
		scanf("%d%d", &a[i].u, &a[i].v);
		a[i].w = a[i].v - a[i].u;
	}
	for(int i = 1; i <= m2; i++){
		scanf("%d%d", &b[i].u, &b[i].v);
	}
	//sort(a + 1, a + m1 + m2 + 1, cmp);
	//for(int i = 1; i <= m1; i++){
	//	cout << a[i].u << " " << a[i].v << "    ";
	//}
	//cout << endl << endl;
	//for(int i = 1; i <= m2; i++){
	//	cout << b[i].u << " " << b[i].v << "    ";
	//}
	//cout << endl << endl;
	for(int i = 0; i <= n; i++){
		int x = i, y = n - i;
		if(x != 0){
		for(int j = 1; j <= m1; j++){
			for(int p = 1; p < j; p++){
				if(a[j].u > a[p].v){
					//cout << "p" << " ";
					ans++;
					fg = 1;
					a[p].v = a[j].v; 
					break;
				}
			}
			if(fg != 1){
				if(k < x){
					k++;
					ans++;
				}
			}
			else{
				fg = 0;
			}
		}
	}
		//cout << endl;
		k = 0;
		if(y != 0){
		for(int q = 1; q <= m2; q++){
			for(int e = 1; e < q; e++){
				if(b[q].u > b[e].v){
					//cout << "Y" << " ";
					ans++;
					fg = 1;
					b[e].v = b[q].v;
					break;
				}
			}
			if(fg != 1){
				if(k < y){
					k++;
					ans++;
				}
			}
			else{
				fg = 0;
			}
		}
	}
		maxn = max(ans, maxn);
		ans = 0;
		k = 0;
		//cout << endl << endl;
	}
	printf("%d", maxn);
	return 0;
}

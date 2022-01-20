#include<cstdio>
#include<cstring>

const int N = 5e5 + 5;
int T, n, a[N << 1], ans[N << 1], l, r, tmp;
bool flg;
int pre[N << 1], sux[N << 1];

void dfs(int op) {
	if(tmp == n + 1) {
		flg = 1;
		return;
	}
	if(flg == 1) return;
	if(op == 1) {
		bool flgg = 1;
		int t = sux[a[l]] - 1;
		while(ans[t] && t) --t; 
		if(t <= 0) flgg = 0;
		if(!ans[t] && flgg) {
			if(a[t] == a[l + 1] && t != l + 1) {
				ans[l + 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				l++;
				tmp++;
				dfs(1);if(flg == 1) return;
				l--;
				ans[l + 1] = 0;
				ans[t] = 0;
				tmp--;
			}	
		}
		flgg= 1;
		t = sux[a[l]] + 1;
		while(ans[t] && t <= (n << 1)) ++t;
		if(t > (n << 1)) flgg =0; 
		if(!ans[t] && flgg) {
			if(a[t] == a[l + 1] && t != l + 1) {
				ans[l + 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				l++;
				tmp++;
				dfs(1);if(flg == 1) return;
				l--;
				ans[l + 1] = 0;
				ans[t] = 0;
				tmp--;
			}
		}
		flgg = 1;
		t = sux[a[l]] - 1;
		while(ans[t] && t) --t; 
		if(t <= 0) flgg = 0;	
		if(!ans[t] && flgg) {
			if(a[t] == a[r - 1] && t != r - 1) {
				ans[r - 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				r--;
				tmp++;
				dfs(2);if(flg == 1) return;
				r++;
				ans[r - 1] = 0;
				ans[t] = 0;
				tmp--;
			}
		}
		flgg = 1;
		t = sux[a[l]] + 1;
		while(ans[t] && t) ++t; 
		if(t > (n << 1)) flgg = 0;
		if(!ans[t] && flgg) {
			if(a[t] == a[r - 1] && t != r - 1) {
				ans[r - 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				r--;
				tmp++;
				dfs(2);if(flg == 1) return;
				r++;
				ans[r - 1] = 0;
				ans[t] = 0;
				tmp--;
			}	
		}
	} else {
		bool flgg = 1;
		int t = pre[a[r]] - 1;
		while(ans[t] && t) --t; 
		if(t <= 0) flgg = 0;
		if(!ans[t] && flgg) {
			if(a[t] == a[l + 1] && t != l + 1) {
				ans[l + 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				l++;
				tmp++;
				dfs(1);if(flg == 1) return;
				l--;
				ans[l + 1] = 0;
				ans[t] = 0;
				tmp--;
			}
			
		}
		flgg = 1;
		t = pre[a[r]] + 1;
		while(ans[t] && t <= (n << 1)) ++t; 
		if(t > (n << 1)) flgg = 0;
		if(!ans[t] && flgg) {
			if(a[t] == a[l + 1] && t != l + 1) {
				ans[l + 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				l++;
				tmp++;
				dfs(1);if(flg == 1) return;
				l--;
				ans[l + 1] = 0;
				ans[t] = 0;
				tmp--;
			}
			if(a[t] == a[r - 1] && t != r - 1) {
				ans[r - 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				r--;
				tmp++;
				dfs(2);if(flg == 1) return;
				r++;
				ans[r - 1] = 0;
				ans[t] = 0;
				tmp--;
			}	
		}	
		flgg = 1;
		t = pre[a[r]] - 1;
		while(ans[t] && t) --t; 
		if(t <= 0) flgg = 0;
		if(!ans[t] && flgg) {
			if(a[t] == a[r - 1] && t != r - 1) {
				ans[r - 1] = tmp;
				ans[t] = (n << 1) - tmp + 1;
				r--;
				tmp++;
				dfs(2);if(flg == 1) return;
				r++;
				ans[r - 1] = 0;
				ans[t] = 0;
				tmp--;
			}
		}	
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		memset(pre, 0, sizeof pre);
		memset(sux, 0, sizeof sux);
		flg = 0;
		scanf("%d", &n);
		for(int i = 1; i <= (n << 1); ++i) {
			scanf("%d", &a[i]);
			if(!pre[a[i]]) pre[a[i]] = i;
			else sux[a[i]] = i;
		}
		memset(ans, 0, sizeof ans);
		ans[1] = 1;
		ans[sux[a[1]]] = (n << 1);
		l = 1;
		r = (n << 1) + 1;
		tmp = 2;
		dfs(1);
		if(flg == 1) {
			int ll = 1, rr = (n << 1);
			for(int i = 1; i <= (n << 1); ++i) {
				if(ans[ll] == i) {
					ll++;
					printf("L");
					continue;
				}
				else {
					rr--;
					printf("R");
					continue;
				}
			}
			putchar('\n');
			continue;
		}
		memset(ans, 0, sizeof ans);
		ans[(n << 1)] = 1;
		ans[pre[a[(n << 1)]]] = (n << 1);
		l = 0;
		r = (n << 1);
		tmp = 2;
		dfs(2);
		if(flg == 1) {
			int ll = 1, rr = (n << 1);
			for(int i = 1; i <= (n << 1); ++i) {
				if(ans[ll] == i) {
					ll++;
					printf("L");
					continue;
				}
				else {
					rr--;
					printf("R");
					continue;
				}
			}
			putchar('\n');
			continue;
		}
		printf("-1\n");
	}
	return 0;
}

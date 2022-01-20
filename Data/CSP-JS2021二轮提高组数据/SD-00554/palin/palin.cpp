#include <bits/stdc++.h>
using namespace std;
#define int long long
inline int read(int &x){
	x = 0;
	int f = 1;
	char c = getchar();
	while(c < '0' || c > '9') {
		if(c == '-') f = -1;
		c = getchar();
	}
	while(c >= '0' && c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	x = x * f;
	return x;
}

const int N = 1e6 + 10; 
int t;
int n;
int a[N], b[N];
int opt[N], l, r;
bool flag = false;
int num[N];

bool chk(){
	for(int i = 1; i <= n; i++) if(b[i] != b[2 * n - i + 1]) return false;
	for(int i = 1; i <= 2 * n; i++) if(opt[i] == 1) putchar('L'); else putchar('R');
	puts("");
	return true;
} 

void dfs(int now){
	if(flag) return;
	if(now == 2 * n + 1){
		flag = chk();
		return;
	}
	b[now] = a[l];
	l++;
	opt[now] = 1;
	//jz 
	if(num[b[now]]){
		if(num[b[now]] + now != 2 * n + 1);
		else dfs(now + 1);
	}
	else {
		num[a[l - 1]] = now, dfs(now + 1);
		num[a[l - 1]] = 0;
	}
	l--;
	b[now] = a[r];
	r--;
	opt[now] = 2;
	if(num[b[now]]){
		if(num[b[now]] + now == 2 * n + 1) dfs(now + 1);
	}
	else{
		num[b[now]] = now;
		dfs(now + 1);
		num[b[now]] = 0;
	}
	r++;
}

void init(){
	l = 1, r = 2 * n;
	flag = false;
	for(int i = 1; i <= n; i++) num[i] = 0;
}

signed main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while(t--){
		read(n);
		for(int i = 1; i <= n * 2; i++) read(a[i]);
		init();
		dfs(1);
		if(!flag) puts("-1");
	}
	return 0;
}


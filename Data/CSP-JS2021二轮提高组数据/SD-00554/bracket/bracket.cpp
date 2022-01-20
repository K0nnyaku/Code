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

const int mod = 1e9 + 7;
const int N = 500 + 10;
int n, k;
char c[N], s[N];
int now;
int ans;
bool flag[N];
int l, r;

bool chk(){
	int num = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] != '*') num = 0;
		else num++;
		if(num > k) return false;
	}
	int now = 0;
	for(int i = 1; i <= n; i++) flag[i] = 0;
	for(int i = 1; i <= n; i++){
		if(s[i] == '(') {
			now++;
			flag[now] = 0;
		}
		else if(s[i] == ')') {
			flag[now--] = 0;
		}
		else{
			if(flag[now] && s[i - 1] != '*') return false;
			if(now <= 0) return false;
		}
	}
	return true;
}

void dfs(int now){
	if(now == n + 1) {
		if(l != r) return;
		if(chk()) ans++; 
		return;
	} 
	if(c[now] != '?') dfs(now + 1);
	s[now] = '*';
	dfs(now + 1);
	s[now] = '(';
	l++;
	dfs(now + 1);
	l--;
	s[now] = ')';
	r++;
	if(r > l) ;
	else dfs(now + 1);
	r--;
}

signed main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n); read(k);
	scanf("%s", c + 1);
	for(int i = 1; i <= n; i++) s[i] = c[i], if(s[i] == '(') l++, else if(s[i] == ')') r++;
	dfs(1); 
	return 0;
}


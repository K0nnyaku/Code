#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
inline int read() {
	int x = 0, f = 1;
	char t = getchar();
	while(!isdigit(t)) {
		if(t == '-')
			f = -1;
		t = getchar();
	}
	while(isdigit(t)) {
		x *= 10;
		x += t - '0';
		t = getchar();
	}
	return x*f;
}
inline void write(int x, char t) {
	if(x < 0) {
		putchar('-');
		x = -x;
	}
	if(!x) {
		putchar('0'), putchar(t);
		return ;
	}
	int _stk[15], _stk_cnt = 0;
	while(x) {
		_stk[++ _stk_cnt] = x%10;
		x /= 10;
	}
	while(_stk_cnt)
		putchar(_stk[_stk_cnt --] + '0');
	putchar(t);
}
const int N = 1e2 + 5, mod = 1e9 + 7;
int n, k, f[2][N][N][4], g[N][N][4];
string s[2];
inline int add(int x, int y) {
	return (x + y)%mod;
}
inline int sub(int x, int y) {
	return (x - y + mod)%mod;
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k;
	cin >> s[0];
	s[0] = " " + s[0];
	f[0][0][0][0] = f[1][0][0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= i; j ++) {
			if((s[0][i] == '?' || s[0][i] == '(') && j) {
				for(int l = 0; l < 4; l ++)
					f[0][i][j][0] = add(f[0][i][j][0], f[0][i - 1][j - 1][l]);
			}
				for(int l = 1; l <= min(k, i); l ++) {
					if(s[0][i - l + 1] != '*' && s[0][i - l + 1] != '?')
						break;
					if(j)
						f[0][i][j][1] = add(f[0][i][j][1], f[0][i - l][j][0]);
					f[0][i][j][3] = add(f[0][i][j][3], f[0][i - l][j][2]);
				}
			if(s[0][i] == ')' || s[0][i] == '?') {
				for(int l = 0; l < 3; l ++)
					f[0][i][j][2] = add(f[0][i][j][2], f[0][i - 1][j + 1][l]);
			}
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(s[0][n + 1 - i] == '(')
			s[1][i] = ')';
		else if(s[0][n + 1 - i] == ')')
			s[1][i] = '(';
		else
			s[1][i] = s[0][n + 1 - i];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= i; j ++) {
			if((s[1][i] == '?' || s[1][i] == '(') && j) {
				for(int l = 0; l < 4; l ++)
					f[1][i][j][0] = add(f[1][i][j][0], f[1][i - 1][j - 1][l]);
			}
				for(int l = 1; l <= min(k, i); l ++) {
					if(s[1][i - l + 1] != '*' && s[1][i - l + 1] != '?')
						break;
					if(j)
						f[1][i][j][1] = add(f[1][i][j][1], f[1][i - l][j][0]);
					f[1][i][j][3] = add(f[1][i][j][3], f[1][i - l][j][2]);
				}
			if(s[1][i] == ')' || s[1][i] == '?') {
				for(int l = 0; l < 3; l ++)
					f[1][i][j][2] = add(f[1][i][j][2], f[1][i - 1][j + 1][l]);
			}
		}
	}
	g[0][0][0] = 1;
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j <= i; j ++) {
			if((s[0][i] == '?' || s[0][i] == '(') && j) {
				g[i][j][0] = add(g[i - 1][j - 1][0], 
					add(g[i - 1][j - 1][2], g[i - 1][j - 1][3]));
			}
				for(int l = 1; l <= min(k, i); l ++) {
					if(s[0][i - l + 1] != '*' && s[0][i - l + 1] != '?')
						break;
					if(j)
						g[i][j][1] = add(g[i][j][1], g[i - l][j][0]);
					g[i][j][3] = add(g[i][j][3], g[i - l][j][2]);
				}
			for(int l = 0; l < 3; l ++)
				g[i][j][2] = add(g[i][j][2], g[i - 1][j + 1][l]);
		}
	}
	write(sub(add(f[0][n][0][2], f[1][n][0][2]), g[n][0][2]), '\n');
	return 0;
}

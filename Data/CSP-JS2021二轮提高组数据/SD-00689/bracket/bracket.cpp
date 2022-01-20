#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
#define mod 1000000007

using namespace std;

int read() {
	int x = 0, f = 1; char ch;
	ch = getchar();
	while(ch > '9' || ch < '0') {if(ch == '-') f = -1; ch = getchar();}
	while(ch <= '9' && ch >= '0') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}

int n, k, l, ans, cnt, s[505], sta[505];

char a[505]; 

void read_itt() {
	n = read(); k = read();
	cin >> a;
	for(int i = 1; i <= n; i++) {
		if(a[i - 1] == '?') s[++l] = 0;
		if(a[i - 1] == '(') s[++l] = 1;
		if(a[i - 1] == ')') s[++l] = 2;
		if(a[i - 1] == '*') s[++l] = 3;
	}
	n = l;
//	for(int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
}

bool judg(int u, int las, int len) {
	if(cnt <= 0) return false;
//	cout << "rt" << endl;
//	printf("u = %d\n", u); 
//	for(int i = 1; i <= u; i++) cout << s[i] << " "; cout << endl;
	if(las == 3 && u - sta[cnt] - 1 > len) return false;
//	printf("u = %d, this is right ::  ", u);
//	printf("las = %d, len = %d, sta[cnt] = %d, cnt = %d, u - sta[cnt] - 1 = %d\n", las, len, sta[cnt], cnt, u - sta[cnt] - 1);
//	for(int i = 1; i < u; i++) printf("%d ", s[i]); printf("\n");
	return true;
}

void dfs(int u, int las, int len) {	// 在填第 u 个，上一个一个是las，*连续len个 
//	printf("test2\n");
	if(len > k) return;
//	printf("test3\n");
	if(u > n) {
//		cout << "test" << endl;
//		for(int i = 1; i <= n; i++) cout << s[i] << " "; cout << endl;
		if(cnt == 0 && las == 2) {
			ans++;
//			printf("ans ::   ");
//			for(int i = 1; i <= n; i++) printf("%d ", s[i]); printf("\n");
		}
		return;
	}
//	printf("u = %d, las = %d, len = %d, cnt = %d, s[u] = %d\n", u, las, len, cnt, s[u]);
//	for(int i = 1; i < u; i++) printf("%d ", s[i]); printf("\n");
	int tmp;
	if(s[u] == 1) {
		sta[++cnt] = u;
		dfs(u + 1, 1, 0);
		cnt--;
	}
	if(s[u] == 2) {
		if(cnt == 0) return;
		tmp = sta[cnt];
		cnt--;
		dfs(u + 1, 2, 0);
		cnt++; sta[cnt] = tmp;
	}
	if(s[u] == 3) dfs(u + 1, 3, len + 1);
	if(s[u] == 0) {
//		printf("test1\n");
		s[u] = 3; dfs(u + 1, 3, len + 1); s[u] = 0;
		s[u] = 1; sta[++cnt] = u; dfs(u + 1, 1, 0); cnt--; s[u] = 0;
		if(judg(u, las, len)) {
			s[u] = 2; tmp = sta[cnt]; cnt--;
			dfs(u + 1, 2, 0); cnt++; s[u] = 0; sta[cnt] = tmp;
//			cout << "test" << endl;
//			for(int i = 1; i <= u; i++) cout << s[i] << " "; cout << endl;
		}
	}
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read_itt();
	if(s[1] == 2 || s[1] == 3 || s[n] == 1 || s[n] == 3) printf("0\n");
	else {
		sta[++cnt] = 1;
		dfs(2, 1, 0);
		printf("%d\n", ans);
	}
//	for(int i = 1; i <= n; i++) printf("%d ", s[i]); printf("\n");
	fclose(stdin); fclose(stdout);
	return 0;
}


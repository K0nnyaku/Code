#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <vector>
#define write(n) (n < 0 ? (putchar('-'), rite(-n)) : rite(n))
using namespace std;
const int mod = 1e9 + 7;
inline int read() {
	int x = 0, b = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			b = 0;
		}
		c = getchar(); 
	}
	while (c >= '0' && c <= '9') {
		x = (x << 1) + (x << 3) + (c ^ '0');
		c = getchar();
	}
	return b ? x : -x;
}
void rite(int n) {
	if (n > 9) {
		rite(n / 10);
	}
	putchar(n % 10 ^ '0');
}
char s[503];
int len, k;
int a[502];
deque<int> team;
int ans = 0;
inline bool check() {
	stack<int> key;
	int sum = 0;
	for (int i = 1; i <= len; ++i) {
		printf("%d", a[i]);
	}
	for (int i = 1; i <= len; ++i) {
		if (a[i] == 1 || a[i] == 2) {
			sum = 0;
			if (key.empty()) {
				key.push(a[i]);
				continue;
			}
			if (key.top() == a[i]) {
				key.push(a[i]);
			} else {
				key.pop();
			}
		} else {
			if (++sum > k) {
				printf(" %d", 0);
				return false;
			}
		}
	}
	printf(" %d", key.empty());
	return key.empty();
}
void DFS() {
	if (team.empty()) {
		if (check()) {
			if (++ans >= mod) {
				ans -= mod;
			} 
		}
		return;
	}
	int k = team.front();
	team.pop_front();
	for (int i = 1; i <= 3; ++i) {
		a[k] = i;
		DFS();
	}
	team.push_front(k);
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout); 
	scanf("%d%d%s",&len, &k, s);
	len -= 2;
	for (int i = 1; i <= len; ++i) {
		if (s[i] == '(') {
			a[i] = 1;
		} else if (s[i] == ')') {
			a[i] = 2;
		} else if (s[i] == '*') {
			a[i] = 3;
		} else {
			team.push_back(i);
		}
	}
	if (team.size() > 40) {
		putchar('0');
		return 0;
	}
	DFS();
	printf("%d", ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

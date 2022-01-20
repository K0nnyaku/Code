#include <bits/stdc++.h>
#define N 100005
using namespace std;

int n, m1, m2, sum = -1;
int num1, num2, ans;
int cnt1, cnt2, last;
struct data {
	int a, b;
}f1[N];
struct be {
	int x, y;
}f2[N];
int g1[N], g2[N];

int read() {
	char ch = getchar();
	int f = 0, h = 1;
	while(!isdigit(ch)) {
		if(ch == '-')
		h = -1;
		ch = getchar();
	}
	while(isdigit(ch)) {
		f = f * 10 + ch - '0';
		ch = getchar();
	}
	return f;
}

int kmp1(data s, data t) {
	if(s.a == t.a)
	return s.b < t.b;
	return s.a < t.a;
}

int kmp2(be s, be t) {
	if(s.x == t.x)
	return s.y < t.y;
	return s.x < t.x;
}

int air(int guonei, int guoji) {
	if(num1 == 0 && num2 == 0) {
		return ans;
	}
	int s = -1, j = -1;
	if(num1 != 0 && guonei != 0) {
		num1--; ans++;
		g1[cnt1++] = f1[m1 - num1 + 1].b;
		sort(g1 + 1, g1 + cnt1 + 1);
		for (int i = 1; i <= cnt1; i++) {
			if(g1[i] > f1[m1 - num1 + 1].a)
			break;
			s++;
		}
	}
	else num1--, s = 0;
	if(num2 != 0 && guoji != 0) {
		num2--; ans++;
		g2[cnt2++] = f2[m2 - num2 + 1].y;
		sort(g2 + 1, g2 + cnt2 + 1);
		for (int i = 1; i <= cnt2; i++) {
			if(g1[i] > f1[m2 - num2 + 1].a)
			break;
			j++;
		}
	}
	else num2--, j = 0;
	air(guonei + s, guoji + j);
}

int main() {
	freopen("airport.in", "r",stdin);
	freopen("airport.out", "w", stdout);
	n = read();
	m1 = read(); m2 = read();
	for (int i = 1; i <= m1; i++)
	f1[i].a = read(), f1[i].b = read();
	sort(f1 + 1, f1 + m1 + 1, kmp1);
	for (int i = 1; i <= m2; i++)
	f2[i].x = read(), f2[i].y = read();
	sort(f2 + 1, f2 + m2 + 1, kmp2);
	int l = 0, r = n;
	while(l <= r) {
		int mid = (l + r) / 2;
		num1 = m1, num2 = m2;
		ans = 0;
		cnt1 = 0, cnt2 = 0;
		air(mid, n - mid);
		if(ans > sum) {
			sum = ans;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}
	printf("%d", sum);
	return 0;
}

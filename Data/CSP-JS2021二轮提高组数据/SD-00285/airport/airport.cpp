#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
inline int read() {
	int x = 0, f = 1; char ch;
	while (ch > '9' || ch < '0') {if (ch == '-') f = -1; ch = getchar();}
	while (ch <='9' && ch >= '0') {x = x * 10 + ch - '0'; ch = getchar();}
	return x * f;
}
const int N = 100005;
struct Edge{
	int a, b;
}in2[N], out2[N], in[N][5], out[N][5];
bool cmp(Edge x, Edge y) {
	return x.a < y.a;
}
int n, m1, m2, ans[N * 2], cnt, tot = 1, js, js2, js3;
long long zzans;
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) scanf("%d%d", &in2[i].a, &in2[i].b);
	for (int i = 1; i <= m2; i++) scanf("%d%d", &out2[i].a, &out2[i].b);
	std::sort(in2 + 1, in2 + m1 + 1, cmp);
	std::sort(out2 + 1, out2 + m2 + 1, cmp);
	for (int i = 1; i <= m1; i++) 
		in[i][0].a = in2[i].a, in[i][0].b = in2[i].b;
	for (int i = 1; i <= m2; i++) 
		out[i][0].a = out2[i].a, out[i][0].b = out2[i].b;
	int m11 = m1, m22 = m2;
	while (in[1][0].a != -1 || in[1][1].a != -1) {
		cnt = js = js3 = 0, tot = tot ? 0 : 1;
		js2++;
		for (int j = 1; j <= m11; j++) {
			if (in[j][0].a == -1 && in[j][1].a == -1) continue;
			//if (in[j][0].a == -1 && in[j][1].a == 0) continue;
			if (in[j][tot].a > cnt) {
				cnt = in[j][tot].b, ans[js2]++;
				in[j][tot].a = -1, in[j][tot].b = -1;
			}
			else {
				in[++js3][!tot].a = in[j][tot].a, in[js3][!tot].b = in[j][tot].b;
				in[j][tot].a = -1, in[j][tot].b = -1;
				js++;
			}
		}
		m11 = js;
	}
	js = cnt = js3 = 0; tot = 1; 
	while (out[1][0].a != -1 || out[1][1].a != -1) {
		cnt = js = js3 = 0, tot = tot ? 0 : 1;
		js2++;
		for (int j = 1; j <= m22; j++) {
			if (out[j][0].a == -1 && out[j][1].a == -1) continue;
			//if (out[j][0].a == -1 && out[j][1].a == 0) continue;
			if (out[j][tot].a > cnt) {
				cnt = out[j][tot].b, ans[js2]++;
				out[j][tot].a = -1, out[j][tot].b = -1;
			}
			else {
				out[++js3][!tot].a = out[j][tot].a, out[js3][!tot].b = out[j][tot].b;
				out[j][tot].a = -1, out[j][tot].b = -1;
				js++;
			}
		}
		m22 = js;
	}
	//for (int i = 1; i <= js2; i++) printf("%d ", ans[i]);
	std::sort(ans + 1, ans + js2 + 1);
	for (int i = js2; i >= js2 - n + 1; i--) zzans += ans[i];
	printf("%lld", zzans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

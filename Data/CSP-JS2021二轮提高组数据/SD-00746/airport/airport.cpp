#include <iostream>
#define f(x) cout << "[" << #x << ": " << (x) << "]";
#define g cout << endl;

#include <queue>
#include <vector>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <functional>

using namespace std;
const int maxn = 1e5 + 9;
int n, m[3], ans[3][maxn], tim[maxn * 2], cnt;
struct plane { int in, out; } a[maxn], last[maxn];
bool operator<(const plane &p1, const plane &p2) { return p1.in < p2.in; }
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, m + 1, m + 2);
	for (int idx = 1;idx < 3;idx++)
	{
		cnt = 0;
		for (int i = 1;i <= m[idx];i++)
			scanf("%d %d", &last[i].in, &last[i].out);
		sort(last + 1, last + m[idx] + 1);
		cnt = m[idx];
		for (int i = 1, used;i <= n;i++)
		{
//			f(i)g
			while (!q.empty())
				q.pop();
			used = i - 1; m[idx] = cnt; cnt = 0;
//			f(m[idx])g
			for (int x = 1;x <= m[idx];x++)
			{
				tim[x] = last[x].in, tim[x + m[idx]] = last[x].out;
//				f(tim[x])f(tim[x + m[idx]])g
			}
			sort(tim + 1, tim + 2 * m[idx] + 1);
			ans[idx][i] = ans[idx][i - 1];
			memcpy(a, last, sizeof (plane) * (m[idx] + 1));
			for (int x = 1, k = 1, t = tim[1];x <= 2 * m[idx] && k <= m[idx];t = tim[++x])	// 时间序
			{
				if (used && t == q.top())
					q.pop(), used--;
				if (t == a[k].in)
				{
					if (used < i)
						q.push(a[k].out), used++, ans[idx][i]++;
					else
						last[++cnt] = a[k];	// 记录下每次没有被选的，这些是 i 变大时有可能被选的 
					k++;
				}
			}
//			f(ans[idx][i])g g g
		}
	}
	int anss = -1;
	for (int i = 0;i <= n;i++)
		anss = max(anss, max(ans[1][i] + ans[2][n - i], ans[1][n - i] + ans[2][i]));
	printf("%d\n", anss);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

































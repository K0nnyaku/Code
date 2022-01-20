#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 25;
int n, m_1, m_2, Ans;
struct SegMent
{
	int L, R;
	bool operator < (const SegMent &X) const { return L < X.L; }
} Nei[N], Wai[N];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m_1, &m_2);
	for (int i = 1; i <= m_1; i++)
		scanf("%d%d", &Nei[i].L, &Nei[i].R);
	for (int i = 1; i <= m_2; i++)
		scanf("%d%d", &Wai[i].L, &Wai[i].R);
	sort (Nei + 1, Nei + 1 + m_1);
	sort (Wai + 1, Wai + 1 + m_2);
	for (int k = 0; k <= n; k++)
	{
		int Cnt = 0, Sum = 0;
		priority_queue <int, vector<int>, greater<int> > Q;
		for (int i = 1; i <= m_1; i++)
		{
			while (Q.size() and Q.top() <= Nei[i].L) Q.pop(), Cnt--;
			if (Cnt < k)
			{
				Cnt++, Sum++;
				Q.push(Nei[i].R);
			}
		}
		Cnt = 0;
		while (Q.size()) Q.pop();
		for (int i = 1; i <= m_2; i++)
		{
			while (Q.size() and Q.top() <= Wai[i].L) Q.pop(), Cnt--;
			if (Cnt < n - k)
			{
				Cnt++, Sum++;
				Q.push(Wai[i].R);
			}
		}
		Ans = max(Ans, Sum);
	}
	printf("%d", Ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}




#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
const int N = 100, INF = 7e10;
int n, k, Ans = INF, Sum, A[N], Vis[N];

void Solve(int Num, int Cnt, int La, int Max, int Min) {
	if (Sum > Ans)	return ;
	if (Num == k + 1) {
		Ans = min(Ans, Sum); return ;
	}
	if (Cnt == (n / k) + 1) {
		Sum += Max - Min;
		Solve(Num + 1, 1, 0, 0, INF);
		Sum -= Max - Min;
	}
	
	for (int i = La + 1; i <= n; i++) {
		if (A[i] == A[La] or Vis[i])	continue;
		Vis[i] = 1;
		Solve(Num, Cnt + 1, i, max(Max, A[i]), min(Min, A[i]));
		Vis[i] = 0;
	}
}

signed main() {
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	for (int i = 1; i <= n; i++)	scanf("%lld",&A[i]);
	
	sort(A + 1, A + n + 1);
	Solve(1, 1, 0, 0, INF);
	
	printf("%lld",Ans);
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 5e4 + 10;

long long Q[MAXN];
int n, m;

int main() {
	freopen("In.in", "r", stdin);

	scanf("%d", &n);
	scanf("%lld", &Q[1]);
	for(int i = 2; i <= n; i++) {
		scanf("%lld", &Q[i]);
		Q[i] += Q[i-1];
	}

	scanf("%d", &m);
	while(m--) {
		int st, len;
		scanf("%d%d", &st, &len);
		printf("%lld\n", Q[st+len-1] - Q[st-1]);
	}

	return 0;
}

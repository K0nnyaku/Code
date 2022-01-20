#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define ZERO(x) memset(x, 0, sizeof x);
#define T(x) E[x].to
#define V(x) E[x].val

const int MAXN = 1e6 + 10;
const int INF = 0x3f3f3f3f;

long long Qh[MAXN], Qc[MAXN], Tp[MAXN];
long long len, ans = -INF;
char S[MAXN];

void Solve40() {

	IOR(i, 1, len+1) {
		long long hp = 1, sum = 0;
		IOR(v, i, len+1) {
			if(S[v] == 'A') 
				sum++;
			else 
				hp += S[v] == 'B' ? -1 : 1;
			if(hp == 0) break;
		}
		ans = max(ans, sum);
	}

	printf("%lld\n", ans);
}

void Solve20() {
	int idx = 0;
	Tp[idx++] = 0;	
	
	IOR(i, 1, len+1) {
		Qc[i] += Qc[i-1] + (S[i] == 'A');
		if(S[i] == 'B') 
			Tp[idx++] = i;
	}
	Tp[idx++] = len+1;

	IOR(i, 0, idx-1) 
		ans = max(ans, Qc[Tp[i+1]-1] - Qc[Tp[i]]);
	
	printf("%lld\n", ans);
}

int main() { /**/
#ifdef LOCAL
	freopen("In.in", "r", stdin);
	freopen("Out.out", "w", stdout);
#endif

	scanf("%s", S+1); len = strlen(S+1);

	bool flag = 0;
	IOR(i, 1, len+1) 
		if(S[i] == 'C') {
			flag = 1;
			break;
		}
	if(flag) 
		Solve40();
	else
		Solve20();

	return 0;
} /**/
#include<bits/stdc++.h>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)
#define LOR(i, st, ed) for(int i = st; i > ed; i--)
#define EOR(i, x) for(int i = Head[x]; i; i = E[i].next)
#define T(x) E[x].to
#define V(x) E[x].val

struct FastIN
{
	template<typename T>
	FastIN& operator>>(T& x)
	{
		char c,l;
		for(c=0;!isdigit(c);c=getchar())l=c;
		for(x=0;isdigit(c);c=getchar())x=x*10-'0'+c;
		if(l=='-')x=-x;
		return *this;
	}
}IN;

const int MAXN = 2e3 + 10;
const int MAXM = 20 + 10;
const int BASIC = 400;
const int INF = 0x3f3f3f3f;

vector<int> Ans;
int A[MAXN], B[MAXN], F[MAXN][MAXN], Way[MAXN][MAXM][MAXN];
int n, m, ans, ansP, ansD, idx;

void Init();
void Work(int i, int j, int k);
int Abs(int x);

int main() { /**/
#ifdef LOCAL
	freopen("I:\\Code\\In.in", "r", stdin);
	freopen("I:\\Code\\Out.out", "w", stdout);
#endif
	IN >> n >> m;
	while(n && m) {
		IOR(i, 1, n+1) IN >> A[i] >> B[i];	

		Init();
		IOR(i, 1, n+1) {
			IOR(j, 0, m+1) IOR(v, -400, 400 + 1) 
				Way[i][j][v+BASIC] = Way[i-1][j][v+BASIC];

			LOR(j, m, 0) IOR(v, -400, 400 + 1) {
				if(v - (A[i] - B[i]) < -400 || v - (A[i] - B[i]) > 400) continue;
				if(F[j][v+BASIC] < F[j-1][v - (A[i]-B[i]) + BASIC] + A[i] + B[i] ) {
					Way[i][j][v + BASIC] = i;

					F[j][v+BASIC] = 
						F[j-1][v - (A[i]-B[i]) + BASIC] + A[i] + B[i];
				}

			}
		}

		IOR(i, -400, 400 + 1) 
			if(F[m][i+BASIC] > 0 && 
				(Abs(ans) > Abs(i) || 
				(Abs(ans) == Abs(i) && F[m][i+BASIC] > F[m][ans+BASIC])) ) ans = i;

//		cout << ans << "\n";
//		cout << F[m][ans+BASIC] << "\n";
//		cout << Way[n][m][ans+BASIC] << " \n";

		Work(n, m, ans+BASIC);

		printf("Jury #%d\nBest jury has value %d for prosecution and value %d for defence:\n",++idx, ansD, ansP);

		IOR(i, 0, Ans.size()) 
			cout << " " << Ans[i];


		IN >> n >> m;

//		if(n + m)
			cout << "\n\n";
//		else
//			cout << "\n";
	}

	return 0;
} /**/

void Init() {
	memset(F, -0x3f, sizeof F);
	F[0][BASIC] = 0;
	ans = INF;
	ansP = ansD = 0;
	Ans.clear();
}

int Abs(int x) {
	return x < 0 ? -x : x;
}

void Work(int i, int j, int k) {
	int T = Way[i][j][k];

	if(!j) return ;

	if(j)
		Work(T-1, j-1, k - (A[T] - B[T]) );

	ansD += A[T];
	ansP += B[T];
	Ans.push_back(T);

}









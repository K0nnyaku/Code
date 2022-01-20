#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
const int N = 4e4 + 55, M = 1e3 + 5;
int n, q, m, root, Ans;
int A[N], B[N], T[N];
int L[M], R[M], Val[N];
int Gr[N], S[M][N], P[M][M];

void Handle(int l, int r, int ll, int rr) { 
	for (int i = l; i <= r; i++) {
		if (T[A[i]] == 0)	T[A[i]] = S[rr][A[i]] - S[ll][A[i]];
		T[A[i]]++;
		if (T[A[i]] > T[Ans])	Ans = A[i];
		else	if (T[A[i]] == T[Ans])	Ans = min(Ans, A[i]);
	}
}

void Clear(int l, int r) {
	for (int i = l; i <= r; i++)	T[A[i]] = 0;
}

void Solve(int l, int r) {
	Ans = 0;
	if (Gr[r] - Gr[l] <= 1)	{//如果写Gr[r]==Gr[l],相减等于1时在else里就会出问题 
		for (int i = l; i <= r; i++) {
			T[A[i]]++;
			if (T[A[i]] > T[Ans])	Ans = A[i];
			else	if (T[A[i]] == T[Ans])	Ans = min(Ans, A[i]);
		}
		Clear(l, r);
	}
	else {
		Ans = P[Gr[l]+1][Gr[r]-1]; 
		T[Ans] = S[Gr[r]-1][Ans] - S[Gr[l]][Ans];
		Handle(l, R[Gr[l]], Gr[l], Gr[r]-1);
		Handle(L[Gr[r]], r, Gr[l], Gr[r]-1);
		Clear(l, R[Gr[l]]); Clear(L[Gr[r]], r);
	}
}

int main() {
#ifdef FIO
    freopen("D:/VS Code/In.in", "r", stdin);
    freopen("D:/VS Code/Out.out", "w", stdout);
#endif
	scanf("%d%d",&n,&q);
	for (int i = 1; i <= n; i++) {
		scanf("%d",&A[i]);
		B[i] = A[i];
	}	
	
	sort(B+1, B+n+1);
	m = unique(B+1, B+n+1) - B - 1;
	for (int i = 1, x; i <= n; i++) {
		x = A[i];
		A[i] = lower_bound(B+1, B+m+1, A[i]) - B;
		Val[A[i]] = x;
	}
	
	root = sqrt(n);
	for (int i = 1; i <= root; i++) {
		L[i] = (i - 1) * root + 1;
		R[i] = i * root;
	}
	if (R[root] < n) {
		L[++root] = R[root] + 1; R[root] = n;//zhu!!!!
	}
	
	for (int i = 1; i <= root; i++) {
		for (int j = L[i]; j <= R[i]; j++) {
			T[A[j]]++; Gr[j] = i;
		}	
		for (int j = 1; j <= m; j++)	S[i][j] = T[j];
	}
	for (int i = 1; i <= root; i++) {
		memset(T, 0, sizeof(T));
		int Num = 0;
		for (int j = i; j <= root; j++) {
			for (int k = L[j]; k <= R[j]; k++) {
				T[A[k]]++;
				if (T[A[k]] > T[Num])	Num = A[k];
				else if (T[A[k]] == T[Num])	Num = min(Num, A[k]);
			}
			P[i][j] = Num;
		}
	}
	
	memset(T, 0, sizeof(T));
	for (int i = 1, l, r; i <= q; i++) {
		scanf("%d%d",&l,&r);
		l = ((l + Val[Ans] - 1) % n) + 1;
		r = ((r + Val[Ans] - 1) % n)	+ 1;
		if (l > r)	swap(l, r);
		//printf("l=%d r=%d\n",l,r);
		Solve(l, r);
		printf("%d\n",Val[Ans]);
	}
	
	return 0;
}
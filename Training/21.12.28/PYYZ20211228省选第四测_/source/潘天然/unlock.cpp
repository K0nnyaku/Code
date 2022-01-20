#include<bits/stdc++.h>
#define lf long double
using namespace std;
const int N = 350;
int t, n, k, A[N], P[N];
int Son, Mom; 

int Lowbit(int x) {
	return x & (-x);
}

void Init() {
	Son = Mom = 0;
	memset(A, 0, sizeof(int) * (n + 5));
	memset(P, 0, sizeof(int) * (n + 5));
}

int main() {
	freopen("unlock.in","r",stdin);
	freopen("unlock.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		scanf("%d%d",&n,&k);
		Init();
		for (int i = 1; i <= n; i++) scanf("%d",&A[i]);
		for (int i = 1; i <= n; i++) {
			P[i] += (1 << (i - 1));
			int j = i;
			while (!((P[i] >> (A[j] - 1)) & 1)) {
				P[i] += (1 << (A[j] - 1));
				j = A[j];
//				printf("P[%d] = %d\n",i,P[i]);
			}
		}
		
		for (int iter = 0; iter < (1 << n); iter++) {
			int Cnt = 0, Num = iter;
			while (Num) {
				Cnt++; Num -= Lowbit(Num);
			}
			if (Cnt != k)	continue;
			int Sum = 0; Mom++;
			for (int i = 0; i < n; i++) {
				if ((iter >> i) & 1) {
					Sum |= P[i + 1];
				}
			}
//			printf("Sum = %d\n",Sum);
			if (Sum == ((1 << n) - 1)) Son++;//, printf("---Son = %d\n",Son);
		}
		
//		printf("%d %d\n",Son,Mom);
		printf("%.9lf\n",1.0 * Son / (1.0 * Mom));
	}
	
	return 0;
}

/*
4
5 1
2 5 4 3 1
5 2 
2 5 4 3 1
5 3
2 5 4 3 1
5 4
2 5 4 3 1
*/

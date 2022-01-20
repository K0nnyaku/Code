#include<cstdio>
#include<cstring>
using namespace std;
const int N = 1e6 + 55;
int t, n, A[N], B[N];
bool Flag, Ans[N];

void Solve(int l, int r, int num) {
	if (l > r) {
		bool flag = true;
		for (int i = 1; i <= n; i++) {
			if (B[i] != B[n * 2 - i + 1]) {
				flag = false; break;
			}
		}
		if (flag)	Flag = true;
		return ;
	}
	
	B[num] = A[l]; Ans[num] = true;
	Solve(l + 1, r, num - 1);
	if (Flag)	return ;
	if (l != r) {
		B[num] = A[r]; Ans[num] = false;
		Solve(l, r - 1, num - 1);
		if (Flag)	return ;	
	}
}

int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while (t--) {
		//Init();
		Flag = false;
		scanf("%d",&n);
		for (int i = 1; i <= n * 2; i++)	scanf("%d",&A[i]);
		
		Solve(1, n * 2, n * 2);
		
		if (Flag) {
			for (int i = n * 2; i >= 1; i--) {
				if (Ans[i])	printf("L");
				else	printf("R");
			}
		}
		else	printf("-1");
		printf("\n");
	}
	
	return 0;
} 

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/

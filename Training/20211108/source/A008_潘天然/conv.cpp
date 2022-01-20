#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 2e5 + 55;
int n, A[N], B[N], C[N];

int main() {
	freopen("conv.in","r",stdin);
	freopen("conv.out","w",stdout);
	scanf("%d",&n);
	for (int i = 0; i < n; i++)	scanf("%d",&A[i]);
	for (int i = 0; i < n; i++)	scanf("%d",&B[i]);
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			C[i] = max(C[i], A[j] + B[(i - j + n) % n]);
		}
	}
	
	for (int i = 0; i < n; i++)	printf("%d ",C[i]);
	return 0;
}

/*
5 
3 2 4 7 5 
8 9 6 1 0
*/

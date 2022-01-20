#include<cstdio>
#include<algorithm>
#include<bitset>
using namespace std;
const int MAXN = 1e3 + 10;
const int MAXM = 5 + 10;
const int WG[] = {0, 1, 2, 3, 5, 10, 20};

bitset<MAXN> B;

int W[MAXM];
int n;

int main() {
	for(int i = 1; i <= 6; i++) scanf("%d", &W[i]);

	B[0] = 1;
	for(int i = 1; i <= 6; i++)
		for(int j = 0; j < W[i]; j++) {
			B = B | (B << WG[i]);	
		}

	printf("Total=%d", B.count()-1);

	return 0;
}

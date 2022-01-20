#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 35 + 10;

long long S[MAXN];

int main() {
	S[1] = 2; 
	for(int i = 2; i <= 35; i++) S[i] = 3 * S[i-1] + 2;

	int x;
	while(~scanf("%d", &x)) {
		printf("%lld\n", S[x]);
	}

	return 0;
}

#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
const int MAX = 65;

unsigned long long F[MAX], S[MAX];

int main() {
//	freopen("In.in", "r", stdin);

	memset(S, 0x7f, sizeof S);
	
	F[1] = 1, F[2] = 3;
	for(int i = 1; i <= 64; i++) 
		F[i] = pow(2, i) - 1;

	S[1] = 1, S[2] = 3;
	for(int i = 3; i <= 64; i++) {
		for(int j = 1; j < i; j++) 
			S[i] = min(S[i], S[j] * 2 + F[i-j]);
	}

//	for(int i = 1; i <= 64; i++) 
//		printf("i = %d, F = %llu\n", i, S[i]);
	int x;
	while(~scanf("%d", &x)) {
		printf("%llu\n", S[x]);
	}

	return 0;
}

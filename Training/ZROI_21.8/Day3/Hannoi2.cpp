#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAXF = 33;
const int MAXS = 64 + 10; 

long long F[MAXF], S[MAXS];
int n;

int main() {
	for(int i = 1; i <= 31; i++) 
		F[i] = pow(2, i) - 1;

	S[1] = 1; S[2] = 3;
	for(int i = 3; i <= 64; i++) 
		S[i] = F[(i-1)/2] + F[i-(i-1)/2-1] + S[(i-1)/2] + S[i-(i-1)/2-1a] + 1;

	for(int i = 1; i <= 64; i++)
		printf("i = %d, F = %lld, S = %lld\n", i, F[i], S[i]);

	return 0;
}

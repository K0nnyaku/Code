#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 1500 + 10;

int Num[MAXN];
int x, iNdex;
bool Ug[MAXN];

int main() {
	freopen("In.in", "r", stdin);

	int P[3] = {2, 3, 5};
	while(P[0] < MAXN && (P[1] = 3)) 
		while(P[1] < MAXN && (P[2] = 5))
			while(P[2] < MAXN && P[0] * P[1] * P[2] < MAXN) {
				Ug[P[0] * P[1] * P[2]] = 1;
			}
	Ug[2] = Ug[3] = Ug[5] = 1;

	for(int i = 1; i < MAXN; i++) 
		if(Ug[i]) Num[iNdex++] = i;

	while(~scanf("%d", &x)) {
		if(!x) continue; 
		printf("%d\n", Num[x-1]);
	}

	return 0;
}

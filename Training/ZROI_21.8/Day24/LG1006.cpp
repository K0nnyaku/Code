#include<cstdio>
#include<iostream>
using namespace std;

#define IOR(i, st, ed) for(int i = st; i < ed; i++)

const int MAX = 60;
long long Mp[MAX][MAX], F[MAX*MAX][MAX][MAX];
int n, m;

int main() {
#ifdef LOCAL
    freopen("In.in", "r", stdin);
    freopen("Out.out", "w", stdout);
#endif
	
	scanf("%d%d",&n, &m);
    IOR(i, 1, n+1) IOR(v, 1, m+1)
        scanf("%lld", &Mp[i][v]);
	
	for(int p = 1; p <= n + m; p++) 
		for(int ft = 1; ft <= n; ft++)
			for(int sd = 1; sd <= n; sd++) {
				int yft = p - ft + 1, ysd = p - sd + 1;
				if(!yft or !ysd) continue;
				F[p][ft][sd] = Mp[ft][yft] + Mp[sd][ysd]
				  + max(max(F[p-1][ft][sd], F[p-1][ft-1][sd-1]), max(F[p-1][ft][sd-1], F[p-1][ft-1][sd]));
				if(ft == sd) F[p][ft][sd] -= Mp[ft][yft];
			}
	printf("%lld",F[n+m][n][n]);
	
	return 0;
}
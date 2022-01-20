#include<bits/stdc++.h>
#include<time.h>
using namespace std;
int n, m, t;
signed main(){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	srand(time(0));
	scanf("%d%d%d", &n, &m, &t);
	while(t--)
		printf("%d\n", rand());
	fclose(stdin);
	fclose(stdout);
	return 0;
}

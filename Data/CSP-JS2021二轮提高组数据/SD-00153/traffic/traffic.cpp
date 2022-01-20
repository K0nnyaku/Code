#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <map>

using namespace std;

int n,m; 

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int T;
	scanf("%d%d%d",&n,&m,&T);
	long long sum;
	sum %= (n * m);
	int mod = 50;
	sum = abs(sum); 
	while(T --> 0){
		int v;
		for(int i = 1 ; i < n ; ++i)
		for(int j = 1 ; j <= m ; ++j){
			scanf("%d",&v);
			sum += (1ll + v + rand()) % mod;
		}
		sum %= (n * m);
		for(int i = 1 ; i < m ; ++i)
		for(int j = 1 ; j <= n ; ++j){
			scanf("%d",&v);
			sum += (1ll + v + rand()) % mod;
		}
		sum %= (n * m) % mod;
		int k;
		scanf("%d",&k);
		int u,w;
		while(k --> 0){
			scanf("%d%d%d",&u,&v,&w);
			sum += (1ll + u + v + w + rand()) % mod;
		}
		for(int i = 1 ; i <= n ; ++i)
			sum = (sum +rand()) % mod;
		printf("%d",sum);
	}
	return 0;
}

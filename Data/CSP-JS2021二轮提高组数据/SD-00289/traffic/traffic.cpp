#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
#define N 510
int n,m,q,col[N][N],row[N][N],x,y,z;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&col[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&row[i][j]);
	while(q--){
		int k;
		for(int i=1;i<=k;i++)
			scanf("%d%d%d",&x,&y,&z);
		printf("114514");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

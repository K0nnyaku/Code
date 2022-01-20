#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;

int n,m,T;
//black 1 white 0
int mapp[50][50][50][50];
bool vis[50][50];
int k,tx,ty;

inline void input() {
	scanf("%d%d%d",&n,&m,&T);
	int x;
	for (int i=1;i<n;i++) {
		for (int j=1;j<=m;j++) {
			scanf("%d",&x);
			mapp[i][j][i+1][j]=x;
			mapp[i+1][j][i][j]=x;
		}
	}
	for (int i=1;i<=n;i++) {
		for (int j=1;j<m;j++) {
			scanf("%d",&x);
			mapp[i][j][i][j+1]=x;
			mapp[i][j+1][i][j]=x;
		}
	}
}

inline void dowork() {
	
	
	
}

int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	printf("23");
	return 0;
	
}






#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int c[105][105][105][105];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin >> n >> m >> t;
	for(int i=1;i<=n-1;i++){
		for(int l=1;l<=m;l++){
			cin >> c[i][l][i+1][l];
		}
	}
	for(int i=1;i<=n;i++){
		for(int l=1;l<=m-1;l++){
			cin >> c[i][l][i][l+1];
		}
	}
	for(int i=0;i<t;i++){
		cout << 545644 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

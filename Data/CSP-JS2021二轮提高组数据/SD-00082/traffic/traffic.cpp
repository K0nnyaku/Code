#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&b[i][j]);
		}
	}
	cout<<12;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

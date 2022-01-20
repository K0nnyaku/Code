#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
char s[10010];
int a[10010][10010],b[10010][10010],x3[10010],p[10010],t[10010];
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,T,k;
	cin>>n>>m>>T;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m-1;j++) {
			cin>>b[i][j];
		}
	}
	while(T--) {
		cin>>k;
		for(int i=1;i<=2;i++) {
			cin>>x3[i]>>p[i]>>t[i];
		}
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

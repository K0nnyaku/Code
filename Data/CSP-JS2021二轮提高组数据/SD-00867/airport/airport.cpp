#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int ans1=0,ans2=0;
struct node {
	int ar;
	int la;
};
struct node1 {
	bool f=0;
	int be;
	int ov;
};
node a[100001];
node b[100001];
node1 vis1[10001];
node1 vis2[10001];
int zans1=-1,zans2=-1;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1; i<=m; ++i)scanf("%d%d",&a[i].ar,&a[i].la);
	for(int i=1; i<=q; ++i)scanf("%d%d",&b[i].ar,&b[i].la);
	for(int i=0; i<=n; ++i) {
		int gn=i,gw=n-i,opt1=1,opt2=1;
		ans1=0;
		for(int j=1; j<=m; ++j) {
			int yu=gn;
			for(int k=1; k<=yu; ++k) {
				int cha=a[j].ar-vis1[k].be;
				int he=cha+a[j].la;
				if(he>vis1[k].ov||vis1[k].f==0) {
					vis1[k].be=a[j].ar;
					vis1[k].ov=a[j].la;
					vis1[k].f=1;
					ans1++;
					zans1=max(ans1,zans1);
				}
			}
		}
		
		for(int p=1; p<=q; ++p) {
			ans2=0;
			int yu=gw;
			for(int k=1; k<=yu; ++k) {
				int cha=b[p].ar-vis2[k].be;
				int he=cha+b[p].la;
				if(he>vis2[k].ov||vis2[k].f==0) {
					vis2[k].be=b[p].ar;
					vis2[k].ov=b[p].la;
					vis2[k].f=1;
					ans2++;
					zans2=max(zans2,ans2);
				}
			}
		}
	}
	long long cht=zans2+zans1;
	printf("%lld",cht);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

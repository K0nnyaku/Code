#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m1,m2;
int ans1=0,ans2=0,ans=-1;

struct plane {
	int a,b,id;
}nei[100010],wai[100010];

bool cmp(plane x,plane y) {
	return x.a<y.a;
}

void dfs() {
	for(int i=0;i<=n;i++) {
		ans1=i;
		for(int m=1;m<=i;m++) {
		for(int j=m+1;j<=n;j++) {
				if(nei[m].b<nei[j].a) {
					ans1++;
					nei[j].a=nei[m].a;
					nei[j].b=nei[m].b;
					nei[j].id=nei[m].id;
					continue;
				}
				if(m>i) m=i;
			}
		}
	for(int k=n-i;k>=0;k--) {
		ans2=k;
		for(int n=1;n<=k;n++) {
			for(int l=k+1;l<=n-i;l++) {
				if(wai[n].b<wai[l].a) {
					ans2++;
					wai[l].a=wai[n].a;
					wai[l].b=wai[n].b;
					wai[l].id=wai[n].id;
					continue;
				}
				if(n>k) n=k;
			}
		}
	}
	ans=max(ans1+ans2,ans);
	}
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) {
		scanf("%d%d",&nei[i].a,&nei[i].b);
		sort(nei+1,nei+m1+1,cmp);
		nei[i].id=i;
	}
	for(int j=1;j<=m2;j++) {
		scanf("%d%d",&wai[j].a,&wai[j].b);
		sort(wai+1,wai+m2+1,cmp);
		wai[j].id=j;
	}
	dfs();
	cout<<ans*2<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

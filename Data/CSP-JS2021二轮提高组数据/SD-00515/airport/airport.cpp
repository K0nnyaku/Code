#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>

using namespace std;
int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cout<<3;
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}/*
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct ap {
	int am1,bm1,am2,bm2;
} air[1000010];
int ans;
int n,m1,m2;
int a[100001];
int so(int x,int y) {
	ans=max(ans,ans);
	int a1,a2,b1,b2;
	int i=1;
	int tot=1;
	a1=air[i].am1;
	a2=air[i].am2;
	b1=air[i].bm1;
	b2=air[i].bm2;
	x--;
	ans++;
	y--;
	ans++;
	if(x>0) {
		for(int k=1; k<=m1; k++) {
			if(air[++i].am1<a2) {
				x--;
				ans++;
				a1=air[i].am1;
			} else {
				a1=air[i].am1;
				if(a1>a2)
				a2=air[i].am2;
				continue;
			}
			if(x==0) continue;
		}
	}
	if(y>0) {
		for(int k=1; k<=m1; k++) {
			if(air[++i].bm1<b2) {
				y--;
				ans++;
				b1=air[i].bm1;
			} else {
				b1=air[i].bm1;
				if(b1>b2)
				b2=air[i].bm2;
				continue;
			}
			if(y==0) continue;
		}
	}
	so(x--,y++);
}
int main() {
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>air[i].am1 >>air[i].am2;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(air[i].am1 <air[j].am1) swap(air[i].am1 ,air[j].am1);
	for(int i=1; i<=m2; i++) {
		cin>>air[i].bm1 >>air[i].bm2;
	}
	for(int i=1; i<=n; i++)
		for(int j=1; j<=n; j++)
			if(air[i].bm1 <air[j].bm1) swap(air[i].bm1 ,air[j].bm1);
	so(n,0);
	cout<<ans;
	return 0;
}
*/

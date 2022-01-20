#include<bits/stdc++.h>
using namespace std;
struct feiji {
	int ks,js;
} a[100005],b[100005],c[100005],d[100005];
bool cmp(feiji x,feiji y) {
	return x.ks<y.ks;
}
int zd=-999;
int n,ma,mb,ansa,ansb;
void dfs(int l,int r) {
	if(l>n||r<0) {
		return;
	}
	ansa=0;
	ansb=0;
	c[1].ks=a[1].ks;
	c[1].js=a[1].js;
	d[1].ks=b[1].ks;
	d[1].js=b[1].js;
	if(l!=0) {
		ansa++;
		for(int i=2; i<=ma; i++) {
			for(int j=1; j<=l; j++) {
				if(a[i].ks>c[j].js) {
					ansa++;
					c[j].ks=a[i].ks;
					c[j].js=a[i].js;
					break;
				}
			}
		}
	}
	if(r!=0) {
		ansb++;
		for(int i=2; i<=mb; i++) {
			for(int j=1; j<=r; j++) {
				if(b[i].ks>d[j].js) {
					ansb++;

					d[j].ks=b[i].ks;
					d[j].js=b[i].js;
					break;
				}
			}
		}
	}
	if(ansa+ansb>zd) {
		zd=ansa+ansb;
	}
	dfs(l+1,r-1);
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>ma>>mb;
	for(int i=1; i<=ma; i++)
		cin>>a[i].ks>>a[i].js;
	for(int i=1; i<=mb; i++)
		cin>>b[i].ks>>b[i].js;
	dfs(0,n);
	sort(a+1,a+ma+1,cmp);
	sort(b+1,b+mb+1,cmp);
	cout<<zd;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

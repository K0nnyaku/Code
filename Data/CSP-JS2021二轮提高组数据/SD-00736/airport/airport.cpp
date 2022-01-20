#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
struct fj {
	int a;
	int b;
};
fj gn[50009],gw[50009];
int duilie[50009],dd=1;
int n,m1,m2,sum1=0,sum2=0,sum=0;
void aa(int k) {
	for(int i=m1; i>=1; i--) {
		sum1=0;
		for(int f=1; f<dd; f++) {
			if(gn[i].a<duilie[f]) sum1++;
		}
		if(sum1<k) {
			sum1++;
			sum2++;
			duilie[dd]=gn[i].b;
			dd++;
		}
	}
	for(int  i=1; i<dd; i++) {
		duilie[i]=0;
	}
	dd=1;
	for(int i=m2; i>=1; i--) {
		sum1=0;
		for(int f=1; f<dd; f++) {
			if(gw[i].a<duilie[f]) sum1++;
		}
		if(sum1<n-k) {
			sum1++;
			sum2++;
			duilie[dd]=gw[i].b;
			dd++;
		}
	}
	for(int  i=1; i<dd; i++) {
		duilie[i]=0;
	}
	dd=1;
	if(sum2>sum) {
		sum=sum2;
		return ;
	}
}
int camp(fj x,fj y) {
	if(x.a<y.a) return 0;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>gn[i].a>>gn[i].b;
	}
	for(int i=1; i<=m2; i++) {
		cin>>gw[i].a>>gw[i].b;
	}
	sort(gn+1,gn+m1+1,camp);
	sort(gw+1,gw+m2+1,camp);
	for(int i=0; i<=n; i++) {
		aa(i);
		sum2=0;
	}
	cout<<sum;
	return 0;
}

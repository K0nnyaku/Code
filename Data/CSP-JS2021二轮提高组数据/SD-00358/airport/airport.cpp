#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,a[100001][4],b[100001][4],book1[100001],book2[100001],m1,m2;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int gn,gw,sumgn=0,sumgw=0,ma=0;
	int chang=0;
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		scanf("%d %d",&a[i][1],&a[i][2]);
	}
	for(int i=1; i<=m2; i++) {
		scanf("%d %d",&b[i][1],&b[i][2]);
	}
	for(int i=1; i<=m1; i++) {
		for(int j=1; j<i; j++) {
			if(a[j][1]>a[j+1][1]) {
				chang=a[j][1];
				a[j][1]=a[j+1][1];
				a[j+1][1]=chang;
				chang=a[j][2];
				a[j][2]=a[j+1][2];
				a[j+1][2]=chang;
			}
		}
	}
	for(int i=1; i<=m2; i++) {
		for(int j=1; j<i; j++) {
			if(b[j][1]>b[j+1][1]) {
				chang=b[j][1];
				b[j][1]=b[j+1][1];
				b[j+1][1]=chang;
				chang=b[j][2];
				b[j][2]=b[j+1][2];
				b[j+1][2]=chang;
			}
		}
	}
	for(int i=0; i<=n; i++) {
		gn=i;
		gw=n-i;
		sumgn=0;
		sumgw=0;
		for(int j=1; j<=m1; j++) {
			if(gn==0) break;
			else {
				for(int k=1; k<=gn; k++) {
					if(a[j][1]>=book1[k]) {
						book1[k]=a[j][2];
						sumgn++;
						break;
					}
				}
			}
		}
		for(int o=1; o<=m2; o++) {
			if(gw==0) break;
			else {
				for(int pp=1; pp<=gw; pp++) {
					if(b[o][1]>=book2[pp]) {
						book2[pp]==b[o][2];
						sumgw++;
						break;
					}
				}
			}
		}
		if(ma<(sumgn+sumgw)) {
			ma=sumgn+sumgw;
		}
	}
	cout<<ma;
	return 0;
}


#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int maxn=1e5+10;
int n,m1,m2;
int ans=0,sum=0;
struct timee {
	int arrive;
	int leave;
};
int main(int argc, char** argv) {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	timee home[maxn],ab[maxn];
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>home[i].arrive>>home[i].leave;
	}
	for(int i=1; i<=m2; i++) {
		cin>>ab[i].arrive>>ab[i].leave;
	}
	for(int i=1; i<=m1; i++) {
		for(int j=i; j<=m1; j++) {
			if(home[i].arrive>home[j].arrive) {
				home[i]=home[j];
			}
		}
	}
	for(int i=1; i<=m2; i++) {
		for(int j=i; j<=m2; j++) {
			if(ab[i].arrive>ab[j].arrive) {
				ab[i]=ab[j];
			}
		}
	}
	int n1=0,n2=n-n1;
	while(n2>=0) {
		if(n1>0) {
			for(int i=1; i<=n1; i++) {
				for(int j=1; j<=m1; j++) {
					if(j<=n1) {
						sum++;
						n1--;
					} else for(int k=1; k<=m1; k++) {
							if(home[j].arrive>home[k].leave) {
								sum++;
							}
						}
				}
			}
		}
		ans=max(ans,sum);
		sum=0;
		n2--;
		n1++;
	}
	cout<<ans<<endl;
	return 0;
}

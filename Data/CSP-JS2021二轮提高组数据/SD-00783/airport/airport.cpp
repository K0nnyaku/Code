#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;

int a[50001][2],b[50001][2],x[50001],z[50001],z1[50001];

int main() {
    freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int y=0,t=0,v=1,maxx,maxt,e=0,e1=0,f[101],f1[101];
	int n,m,l,sum=0;
	
	cin>>n>>m>>l;
	
	for (int i=1; i<=m; i++) {
		for (int j=1; j<=2; j++)
			cin>>a[i][j];
			f[i]=a[i][2];
	}
	
	for (int i=1; i<=m; i++) {
		for (int j=1; j<i; j++) {
			if (f[j]>f[j+1]) {
				swap (f[j],f[j+1]);
			}
		}
	}
	
	for (int i=1; i<=l; i++) {
		for (int j=1; j<=2; j++)
			cin>>b[i][j];
			f1[i]=b[i][2];
	}
    
		for (int i=1; i<=l; i++) {
		for (int j=1; j<i; j++) {
			if (f1[j]>f1[j+1]) {
				swap (f1[j],f1[j+1]);
			}
		}
	}
    
    maxx=max(m,l);
    maxt=max(f[m],f1[l]);
    
	for (int j=0; j<=n; j++) {
		int wz1=0,wz2=0;
		for (int i=1; i<=maxt; i++) { 
			for (int k=1; k<=maxx; k++) {
				if (a[k][1]==i) {
					if (wz1<j) {
						sum++;
						wz1++;
						y++;
						z[y]=k;

					}
				}
				if (y>=1&&e==0) {
					for (int o=1; o<=y; o++) {
						if (a[z[o]][2]==i) {
							wz1-=1;
							e=1;
						}
					}
				}
				if (b[k][1]==i) {
					if (wz2<n-j) {

						sum++;
						wz2++;
						t++;
						z1[t]=k;
					}
				}
				if (t>=1&e1==0) {
					for (int o=1; o<=t; o++) {
						if (b[z1[o]][2]==i) {
							wz2--;
							e1=1;
						}
					}
				}

			}
			e=0;
			e1=0;
			
		}
		x[v]=sum;
		sum=0;
		v++;
		t=1;
		y=1;
	}
	
    for (int i=0; i<v; i++) {
		for (int j=1; j<v-i; j++) {
			if (x[j]>x[j+1]) {
				swap (x[j],x[j+1]);
			}
		}
	}
	cout<<x[v];

	fclose(stdin);
	fclose(stdout);
	return 0;
}




#include<iostream>
#include<cstdio>
using namespace std;
int a[100001][3];
bool b[100001];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,ma,mb,t,mmax=0;
	cin>>n>>ma>>mb;
	for(int i=1; i<=ma; i++) {
		cin>>a[i][0]>>a[i][1];
		a[i][2]=1;
		b[i]=false;
		if(a[i][1]>mmax)mmax=a[i][1];
	}
	for(int i=1; i<=mb; i++) {
		cin>>a[i+ma][0]>>a[i+ma][1];
		a[i+ma][2]=2;
		b[i+ma]=false;
		if(a[i+ma][1]>mmax)mmax=a[i+ma][1];
	}
	for(int i=ma; i>=1; i--) {
		for(int j=1; j<=i; j++) {
			if(a[i][0]>a[i+1][0]) {
				t=a[i][0];
				a[i][0]=a[i+1][0];
				a[i+1][0]=t;
				t=a[i][1];
				a[i][1]=a[i+1][1];
				a[i+1][1]=t;
				t=a[i][2];
				a[i][2]=a[i+1][2];
				a[i+1][2]=t;
			}
		}
	}
	int na,nb,sum=0,maxx=0;
	for(int i=0; i<=n; i++) {
		na=i;
		nb=n-i;
		for(int j=1; j<=mmax; j++) {
			for(int k=1; k<=ma+mb; k++) {
				if(a[k][1]==j) {
					if(b[k]) {
						if(a[k][2]==1) {
							na++;
						}
						if(a[k][2]==2) {
							nb++;
						}
					}
				}
				if(a[k][0]==j) {
					if(a[k][2]==1) {
						if(na>=1) {
							na--;
							sum++;
							b[k]=true;
						}
					}
					if(a[k][2]==2) {
						if(nb>=1) {
							nb--;
							sum++;
							b[k]=true;
						}
					}
				}
			}
		}
		for(int k=1; k<=ma+mb; k++) {
			b[k]=false;
		}
		if(sum>maxx)maxx=sum;
		sum=0;
	}
	cout<<maxx<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

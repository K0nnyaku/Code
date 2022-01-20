#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
int s,n,m,sum1[50010],f[50010],sum2[50010],ff[50010],sum3,maxa,a[50010],aa[50010],b[50010],bb[50010];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>s>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i]>>aa[i];
	}
	for(int i=1;i<=m;i++) {
		cin>>b[i]>>bb[i];
	}
	int t=0;
	for(int i=n;i>=1;i--) {
		t=0;
		for(int j=1;j<i;j++) {
			if(a[j]>a[j+1])  {
			   swap(a[j],a[j+1]);
			   swap(aa[j],aa[j+1]);	
			   t=1;
			}
		}
		if(t==0) break;
	}
	for(int i=m;i>=1;i--) {
		t=0;
		for(int j=1;j<i;j++) {
			if(b[j]>b[j+1])  {
			   swap(b[j],b[j+1]);
			   swap(bb[j],bb[j+1]);	
			   t=1;
			}
		}
		if(t==0) break;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			if(f[j]<a[i]) {
				f[j]=aa[i];
				sum1[j]++;
				break;
            }
        }
    }
	for(int i=1;i<=m;i++) {
		for(int j=1;j<=m;j++) {
			if(ff[j]<b[i]) {
				ff[j]=bb[i];
				sum2[j]++;
				break;
			}
		}
	}
	for(int i=0;i<=s;i++) {
		sum3+=sum1[i];
		m-=sum2[s-i+1];
		int t=sum3+m;
		if(t>maxa) maxa=t;
	}
	cout<<maxa;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

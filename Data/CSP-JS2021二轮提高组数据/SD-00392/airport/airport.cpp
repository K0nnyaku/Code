#include<iostream>
#include<cstdio>
#define M 100001
using namespace std;
int n,m1,m2,a[M],b[M],ans,t,ti;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		t=max(t,y);
		for(int j=x;j<=y;j++)a[j]++;
	}
	for(int i=1;i<=m2;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		ti=max(t,y);
		for(int j=x;j<=y;j++)b[j]++;
	}
	for(int i=0;i<=n;i++){
		int h=i,ab=n-i,k1=m1,k2=m2;
		for(int j=1;j<=t;j++){
			if(a[j-1]!=a[j]&&a[j]>h)k1=k1-(max(a[j],a[j-1])-min(a[j],a[j-1]));
		}
		for(int j=1;j<=ti;j++){
			if(b[j-1]!=b[j]&&b[j]>ab)k2=k2-(max(b[j],b[j-1])-min(b[j],b[j-1]));
		}
		ans=max(ans,k1+k2);
	}
	printf("%d",ans);
	return 0;
	fclose(stdin);
	fclose(stdout);
}

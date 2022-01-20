#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;

int n,m,t,k,cnt,ans;
int gw[500000],t1[110],t2[110];

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=0;i<m*(n-1);i++){
			scanf("%d",&gw[i]);
	}
	for(int i=m*(n-1);i<m*(n-1)+n*(m-1);i++){
			scanf("%d",&gw[i]);
	}
	for(int i=0;i<t;i++){
		scanf("%d",&k);
		for(int j=m*(n-1)+n*(m-1);j<m*(n-1)+n*(m-1)+k;j++){
			scanf("%d%d%d",&gw[j],&t1[j],&t2[j]);
		}
		cnt=n*m/2;
		sort(gw,gw+m*(n-1)+n*(m-1)+k);
		for(int i=0;i<cnt;i++){
			ans+=gw[i];
		}
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

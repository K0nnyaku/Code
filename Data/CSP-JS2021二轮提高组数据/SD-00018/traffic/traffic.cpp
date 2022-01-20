#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,k,i,j,x,y,z;
	long long cnt2=0,cnt3=0;
	scanf("%d%d%d",&n,&m,&t);
	for(i=1;i<n;i++) for(j=0;j<m;j++) scanf("%d",&x);
	for(i=0;i<n;i++) for(j=1;j<m;j++) scanf("%d",&x);
	for(i=0;i<t;i++){
		scanf("%d",&k);
		cnt2=cnt3=0;
		for(j=0;j<k;j++){
			scanf("%d%d%d",&x,&y,&z);
			if(z) cnt2+=x;
			else cnt3+=x; 
		}
		printf("%lld\n",min(cnt2,cnt3));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

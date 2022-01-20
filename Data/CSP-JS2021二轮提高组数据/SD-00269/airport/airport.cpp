#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=101010;
int n,m1,m2;
int ans[maxn],ans2;
struct node{
	int goin,goout;
}a[maxn],b[maxn],bri1[maxn],bri2[maxn];
bool cmp(node x,node y){
	return x.goin<y.goin;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%lld%lld",&a[i].goin,&a[i].goout);
	}
	for(int i=1;i<=m2;i++){
		scanf("%lld%lld",&b[i].goin,&b[i].goout);
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	ans2=0;
	for(int l1=0;l1<=n;l1++){
		memset(bri1,0,sizeof(bri1));
		memset(bri2,0,sizeof(bri2));
		int l2=n-l1;
		for(int i=1;i<=m1;i++){
			if(l1!=0){
				for(int j=1;j<=l1;j++){
				if(bri1[j].goout<a[i].goin){
					bri1[j].goout=a[i].goout;
					ans[l1]++;
					i++;
				}
			}
			}	
		}
		for(int i=1;i<=m2;i++){
			if(l2!=0){
				for(int j=1;j<=l2;j++){
				if(bri2[j].goout<b[i].goin){
					bri2[j].goout=b[i].goout;
					ans[l1]++;
					i++;
				}
			}
			}
			
		}
		
	}
	for(int i=0;i<=n;i++){
		ans2=max(ans2,ans[i]);
	}
	printf("%lld",ans2+1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


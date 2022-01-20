#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
struct bc{
	long long l,r;
};
bc a[100098];//°à´Î
bool cmp(bc zz,bc qq){
	return zz.l<qq.l;
}
long long n,mgn,mgj;
long long zhan=-1;
long long fn[100009],fj[100009];//dp
bool zy[100009];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&mgn,&mgj);
	for(int i=1;i<=mgn;i++){
		scanf("%lld%lld",&a[i].l,&a[i].r);
	}
	sort(a+1,a+mgn+1,cmp);
	for(int i=1;i<=n;i++){
		zhan=0;
		for(int j=1;j<=mgn;j++){
			if(!zy[j]&&a[zhan].r<a[j].l){
				fn[i]++;
				zy[j]=1;
				zhan=j;
			}
		}
	}
	
	memset(zy,0,sizeof(zy));
	
	for(int i=1;i<=mgj;i++){
		scanf("%lld%lld",&a[i].l,&a[i].r);
	}
	sort(a+1,a+mgj+1,cmp);
	for(int i=1;i<=n;i++){
		zhan=0;
		for(int j=1;j<=mgj;j++){
			if(!zy[j]&&a[zhan].r<a[j].l){
				fj[i]++;
				zy[j]=1;
				zhan=j;
			}
		}
//		while(!q.empty())q.pop();
	}
	
	long long ans=0;
	for(int i=1;i<=n;i++){
		fn[i]+=fn[i-1];
		fj[i]+=fj[i-1];
	}
	for(int i=0;i<=n;i++){
		ans=max(ans,fn[i]+fj[n-i]);
	}
	cout<<ans;
	return 0;
} 












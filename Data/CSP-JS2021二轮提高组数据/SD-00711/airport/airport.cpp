#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<stack>
using namespace std;
typedef long long ll;
const ll N=1e5+10;
ll n,m1,m2,cnt;
struct plane{
	ll a,b,is;
	plane(){
		a=b=is=0;
	}
}a1[N],a2[N];
struct node{
	ll bh,tp,tm;
	node(){
		bh=tp=tm=0;
	}
}tm1[N<<1],tm2[N<<1];
bool cmp1(node x,node y){
	return x.tm<y.tm;
}
ll l,r,md1,md2,ans;
ll check(ll a){
	ll ans=0,nw=0;
	for(int i=1;i<=m1*2;i++){
		if(tm1[i].tp==1){
			if(nw<a){
				nw++;
				ans++;
				a1[tm1[i].bh].is=1;
			}
		}
		else{
			if(a1[tm1[i].bh].is==1){
				nw--;
				a1[tm1[i].bh].is=0;
			}
		}
	}
	nw=0;
	for(int i=1;i<=m2*2;i++){
		if(tm2[i].tp==1){
			if(nw<n-a){
				nw++;
				ans++;
				a2[tm2[i].bh].is=1;
			}
		}
		else{
			if(a2[tm2[i].bh].is==1){
				nw--;
				a2[tm2[i].bh].is=0;
			}
		}
	}
	return ans;
}
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(ll i=1;i<=m1;i++)	
	{	
		scanf("%lld %lld",&a1[i].a,&a1[i].b);
		tm1[i*2-1].bh=i,tm1[i*2-1].tp=1,tm1[i*2-1].tm=a1[i].a;
		tm1[i*2].bh=i,tm1[i*2].tp=-1,tm1[i*2].tm=a1[i].b;
	}
	sort(tm1+1,tm1+m1*2+1,cmp1);
	for(ll i=1;i<=m2;i++)	
	{
		scanf("%lld %lld",&a2[i].a,&a2[i].b);
		tm2[i*2-1].bh=i,tm2[i*2-1].tp=1,tm2[i*2-1].tm=a2[i].a;
		tm2[i*2].bh=i,tm2[i*2].tp=-1,tm2[i*2].tm=a2[i].b;
	}
	sort(tm2+1,tm2+m2*2+1,cmp1);
	l=0,r=n;
	while(l<r){
		md1=(l+r)>>1;
		md2=md1+1;
		ll ansmd1=check(md1),ansmd2=check(md2);
		if(ansmd1<=ansmd2){
			l=md1;
		}
		else {
			r=md2;
		}
		cnt++;
		ans=max(ansmd1,ansmd2);
		if(cnt==60) break;
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

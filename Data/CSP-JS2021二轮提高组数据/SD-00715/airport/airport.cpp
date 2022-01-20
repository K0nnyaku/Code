#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#define ll long long
#define N 100010
using namespace std;
struct node{
	ll l,r;
}b[N];
ll cmp(node a,node b){return a.l<b.l;}
ll n,m1,m2,m,t[N<<2],a1[N],a2[N],tot1=0,tot2=0,s1[N],s2[N],sum,xx,ans=-1e13;

ll ask(ll x,ll l,ll r,ll L,ll R){
	if(L<=l&&r<=R)return t[x];
	ll mid=(l+r)>>1;
	ll ans=1e13;
	if(mid>=L)ans=min(ans,ask(x<<1,l,mid,L,R));
	if(mid<R)ans=min(ans,ask(x<<1|1,mid+1,r,L,R));
	return ans;
}
void change(ll x,ll l,ll r,ll L,ll k){
	if(l==r){
		t[x]=k;
		return ;
	}
	ll mid=(l+r)>>1;
	if(mid>=L)change(x<<1,l,mid,L,k);
	else change(x<<1|1,mid+1,r,L,k);
	t[x]=min(t[x<<1],t[x<<1|1]);
}
void check(ll x,ll l,ll r,ll L,ll R,ll k){
	if(l==r){
		xx=l;
		return ;
	}
	ll mid=(l+r)>>1;
	if(mid>=R)check(x<<1,l,mid,L,R,k);
	else {
		if(ask(1,1,m,L,mid)<k)
			check(x<<1,l,mid,L,R,k);
		else check(x<<1|1,mid+1,r,L,R,k);
	}
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	m=m1+m2;
	
	for(ll i=1;i<=m1;i++)scanf("%lld%lld",&b[i].l,&b[i].r);
	sort(b+1,b+m1+1,cmp);
	sum=1;
	memset(t,0x3f,sizeof(t));
	change(1,1,m,1,b[1].r);
	a1[1]=1;
	for(ll i=2;i<=m1;i++){
		if(ask(1,1,m,1,sum)>=b[i].l){
			sum++;
			a1[sum]=1;
			change(1,1,m,sum,b[i].r);
		}
		else {
			check(1,1,m,1,sum,b[i].l);
			change(1,1,m,xx,b[i].r);
			a1[xx]++;
		}
	}
	for(ll i=1;i<=n;i++)s1[i]=s1[i-1]+a1[i];
	
	for(ll i=1;i<=m2;i++)scanf("%lld%lld",&b[i].l,&b[i].r);
	sort(b+1,b+m2+1,cmp);
	sum=1;
	memset(t,0x3f,sizeof(t));
	change(1,1,m,1,b[1].r);
	a2[1]=1;
	for(ll i=2;i<=m2;i++){
		if(ask(1,1,m,1,sum)>=b[i].l){
			sum++;
			a2[sum]=1;
			change(1,1,m,sum,b[i].r);
		}
		else {
			check(1,1,m,1,sum,b[i].l);
			change(1,1,m,xx,b[i].r);
			a2[xx]++;
		}
	}
	for(ll i=1;i<=n;i++)s2[i]=s2[i-1]+a2[i];
	
	for(ll i=0;i<=n;i++)ans=max(ans,s1[i]+s2[n-i]);
	cout<<ans<<endl;
	
	return 0;
}

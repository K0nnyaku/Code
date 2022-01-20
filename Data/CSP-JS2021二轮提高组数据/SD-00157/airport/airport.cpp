#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
using namespace std;

const long long N=1e5+1;
long long n,m1,m2,p1,p2,dic[4*N+10],tot,inv[2*N+10],cnt,air1[2*N+10],air2[2*N+10],dela[2*N+10],ans,now;
struct airp{
	long long l,r;
}a1[N+10],a2[N+10];
bool cmp(airp u,airp v){return u.l<v.l;}
map <long long,long long> mp;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	long long i,j,u,v,gx;
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++) cin>>a1[i].l>>a1[i].r,dic[++tot]=a1[i].l,dic[++tot]=a1[i].r;
	for(i=1;i<=m2;i++) cin>>a2[i].l>>a2[i].r,dic[++tot]=a2[i].l,dic[++tot]=a2[i].r;
	sort(dic+1,dic+tot+1);
	for(i=1;i<=tot;i++){
		if(!mp[dic[i]]){
			inv[dic[i]]=++cnt;
			mp[dic[i]]=1;
		}
	}
	for(i=1;i<=m1;i++){
		a1[i].l=inv[a1[i].l];
		a1[i].r=inv[a1[i].r];
	}
	for(i=1;i<=m2;i++){
		a2[i].l=inv[a2[i].l];
		a2[i].r=inv[a2[i].r];
	}
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(i=1;i<=m1;i++) air1[a1[i].l]=i;
	for(i=1;i<=m2;i++) air2[a2[i].l]=i;
	for(gx=0;gx<=n;gx++){
		now=0;
		p1=gx,p2=n-gx;
		u=0;v=0;
		memset(dela,0,sizeof(dela));
		for(i=1;i<=cnt;i++){
			if(dela[i]==1) u--;
			if(dela[i]==2) v--;
			if(air1[i]){
				if(u<p1){
					u++;
					now++;
					dela[a1[air1[i]].r]=1;
				}
			}
			if(air2[i]){
				if(v<p2){
					v++;
					now++;
					dela[a2[air2[i]].r]=2;
				}
			}
		}
		ans=max(ans,now);
	}
	cout<<ans<<endl;
	return 0;
}

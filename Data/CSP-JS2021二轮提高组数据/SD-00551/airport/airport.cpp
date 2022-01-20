#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;
const int N=1e5+5;
ll n,m1,m2;
ll a1[N],b1[N],a2[N],b2[N];
struct r{
	ll a;
	bool operator < (const r &rhs) const {
		return a>rhs.a;
	}
};
priority_queue<r> q;
ll ans=-0x3f3f3f3f;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%lld%lld",&a1[i],&b1[i]);
	}
	for(int i=1;i<=m2;i++){
		scanf("%lld%lld",&a2[i],&b2[i]);
	}
	for(int k=0;k<=n;k++){
		ll brigein1=k-1,atin1=1;
		while(!q.empty()) q.pop();
		if(k!=0){
			q.push((r){b1[1]});
			for(int i=2;i<=m1;i++){
				r u=q.top();
				if(a1[i]>u.a){
					q.pop();
					u=q.top();
					while(u.a<a1[i]&&!q.empty()){
						q.pop();
						u=q.top();
						brigein1++;
					}
					q.push((r){b1[i]});
					atin1++;
				}
				else{
					if(brigein1>0){
						brigein1--;
						atin1++;
						q.push((r){b1[i]});
					}
				}
			}
		}
		else atin1=0;
		ll brigein2=n-k-1,atin2=1;
		if(k!=n){
			while(!q.empty()) q.pop();
			q.push((r){b2[1]});
			for(int i=2;i<=m2;i++){
				r u=q.top();
				if(a2[i]>u.a){
					q.pop();
					u=q.top();
					while(u.a<a2[i]&&!q.empty()){
						q.pop();
						u=q.top();
						brigein2++;
					}
					q.push((r){b2[i]});
					atin2++;
				}
				else{
					if(brigein2>0){
						brigein2--;
						atin2++;
						q.push((r){b2[i]});
					}
				}
			}
		}
		else atin2=0;
//		printf("%lld %lld\n",atin1,atin2);
		ans=max(ans,atin1+atin2);
	}
	printf("%lld\n",ans);
	return 0;
}

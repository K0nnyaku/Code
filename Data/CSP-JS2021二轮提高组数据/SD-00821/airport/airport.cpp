#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,m2,sume[100010],cnt,ans,sr[100010];
struct node{
	int en,sum;
}edge[100010];
struct nod{
	int be,en;
}a[100010],a2[100010];
bool cmp(nod a,nod b){
	return a.be<b.be;
} 
signed main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m,&m2);
	for(int i=1;i<=m;++i){
		scanf("%lld%lld",&a[i].be,&a[i].en);
	}
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m2;++i){
		scanf("%lld%lld",&a2[i].be,&a2[i].en);
	}
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m;++i){
		if(!cnt){
			cnt++;
			edge[1].en=a[i].en;
			edge[1].sum=1;
		}
		else{
			bool flag=false;
			for(int j=1;j<=cnt;++j){
				if(edge[j].en<a[i].be){
					flag=true;
					edge[j].sum++;
					edge[j].en=a[i].en;
					break;
				}
			}
			if(!flag){
				edge[++cnt].en=a[i].en;
				edge[cnt].sum=1;
			}
		}
	}
	int cntt=cnt;
	for(int i=1;i<=m2;++i){
		if(i==1){
			cnt++;
			edge[cnt].en=a2[i].en;
			edge[cnt].sum=1;
		}
		else{
			bool flag=false;
			for(int j=cntt+1;j<=cnt;++j){
				if(edge[j].en<a2[i].be){
					flag=true;
					edge[j].sum++;
					edge[j].en=a2[i].en;
					break;
				}
			}
			if(!flag){
				edge[++cnt].en=a2[i].en;
				edge[cnt].sum=1;
			}
		}
	}
	for(int i=cntt+1;i<=cnt;++i){
		sr[i-cntt]=sr[i-1-cntt]+edge[i].sum;
	} 
	int l=1,r=cntt;
	int sl=0;
	for(int i=0;i<=n&&i<=cntt;++i){
		sl+=edge[i].sum;
		ans=max(sl+sr[n-i],ans);
	}
	printf("%lld",ans);
	return 0;
}

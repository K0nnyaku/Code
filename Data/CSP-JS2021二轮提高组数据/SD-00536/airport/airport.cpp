#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,x,y;//桥 内机 外机 
ll ans,cnt1,cnt2,sum,nei,wai,c[1000010];
struct Node{
	ll a,b;//抵达 离开 
}e[1000010],g[1000010];//内 外 
bool cmp(Node x,Node y){
	return x.a<y.a;
}
ll Dfs(ll s){
	nei=n-s;
	wai=s;
	sum=0;
	if(s<0){
		return ans; 
	}
	for(ll i=1;i<=x;i++){
		if(nei>0){
			nei--;
			sum++;
			c[++cnt1]=e[i].b;
			continue;
		}
		if(nei<=0){
			if(c[++cnt2]<=e[i].a&&cnt2<=cnt1){
				sum++;
				c[++cnt1]=e[i].b;
				continue;
			}
			cnt2--;
		}
	}
	//cout<<"nei"<<sum<<" ";
	memset(c,0,sizeof(c));
	cnt1=0;
	cnt2=0;
	for(ll i=1;i<=y;i++){
		if(wai>0){
			wai--;
			sum++;
			c[++cnt1]=g[i].b;
			continue;
		}
		if(wai<=0){
			if(c[++cnt2]<=g[i].a&&cnt2<=cnt1){
				sum++;
				c[++cnt1]=g[i].b;
				continue;
			}
			cnt2--;
		}
		//cout<<"i"<<1<<""<<"sum"<<sum<<" ";
		
	}
	//cout<<"wai"<<sum-qwq<<" ";
	memset(c,0,sizeof(c));
	cnt1=0;
	cnt2=0;
	//cout<<"zong"<<sum<<endl;
	ans=max(ans,sum);
	Dfs(--s);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&x,&y);
	for(int i=1;i<=x;i++){
		scanf("%lld%lld",&e[i].a,&e[i].b);
	}
	for(int i=1;i<=y;i++){
		scanf("%lld%lld",&g[i].a,&g[i].b);
	}
	sort(e+1,e+1+x,cmp);
	sort(g+1,g+1+y,cmp);
	Dfs(n);
	printf("%lld",ans);
	return 0;
}

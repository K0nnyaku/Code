#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
#define ll long long
using namespace std;
struct PLANE{
	ll head,end;
}p[100010];
map<ll ,ll >tong;
priority_queue<ll >que;
ll n,m1,m2;
ll cnt,x[200010],qzh[200010];
ll add[3][100010];
ll X,cun;
ll ans,las;
int cmp(PLANE ,PLANE );
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(ll i=1;i<=m1;i++){
		scanf("%lld %lld",&p[i].head,&p[i].end);
		x[i*2-1]=p[i].head;
		x[i*2]=p[i].end;
	}
	sort(x+1,x+1+m1+m1);
	sort(p+1,p+1+m1,cmp);
	cnt=0;
	las=0;
	tong.clear();
	for(ll i=1;i<=m1*2;i++){
		if(x[i]!=las){
			cnt++;
			x[cnt]=x[i];
			tong[x[cnt]]=cnt;
			las=x[cnt];
		}
	}
	cnt=0;
	for(ll i=1;i<=n;i++){
		while(!que.empty()){
			que.pop();
		}
		cun=0;
		cnt=0;
		for(ll j=1;j<=m1;j++){
			while(!que.empty()&&(-que.top())<p[j].head){
				que.pop();
				cnt--;
			}
			if(cnt<i){
				que.push(-p[j].end);
				cun++;cnt++;
			}
		}
		add[1][i]=cun;
	}
	for(ll i=1;i<=m2;i++){
		scanf("%lld %lld",&p[i].head,&p[i].end);
		x[i*2-1]=p[i].head;
		x[i*2]=p[i].end;
	}
	sort(x+1,x+1+m2+m2);
	sort(p+1,p+1+m2,cmp);
	cnt=0;
	las=0;
	tong.clear();
	for(ll i=1;i<=m2*2;i++){
		if(x[i]!=las){
			cnt++;
			x[cnt]=x[i];
			tong[x[cnt]]=cnt;
			las=x[cnt];
		}
	}
	cnt=0;
	for(ll i=1;i<=n;i++){
		while(!que.empty()){
			que.pop();
		}
		cun=0;
		cnt=0;
		for(ll j=1;j<=m2;j++){
			while(!que.empty()&&(-que.top())<p[j].head){
				que.pop();
				cnt--;
			}
			if(cnt<i){
				que.push(-p[j].end);
				cun++;cnt++;
			}
		}
		add[2][i]=cun;
	}	
	for(ll i=0;i<=n;i++){
		ans=max(add[1][i]+add[2][n-i],ans);
	}
	printf("%lld\n",ans);
	return 0;
}
int cmp(PLANE A,PLANE B){
	return A.head<B.head;
}

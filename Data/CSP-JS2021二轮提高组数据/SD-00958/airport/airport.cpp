#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
const int maxn = 100100;
ll n,m1,m2;
struct node{
	ll l;
	ll r;
};
node a[maxn],b[maxn];

bool cmp(node x,node y){
	return x.l < y.l; 
}
long long ans = -1e12;
priority_queue <long long> nowa;
priority_queue <long long> nowb;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%lld%lld",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%lld%lld",&b[i].l,&b[i].r); 
	
	sort(a+1,a+m1+1,cmp);sort(b+1,b+m2+1,cmp);
	
	for(long long i=0;i<=n;i++){
		ll gw = n-i;
		ll ans1=0,ans2=0;
		ll t1 = 1,t2 = 1;
		while(!nowa.empty()) nowa.pop();
		while(!nowb.empty()) nowb.pop();
		nowa.push(0);nowb.push(0);	
		for(int j=1;j<=m1;j++){
			long long nowj = nowa.top() * (-1);
			if(nowj <= a[j].l && t1!=0){
				t1--;
				nowa.pop();
			}
			if(t1 < i){
				
				//cout<<nowj<<endl;
				nowa.push(a[j].r*(-1));
				t1++;
				ans1++;
			}
		}
		
		for(int j=1;j<=m2;j++){
			long long nowj = nowb.top() * (-1);
			if(nowj <= b[j].l && t2 !=0){
				t2--;
				nowb.pop();
			}
			if(t2 < n-i){
				nowb.push(b[j].r * (-1));
				t2++;
				ans2++;
			}
			
		}
		//cout<<ans1<<" "<<ans2<<endl;
		ans = max(ans,ans1+ans2);
	}
	
	printf("%lld",ans);
	return 0;
} 

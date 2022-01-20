#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e4 + 10;
ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){ if(ch=='-') f=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9'){ x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
} 
void print(ll x){
	if(x==1) putchar('L');
	else if(x==2) putchar('R');
}
deque < ll > q,x,y,p;
ll T,n,num,k[maxn];
ll check(ll n){
	ll u,v,re=1;
	x.clear(),y.clear();
	for(int i=1;n/2>=i;i++){
		u=q.front(),v=q.back();
		q.pop_front();q.pop_back();
		x.push_front(u);
		y.push_back(v);
		if(u!=v){ re=0; break; }
	}
	while(!x.empty()){
		u=x.front(),v=y.back();
		x.pop_front(),y.pop_back();
		q.push_front(u),q.push_back(v);
	}
	return re;
} 
ll dfs(ll i,ll co,ll n){
	ll h;
	if(co==1){
		ll o=p.front();
		q.push_front(o);
		p.pop_front();
		h=o;
	}
	else if(co==2){
		ll o=p.back();
		q.push_back(o);
		p.pop_back();
		h=o;
	}
	if(i==n){
		if(check(n)) {
			print(co);
			return 1;
		}
	}
	if(i!=n&&dfs(i+1,1,n)){
		print(co);
		return 1;
	}
	if(i!=n&&dfs(i+1,2,n)){
		print(co);
		return 1;
	}
	if(co==1) p.push_front(h),q.pop_front();
	else if(co==2) p.push_back(h),q.pop_back();
	return 0;
}
signed main(){
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
	//³·×¢ÊÍ
	T=read();
	while(T--){
		q.clear(),p.clear();
		n=read();
		for(int i=1;2*n>=i;i++){
			num=read();
			p.push_back(num);
		}
		if(dfs(1,1,2*n)) continue;
		else if(dfs(1,2,2*n)) continue;
		cout<<"-1"<<endl;;
	}
	return 0;
}


#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<cmath>
#include<set>
#include<map>
#include<bitset>
#include<vector>
#define mp make_pair
#define pb push_back
#define vi vector<int>
typedef long long ll;
using namespace std;
//#define int long long
int read(){
	char c=getchar();int s=0,x=1;
	while(c<'0' || c>'9'){
		if(c=='-')x=-1;c=getchar();
	}
	while(c>='0' && c<='9'){
		s=s*10+c-'0';c=getchar();
	}
	return s*x;
}
const int N=3e5+5;
int n,xx,yy,x,y,f[N],g[N];
struct node{
	int l,r;
	friend bool operator < (node x,node y){
		if(x.l!=y.l)return x.l<y.l;
		else return x.r<y.r;
	}
};
set<node>sa,sb;
int main(){
	#ifdef newbiewzs
	#endif
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();xx=read();yy=read();
	for(int i=1;i<=xx;i++){
		x=read();y=read();
		node tmp={x,y};
		sa.insert(tmp);
	}
	for(int i=1;i<=yy;i++){
		x=read();y=read();
		node tmp={x,y};
		sb.insert(tmp);
	}
	for(int i=1;i<=xx;i++){
		if(!sa.size())break;
		auto u=sa.begin();
		node w=*u;
		f[i]++;
		
		while(1){
			auto v=sa.lower_bound((node){w.r,0});
			sa.erase(w);
			if(v==sa.end())break;
			w=*v;
			f[i]++;
		}
	}
	for(int i=1;i<=xx;i++){
		if(!sb.size())break;
		auto u=sb.begin();
		g[i]++;
		while(1){
			auto v=sb.lower_bound((node){(*u).r,0});
			sb.erase(u);
			if(v==sb.end())break;
			u=v;
			g[i]++;
		}
	}
	for(int i=1;i<=xx;i++)f[i]=f[i-1]+f[i];
	for(int i=1;i<=yy;i++)g[i]=g[i-1]+g[i];
	int maxx=0;
	for(int i=0;i<=n;i++){
		maxx=max(maxx,f[i]+g[n-i]);
	}
	cout<<maxx;
	return 0;
}


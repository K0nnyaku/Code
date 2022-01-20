#include<bits/stdc++.h>
#define int long long
#define N 100005
#define f first
#define s second
using namespace std;
int n,m,mm,ans;
pair<int,int> a[N],b[N];
vector<pair<int,pair<int,bool> > > v;//离散化数组
map<int,pair<int,bool> > mp;
bool vis[N<<1];
inline int read(){
	int f=1,q=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=0;ch=getchar();}
	while(isdigit(ch))q=(q<<3)+(q<<1)+(ch^48),ch=getchar(); 
	return f?q:-q;
}
inline void print(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)print(x/10);
	putchar(x%10+48);
}
inline bool cmp(pair<int,pair<int,bool> > aa,pair<int,pair<int,bool> > bb){
	return aa.f<bb.f;
}
signed main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n=read(),m=read(),mm=read();
	for(register int i=1;i<=m;++i)a[i].f=read(),a[i].s=read(),v.push_back(make_pair(a[i].f,make_pair(i,0))),v.push_back(make_pair(a[i].s,make_pair(i,1)));
	for(register int i=1;i<=mm;++i)b[i].f=read(),b[i].s=read(),v.push_back(make_pair(b[i].f,make_pair(i+m,0))),v.push_back(make_pair(b[i].s,make_pair(i+m,1)));
	sort(v.begin(),v.end(),cmp);
	int xx=((m+mm)<<1);
//	for(register int i=0;i<xxx;++i){
//		cout<<v[i].f<<" "<<v[i].s.f<<" "<<v[i].s.s<<endl;
//	}
	for(register int i=0;i<xx;++i){//离散化 
		if(v[i].s.f>m){//国际 
			if(v[i].s.s)b[v[i].s.f-m].s=i+1;
			else b[v[i].s.f-m].f=i+1;
		}
		else{//国内 
			if(v[i].s.s)a[v[i].s.f].s=i+1;
			else a[v[i].s.f].f=i+1;
		}
	}
	sort(a+1,a+m+1);sort(b+1,b+mm+1);
	for(register int i=1;i<=m;++i)mp[a[i].f]=make_pair(i,0),mp[a[i].s]=make_pair(i,1);
	for(register int i=1;i<=mm;++i)mp[b[i].f]=make_pair(i+m,0),mp[b[i].s]=make_pair(i+m,1);
	for(register int i=0;i<=n;++i){//廊桥枚举O(nm)暴力，i为国内廊桥数
		int ii=n-i;//ii为国际廊桥数
		int ix=0,iix=0;//ix now domestic, iix now international
		int maxn=0;
		for(register int j=1;j<=xx;++j){
			pair<int,bool> mx=mp[j];
			if(mx.f>m){//国际
				if(mx.s){//end
					if(vis[mx.f]){
						--iix;
						vis[mx.f]=false;
					}
				}
				else{//start
					if(iix<ii){
						++iix,++maxn;
						vis[mx.f]=true;
					}
				}
			}
			else{//国内
				if(mx.s){//end
					if(vis[mx.f]){
						--ix;
						vis[mx.f]=false;
					}
				}
				else{//start
					if(ix<i){
						++ix,++maxn;
						vis[mx.f]=true;
					}
				}
			}
		}
		ans=max(ans,maxn);
//		cout<<endl;
//		cout<<i<<" "<<maxn<<endl;
	}
	print(ans);
	return 0;
}
/*
3 3
1 5
3 8
13 18
2 11
7 17
12 16

*/

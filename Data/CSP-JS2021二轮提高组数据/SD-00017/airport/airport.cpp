#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;

/***** Fast_IO *****/

namespace IO{
	char buf[(1<<21)]; int _=0;
	
	#define gc getchar
	#define pc putchar
	
	template<class I>
	inline I read(I &x){
		x=0; I f=1; char c=gc(); if(c==EOF){ return -1; }
		while(c<'0'||c>'9'){ if(c=='-'){ f=f*(-1); } c=gc(); }
		while(c>='0'&&c<='9'){ x=(x<<1)+(x<<3)+(c^48); c=gc(); }
		return x=x*f;
	}
	
	template<class I>
	inline void write(I x){
		if(x==0){ pc('0'); return; }
		int tmp=(x>0?x:(-x)),cnt=0;
		if(x<0){ pc('-'); }
		while(tmp){ buf[cnt++]=(tmp%10+'0'); tmp/=10; }
		while(cnt){ pc(buf[--cnt]); }
		return;
	}
	
	#define out(x) write(x),pc(' ')
	#define outn(x) write(x),pc('\n')
	#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
	#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
	#define FORs(i,a,b,s) for(int i=(a);i<=(b);i+=(s))
	#define ROFs(i,a,b,s) for(int i=(a);i>=(b);i-=(s))
	#define pb push_back
}using namespace IO;

/***** Fast_IO *****/

#define maxn 1000010
#define SIZE 5010

int n,m_1,m_2;

struct Bridge{
	int u,v;
	int cnt;
	
	bool operator <(Bridge p) const { return u<p.u; }
}bri[maxn],bri2[maxn];

int lim;

class BIT{
	#define lowbit(k) ((k)&(-k))
	
	private:
		int tree[maxn];
		
	public:
		
		void add(int x,int k){
			for(;x<=lim;x+=lowbit(x)){ tree[x]+=k; }
			return;
		}
		
		int query(int x){
			int res=0;
			for(;x>0;x-=lowbit(x)){ res+=tree[x]; }
			return res;
		}
}ta,ta2;

vector<int> vis1,vis2;

bool Use[maxn],Use2[maxn];
int ans[maxn],ans2[maxn];

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(m_1),read(m_2);
	FOR(i,1,m_1){ read(bri[i].u),read(bri[i].v); lim=::max(lim,bri[i].v); }
	FOR(i,1,m_2){ read(bri2[i].u),read(bri2[i].v); lim=::max(lim,bri2[i].v); }
	sort(bri+1,bri+m_1+1);
	sort(bri2+1,bri2+m_2+1);
	if(n>5000){
		int res=0,pos_1=1,cnt=0;
		FOR(tmp,1,n){
			int now=1;
			while(Use[now]&&now<=m_1){ ++now; }
			if(now>m_1){ ans[tmp]=res; continue; }
			Use[now]=1; ++res;
			while(1){
				int l=now,r=m_1;
				int k=-1;
	//			printf("--->"); out(now);puts("");
				while(l<=r){
					int mid=(l+r)>>1;
	//				outn(mid);
					if(bri[mid].u>bri[now].v){
						k=mid;
						r=mid-1;
					} else{ l=mid+1; }
				}
	//			out(tmp),outn(k);
				if(k==-1){ ans[tmp]=res; break; }
				while(Use[k]&&k<=m_1){ ++k; }
				if(k>m_1){ ans[tmp]=res; break; }
				now=k; ++res; Use[now]=1;
			}
		}
		res=0,pos_1=1,cnt=0;
		FOR(tmp,1,n){
			int now=1;
			while(Use2[now]&&now<=m_2){ ++now; }
			if(now>m_2){ ans2[tmp]=res; continue; }
			Use2[now]=1; ++res;
			while(1){
				int l=now,r=m_2;
				int k=-1;
	//			printf("--->"); out(now);puts("");
				while(l<=r){
					int mid=(l+r)>>1;
	//				outn(mid);
					if(bri2[mid].u>bri2[now].v){
						k=mid;
						r=mid-1;
					} else{ l=mid+1; }
				}
	//			out(tmp),outn(k);
				if(k==-1){ ans2[tmp]=res; break; }
				while(Use2[k]&&k<=m_2){ ++k; }
				if(k>m_2){ ans2[tmp]=res; break; }
				now=k; ++res; Use2[now]=1;
			}
		}
		int answ=0;
		FOR(i,0,n){
			answ=::max(answ,ans[i]+ans2[n-i]);
		}
		outn(answ);
	} else{
		int answ=0;
		FOR(i,0,n){
			int tmp=i,tmp2=n-i;
			int res=0,Cnt=0;
			FOR(j,1,m_1){
				bri[j].cnt=(j-Cnt-1)-ta.query(bri[j].u);
				if(bri[j].cnt<tmp){ ta.add(bri[j].v,1); vis1.pb(j); }
				else{ ++Cnt; }
			}
			Cnt=0;
			FOR(j,1,m_2){
				bri2[j].cnt=(j-Cnt-1)-ta2.query(bri2[j].u);
				if(bri2[j].cnt<tmp2){ ta2.add(bri2[j].v,1); vis2.pb(j); }
				else{ ++Cnt; }
			}
			answ=max(answ,(int)vis1.size()+(int)vis2.size());
			FOR(j,0,(int)vis1.size()-1){ ta.add(bri[vis1[j]].v,-1); }
			FOR(j,0,(int)vis2.size()-1){ ta2.add(bri2[vis2[j]].v,-1); }
			vis1.clear(),vis2.clear();
		}
		outn(answ);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/

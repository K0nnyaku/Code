#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

#define int long long

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

int T,n;
int a[maxn];

int DIGIT(int S,int k){
	return (1<<(k-1))&S;
}

vector<int> b,c;

signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(T);
	while(T--){
		read(n);
		FOR(i,1,(n<<1)){ read(a[i]); }
		int ans=-1;
		FOR(S,0,(1ll<<(n<<1))-1){
			// outn(S);
			b.clear();
			c.clear();
			int pos_1=1,pos_2=(n<<1);
			ROF(i,(n<<1),1){
				if(DIGIT(S,i)==0){
					b.pb(a[pos_1]);
					++pos_1;
				} else{
					b.pb(a[pos_2]);
					--pos_2;
				}
			}
			c=b;
			// reverse(b.begin(),b.end());
			FOR(i,1,n){ ::swap(b[i-1],b[(n<<1)-i]); }
			if(b==c){ ans=S; break; }
		}
		if(ans==-1){ puts("-1"); }
		else{
			ROF(i,(n<<1),1){
				if(DIGIT(ans,i)==0){
					cout<<"L";
				} else{ cout<<"R"; }
			}
			puts("");
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/

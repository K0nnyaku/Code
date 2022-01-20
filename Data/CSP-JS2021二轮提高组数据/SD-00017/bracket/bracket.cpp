#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
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
}using namespace IO;

/***** Fast_IO *****/

#define maxn 1000010
#define SIZE 5010

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	read(n);
	outn(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

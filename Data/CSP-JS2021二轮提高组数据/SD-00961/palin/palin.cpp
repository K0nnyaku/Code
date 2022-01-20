#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

template<typename T = int>
inline T read(){
	T x=0,w=1;
	char ch=getchar();
	
	while(!isdigit(ch)){
		if(ch=='-') w=-1;
		ch=getchar();
	}
	
	while(isdigit(ch)){
		x=x*10+ch-'0';
		ch=getchar();
	}	
	
	return x*w;
}
template<typename T = int>
inline void write(T x){
	static int sta[56],tp=0;
	if(x<0){
		putchar('-');
		x=-x;
	}else if(x==0){
		putchar('0');
		return;
	}
	while(x){
		sta[++tp]=x%10,x/=10;
	}
	while(tp){
		putchar(sta[tp--]+'0');
	}
	return;
}

const int N=5e5+5;
int t;
int n,a[N*2],l,r;
bool vis[N*2], op[N*2];
bool flag = 1;
//void search(bool t, int dep){
//	if(flag==1) return;
//	if(dep==n*2){
//		if(check()){
//			flag = 1;
//		}
//		
//		return;
//	}
//
//	return;
//}

inline void work(){
	n=read();
	for(register int i=1;i<=n;i++) a[i]=read();
//	memset(vis,0,sizeof(vis));
//	
//	vis[1]=1;
//	op[1]=0;
//	l=2;
//	search(0,1);
//	l=1;
//	vis[1]=0;
//	vis[2*n]=1;
//	op[1]=1;
//	r=2*n-1;
//	search(1,1);
//	r=2*n;
//	vis[2*n]=0;
	
	printf('-1\n');
	
	return;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	t=read();
	while(t--) work();
	
	return 0;
}

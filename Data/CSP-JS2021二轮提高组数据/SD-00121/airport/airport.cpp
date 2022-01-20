#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct A{
	int tim,typ,id;
	bool operator<(const A&tmp)const{
		return tim<tmp.tim;
	}
}a[100010];
struct B{
	int tim,typ,id;
	bool operator<(const B&tmp)const{
		return tim<tmp.tim;
	}
}b[100010];
int n,m1,m2,l,r,x,y,ans;
bool vis[100010];
inline int calc(int nw){
	int c1=nw,c2=n-nw, n1=0,n2=0,ret=0;
	for(int i=0;i<(m1<<1);++i){
		if(a[i].typ==1||vis[a[i].id]){
			n1+=a[i].typ;
			vis[a[i].id]=0;
		}
		if(n1>c1){
			n1=c1;
			continue;
		}
		if(a[i].typ==1){
			++ret;
			vis[a[i].id]=1;
		}
	}
	for(int i=0;i<(m2<<1);++i){
		if(b[i].typ==1||vis[b[i].id]){
			n2+=b[i].typ;
			vis[b[i].id]=0;
		}
		if(n2>c2){
			n2=c2;
			continue;
		}
		if(b[i].typ==1){
			++ret;
			vis[b[i].id]=1;
		}
	}
	return ret;
}
signed main(){
	freopen("airport.in","r",stdin); 
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		a[i<<1].tim=x;
		a[i<<1].typ=1;
		a[i<<1].id=i;
		a[i<<1|1].tim=y;
		a[i<<1|1].typ=-1;
		a[i<<1|1].id=i;
	}
	sort(a,a+(m1<<1));
	for(int i=0;i<m2;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		b[i<<1].tim=x;
		b[i<<1].typ=1;
		b[i<<1].id=i;
		b[i<<1|1].tim=y;
		b[i<<1|1].typ=-1;
		b[i<<1|1].id=i;
	}
	sort(b,b+(m2<<1));
	ans=l=0;
	r=n;
	while(l<r){
		int dlt=(r-l)/3;
		x=l+dlt;
		y=r-dlt;
		if(calc(x)>calc(y)){
			ans=x;
			r=y-1;
		}
		else{
			ans=y;
			l=x+1;
		}
	}
	printf("%d",calc(ans));
	return 0;
} 

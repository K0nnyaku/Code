#include<cstdio>
#include<algorithm>
using namespace std;
#define C getchar()
typedef long long ll;
ll read(){
	ll f=1,x=0;
	char ch=C;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=C;}
	while(ch>='0'&&ch<='9') x=(x<<3)+(x<<1)+ch-'0',ch=C;
	return x*=f;
}
const int N=100005;
struct plane{
	ll a,b;
	bool operator <(const plane &x)const{
		return a<x.a;
	}
	bool operator >(const plane &x)const{
		return a>x.a;
	}
}x[N],y[N];
ll n,m1,m2;
ll ans,fa[N],f1[N],f2[N];
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;++i)
		x[i].a=read(),x[i].b=read(),fa[i]=i;
	fa[m1+1]=m1+1;
	x[m1+1].a=100000010;
	sort(x+1,x+1+m1);
	for(int i=1,front=0,to;i<=n;++i){
		front=find(front+1);
		if(front>m1) break;
		f1[i]=1;
		for(int j=front,tmp;1;){
			tmp=x[j].b;
			j=find(upper_bound(x+1,x+1+m1,plane{tmp,0})-x);
			if(j>m1) break;
			fa[j]=find(j+1);
			++f1[i];
		}
	}
	for(int i=1;i<=n;++i)
		f1[i]+=f1[i-1];

	for(int i=1;i<=m2;++i)
		y[i].a=read(),y[i].b=read(),fa[i]=i;
	fa[m2+1]=m2+1;
	y[m2+1].a=100000010;
	sort(y+1,y+1+m2);
	for(int i=1,front=0,to;i<=n;++i){
		front=find(front+1);
		if(front>m2) break;
		f2[i]=1;
		for(int j=front,tmp;1;){
			tmp=y[j].b;
			j=find(upper_bound(y+1,y+1+m2,plane{tmp,0})-y);
			j=find(j);
			if(j>m2) break;
			fa[j]=find(j+1);
			++f2[i];
		}
	}
	for(int i=1;i<=n;++i)
		f2[i]+=f2[i-1];
	for(int i=0;i<=n;++i){
		ans=max(f1[i]+f2[n-i],ans);
	}
	printf("%lld\n",ans);
	return 0;
}

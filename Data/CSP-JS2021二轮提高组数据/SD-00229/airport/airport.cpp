#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
const int MAXN=100010;
int n,m1,m2,ans,sum;
int gn,gw;
int ret1,ret2;
struct tim{
	int s,t;
};
tim a[MAXN],b[MAXN];
inline int read(){
	char c=' ';int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<1)+(x<<3)+c-'0';c=getchar();}
	return x*f;
}
bool cmp(tim x,tim y){
	if(x.s<y.s) return 1;
	return 0;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i){
		a[i].s=read(),a[i].t=read();
	}
	for(int i=1;i<=m2;++i){
		b[i].s=read(),b[i].t=read();
	}
	std::sort(a+1,a+m1+1,cmp);
	std::sort(b+1,b+m2+1,cmp);
	for(int i=0;i<=n;++i){
		std::priority_queue<int,std::vector<int>,std::greater<int> >h1;
		std::priority_queue<int,std::vector<int>,std::greater<int> >h2;
		sum=0;
		gn=ret1=i,gw=ret2=n-i;
		if(gn){
			h1.push(a[1].t);
			sum++;
			ret1--;
			for(int j=2;j<=m1;++j){
				int t2=h1.top();
				if((a[j].s>t2)){
					h1.pop();
					++ret1;
				}
				if(ret1>gn) ret1=gn;
				if(ret1){
					h1.push(a[j].t);
					sum++;
					ret1--;
				}
			}
		}
		if(gw){
			h2.push(b[1].t);
			sum++;
			ret2--;
			for(int j=2;j<=m2;++j){
				int t2=h2.top();
				if((b[j].s>t2)){
					h2.pop();
					++ret2;
				}
				if(ret2>gw) ret2=gw;
				if(ret2){
					h2.push(b[j].t);
					sum++;
					ret2--;
				}
			}
		}
		ans=std::max(ans,sum);
	}
	std::cout<<ans<<"\n";
	return 0;
}

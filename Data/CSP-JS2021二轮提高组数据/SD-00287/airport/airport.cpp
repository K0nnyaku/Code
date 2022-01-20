#include<cstdio>
#include<cmath>
#include<algorithm>
#include<set>
#include<cstring>
#define EN putchar('\n')
#define INT_INF (int)(0x3f3f3f3f)
#define LL_INF (long long)(0x3f3f3f3f3f3f3f3f)
inline int read(){
	register int x=0;register int y=1;
	register int c=getchar();
	while(c<'0'||c>'9') y&=(c!='-'),c=getchar();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=getchar();
	return y?x:-x;
}
#define N 100006
struct Plain{
	int l,r;
	inline int operator < (const Plain &o)const{return l<o.l;}
};
std::set<Plain>set;
inline void work(int n,int *ans){
	for(int i=1;i<=n;i++){
		ans[i]=ans[i-1];
		auto it=set.upper_bound({0,0});
		while(it!=set.end()){
			int r=(*it).r;set.erase(it);
			ans[i]++;
			it=set.upper_bound({r,0});
		}
	}
}
int num1[N],num2[N];
int main(){
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout);
	int n=read(),m1=read(),m2=read();
	for(int l,i=1;i<=m1;i++) l=read(),set.insert({l,read()});
	work(n,num1);
	set.clear();
	for(int l,i=1;i<=m2;i++) l=read(),set.insert({l,read()});
	work(n,num2);
	int ans=0;
	for(int i=0;i<=n;i++) ans=std::max(ans,num1[i]+num2[n-i]);
	printf("%d\n",ans);
	return 0;
}

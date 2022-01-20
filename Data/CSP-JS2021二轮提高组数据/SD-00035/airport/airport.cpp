#include <cstdio>
#include <algorithm>
#include <iostream>
#include <queue>
#define ll int
using namespace std;
struct plane{
	ll ariv,leaf,tot;
	bool friend operator <(plane in1,plane in2){
		return in1.ariv<in2.ariv;
	}
}l[2][109376];
inline ll read(){
	char c=getchar();ll flag=1,rt=0;
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')flag=-1,c=getchar();
	while(c>='0'&&c<='9'){rt*=10;rt+=(ll)(c-48);c=getchar();}
	return rt*flag;
}
priority_queue<plane> q;
ll n,m1,m2,ans1[109376],ans2[109376],ans,now1,now2,wat[109376];
bool cmp(plane is1,plane is2){
	return is1.ariv<is2.ariv;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=0;i<m1;i++){
		int a=read(),b=read();
		l[1][i]=plane{a,b,0};
	}
	sort(l[1],l[1]+m1);
	ll nct=m1,nrd=1;
	while(nct){
		for(int i=nrd-1;i<m1;i++){
//			printf(" %d %d %d\n",l[1][i].ariv,l[1][i].leaf,l[1][i].tot);
			if(l[1][i].tot)continue;
			ans1[nrd]++,l[1][i].tot=1,i=upper_bound(l[1],l[1]+m1,plane{l[1][i].leaf,0,0})-l[1]-1;
		}
//		printf("%lld %lld\n",cnt,nrd&1);
		nct-=ans1[nrd];
		nrd++;
	}
	for(int i=0;i<m2;i++){
		int a=read(),b=read();
		l[1][i]=plane{a,b,0};
	}
	sort(l[1],l[1]+m2);
	nct=m2,nrd=1;
	while(nct){
		for(int i=nrd-1;i<m2;i++){
//			printf(" %d %d %d\n",l[1][i].ariv,l[1][i].leaf,l[1][i].tot);
			if(l[1][i].tot)continue;
			ans2[nrd]++,l[1][i].tot=1,i=upper_bound(l[1],l[1]+m2,plane{l[1][i].leaf,0,0})-l[1]-1;
		}
//		printf("%lld %lld\n",cnt,nrd&1);
		nct-=ans2[nrd];
		nrd++;
	}
	for(int i=1;i<=n;i++)ans1[i]+=ans1[i-1],ans2[i]+=ans2[i-1];
//	for(int i=0;i<=n;i++)printf("%d %d\n",ans1[i],ans2[i]);
	for(int i=0;i<=n;i++)ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


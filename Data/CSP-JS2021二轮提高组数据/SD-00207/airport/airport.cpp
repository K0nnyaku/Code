#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define Max(a,b) a>b?a:b
inline int read()
{
	int x=0,y=1,c=getchar();
	while(c<'0'||c>'9')if(c=='-'){y=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*y;
}
int n,M1,M2,tot1,tot2,t1,ans,Ans[100005],Ans2[100005];
int Ed2[100005],Ed[100005],g1,g2,He,Ta,mId;
struct jy{
	int Head,Tail;
}q1[100005],q2[100005];
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();M1=read();M2=read();
	for(int i=1;i<=M1;i++) {
		g1=read();
		g2=read();
		He=1,Ta=i;
		while(He!=Ta) {
			mId=(He+Ta)>>1;
			if(q1[mId].Head>=g1) Ta=mId;
			else He=mId+1;
		}
		for(int j=i;j>=He+1;j--) {
			q1[j].Head=q1[j-1].Head;
			q1[j].Tail=q1[j-1].Tail;
		}
		q1[He].Head=g1;
		q1[He].Tail=g2;
	}
	for(int i=1;i<=M2;i++) {
		g1=read();
		g2=read();
		He=1,Ta=i;
		while(He!=Ta) {
			mId=(He+Ta)>>1;
			if(q2[mId].Head>=g1) Ta=mId;
			else He=mId+1;
		}
		for(int j=i;j>=He+1;j--) {
			q2[j].Head=q2[j-1].Head;
			q2[j].Tail=q2[j-1].Tail;
		}
		q2[He].Head=g1;
		q2[He].Tail=g2;
	}
	for(int i=1;i<=M1;i++) {
		t1=0;
		while(q1[i].Head<Ed[++t1]);
		++Ans[t1];
		Ed[t1]=q1[i].Tail;
	}
	for(int i=1;i<=M2;i++) {
		t1=0;
		while(q2[i].Head<Ed2[++t1]);
		++Ans2[t1];
		Ed2[t1]=q2[i].Tail;
	}
	for(int i=1;i<=n;i++) {
		Ans[i]+=Ans[i-1];
		Ans2[i]+=Ans2[i-1];
	}
	for(int i=1;i<=n;i++) {
		ans=Max(ans,Ans[i]+Ans2[n-i]);
	}
	printf("%d",ans);
}

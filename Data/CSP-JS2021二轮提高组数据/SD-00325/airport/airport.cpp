#include<bits/stdc++.h>
using namespace std;
const int N=200010;
int n,m1,m2,vis[N],vis2[N];
struct d{
	int a,b,fro;
	bool operator < (const d x) const{return a<x.a;}
}qwq[N],qwq2[N];
int ans1[N],ans2[N],anss;
struct xd{
	int a,fro;
	bool operator < (const xd x) const{return a<x.a;}
}qqq;
set<xd> kel1,kel2;
int main(){
//	freopen("data.txt","r",stdin);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&qwq[i].a,&qwq[i].b);
		qwq[i].fro=i;
	}
	sort(qwq+1,qwq+m1+1);
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&qwq2[i].a,&qwq2[i].b);
		qwq2[i].fro=i;
	}
	sort(qwq2+1,qwq2+m2+1);
	
	for(int i=1;i<=m1;i++){
		qqq.a=qwq[i].a;qqq.fro=i;
		kel1.insert(qqq);
	}
	
	for(int i=1;i<=m2;i++){
		qqq.a=qwq2[i].a;qqq.fro=i;
		kel2.insert(qqq);
	}
	
	int now=1;
	for(int i=1;i<=n;i++){
		while(now<=m1&&vis[now])now++;
		int noww=now;
		while(noww<=m1&&noww!=-1){
			ans1[i]++;
			vis[noww]=1;
			qqq.a=qwq[noww].a;qqq.fro=noww;
			kel1.erase(qqq);
			qqq.a=qwq[noww].b;qqq.fro=0;
			set<xd>::iterator itt=kel1.lower_bound(qqq);
			if(itt==kel1.end())noww=-1;
			else noww=(*itt).fro;
		}
	}
	for(int i=1;i<=n;i++)ans1[i]+=ans1[i-1];
	
	
	
	int now2=1;
	for(int i=1;i<=n;i++){
		while(now2<=m2&&vis2[now2])now2++;
		int noww2=now2;
		while(noww2<=m2&&noww2!=-1){
			ans2[i]++;
			vis2[noww2]=1;
			qqq.a=qwq2[noww2].a;qqq.fro=noww2;
			kel2.erase(qqq);
			qqq.a=qwq2[noww2].b;qqq.fro=0;
			set<xd>::iterator itt=kel2.lower_bound(qqq);
			if(itt==kel2.end())noww2=-1;
			else noww2=(*itt).fro;
		}
	}
	for(int i=1;i<=n;i++)ans2[i]+=ans2[i-1];
	for(int i=0;i<=n;i++){
		anss=max(anss,ans1[i]+ans2[n-i]);
	}
	printf("%d\n",anss);
	
	return 0;
}

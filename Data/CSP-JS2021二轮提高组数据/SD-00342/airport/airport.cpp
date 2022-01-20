#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#define LL long long
using namespace std;
struct node{
	int x,y;
}a[100100],b[100100];
int visa[100100],visb[100100];
int ansa[100100],ansb[100100];
priority_queue<LL>qa;
priority_queue<LL>qb;
int n,m1,m2;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++){
		scanf("%d%d",&a[i].x,&a[i].y);
		qa.push(-i);
	}
	for(int i=1;i<=m2;i++){
		scanf("%d%d",&b[i].x,&b[i].y);
		qb.push(-i);
	}
	for(int i=1;i<=n;i++){
		ansa[i]=m1;
		ansb[i]=m2;
	}
	ansa[0]=0;
	ansb[0]=0;
	int zhong1=0,cnt=0,bian=0,tm=0;
	while(!qa.empty()){
		LL s1=-qa.top();
		qa.pop();
		LL s1m=s1%1000001;
		//printf("%d ",s1m);
		if(bian>=s1m){
			tm++;
			ansa[tm]=cnt+ansa[tm-1];
			zhong1=0;
			cnt=0;
		}
		bian=s1m;
		int qi=a[s1m].x;
		if(qi>=zhong1){
			zhong1=a[s1m].y;
			cnt++;
		}
		else{
			qa.push(-s1-1000001);
		}
	}
//	tm++;
//	ansa[tm]=m1-ansa[tm-1];
	cnt=0;
	bian=0;
	int zhong2=0,tm2=0;
	while(!qb.empty()){
		LL s2=-qb.top();
		qb.pop();
		LL s2m=s2%1000001;
	//	printf("%d ",s2m);
		if(bian>=s2m){
			tm2++;
			ansb[tm2]=cnt+ansb[tm2-1];
			zhong2=0;
			cnt=0;
		}
		bian=s2m;
		int qi=b[s2m].x;
		if(qi>=zhong2){
			zhong2=b[s2m].y;
			cnt++;
		}
		else{
			qb.push(-s2-1000001);
		}
	}
//	tm2++;
	//ansb[tm2]=m2-ansb[tm2-1];
//	printf("\n");
	//for(int i=1;i<=tm2;i++)
	//	printf("%d ",ansb[i]);
	int ans=0;
	for(int i=0;i<=n;i++){
		ans=max(ans,ansa[i]+ansb[n-i]);
	}
	printf("%d\n",ans);
	return 0;
}

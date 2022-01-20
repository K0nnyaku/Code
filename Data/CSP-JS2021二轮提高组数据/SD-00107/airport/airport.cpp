#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<queue> 
#include<algorithm>
#define N 100010
#define ll long long 
using namespace std;
priority_queue<int> q1;
priority_queue<int> q2;
int n,m1,m2,n1,n2,now1,now2,cnt1,cnt2,ans=-1;
struct node{
	int l,r;
}e1[N],e2[N]; 
bool cmp(node a,node b){
	if(a.r!=b.r) return a.l<b.l;
	else return a.r<b.r;
}
void sol1(){
	while(!q1.empty()) q1.pop();
	now1=n1;cnt1=0;
	for(int i=1;i<=m1;i++){
		while(!q1.empty()&&-q1.top()<=e1[i].l){ //当前这个开始前还有能结束的 全部结束 
			now1++;q1.pop();
		}
		if(now1<=0) continue ;
		cnt1++;
		now1--;
		q1.push(-e1[i].r);
	}
}
void sol2(){
	while(!q2.empty()) q2.pop();
	now2=n2;cnt2=0;
	for(int i=1;i<=m2;i++){
		while(!q2.empty()&&-q2.top()<=e2[i].l){ //当前这个开始前还有能结束的 全部结束 
			now2++;q2.pop();
		}
		if(now2<=0) continue ;
		cnt2++;
		now2--;
		q2.push(-e2[i].r);
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++) scanf("%d%d",&e1[i].l,&e1[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&e2[i].l,&e2[i].r);
	sort(e1+1,e1+1+m1,cmp);
	sort(e2+1,e2+1+m2,cmp);
	for(int i=0;i<=n;++i){
		n1=i;n2=n-i;
		sol1();
		sol2();
		ans=max(ans,cnt1+cnt2);
	}
	printf("%d",ans);
	
	
	return 0;
}

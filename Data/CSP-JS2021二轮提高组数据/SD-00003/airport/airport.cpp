#include<iostream>
#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int N = 1e5+10;
int n,m1,m2,ans,flag;
int tem1,tem2,las=-1;
struct Node{
	int l,r;
}e1[N],e2[N];
bool cmp(Node a,Node b){
	return a.l<b.l;
}
void solve(int x){
	tem1=tem2=0;
	priority_queue<int> q;
	for(int i=1;i<=m1;i++){
		while(!q.empty()&&e1[i].l>=(-q.top()))
		q.pop();
		if(q.size()<x){
			q.push(-e1[i].r);
			tem1++;
		}
		else continue;
	}
	while(!q.empty()) q.pop();
	for(int i=1;i<=m2;i++){
		while(!q.empty()&&e2[i].l>=(-q.top()))
		q.pop();
		if(q.size()<(n-x)){
			q.push(-e2[i].r);
			tem2++;
		}
		else continue;
	}
	ans=max(ans,tem1+tem2);
	if(tem1==las){
		flag=1;
		return;
	}
	las=tem1;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	flag=0;
	for(int i=1;i<=m1;i++) scanf("%d%d",&e1[i].l,&e1[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&e2[i].l,&e2[i].r);
	sort(e1+1,e1+1+m1,cmp);
	sort(e2+1,e2+1+m2,cmp);
	int pan=min(m1,n);
	for(int i=0;i<=pan;i++){
		solve(i);
		if(flag) break;
	}
	printf("%d\n",ans);
	return 0;
}

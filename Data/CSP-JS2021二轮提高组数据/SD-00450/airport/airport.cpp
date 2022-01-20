#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int N=114514;
int n,m,k,tot,tot2,c[N],c1[N],c2[N],ans,sum,p[N];
priority_queue<int>q;
struct node{
	int h,t;
}e[N];
bool cmp(node x,node y){
	return x.h<y.h;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>k>>n>>m;
	for(int i=1;i<=n;i++)cin>>e[i].h>>e[i].t;
	sort(e+1,e+n+1,cmp);
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++)q.push(0);
		for(int j=1;j<=n;j++){
			int f=-q.top();q.pop();
			if(f<=e[j].h){
				f=e[j].t;c1[i]++;
			}
			q.push(-f);
		}
		while(q.size())q.pop();
	} 
	for(int i=0;i<=k;i++)cout<<c1[i]<<" ";
	for(int i=1;i<=m;i++)cin>>e[i].h>>e[i].t;
	sort(e+1,e+m+1,cmp);
	while(q.size())q.pop();
	for(int i=1;i<=k;i++){
		for(int j=1;j<=i;j++)q.push(0);
		for(int j=1;j<=m;j++){
			int f=-q.top();q.pop();
			if(f<=e[j].h){
				f=e[j].t;c2[i]++;
			}
			q.push(-f);
		}
		while(q.size())q.pop();
	}
	for(int i=0;i<=k;i++)cout<<c2[i]<<" ";
	for(int i=0;i<=k;i++){
		c[i]=c1[i]+c2[k-i];
		ans=max(c[i],ans);
	}
	cout<<ans;
	fclose(stdin);fclose(stdout);
	return 0;
}/*3 4 5 2 11
 4 15
 7 17
 12 16
 1 5
 3 8
 6 10
 9 14
 13 18
  */

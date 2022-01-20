#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
using namespace std;
const int N=100005;
struct node{
	int a,b;
};
bool operator < (node x,node y)
{
	return x.b>y.b;
}
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int n,m1,m2,ans=0;
node f1[N],f2[N],vis[N];
priority_queue<node>q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&f1[i].a,&f1[i].b);
	for(int i=1;i<=m2;i++)scanf("%d%d",&f2[i].a,&f2[i].b);
	sort(f1+1,f1+1+m1,cmp);
	sort(f2+1,f2+1+m2,cmp);
//	for(int i=1;i<=m1;i++)cout<<f1[i].a<<" ";
	for(int gn=0;gn<=n;gn++)
	{
		int gy=n-gn,tot=0;
		//国内 
		while(!q.empty())q.pop();
		for(int i=1;i<=m1;i++)
		{
			if(gn==0)break;
			while((!q.empty())&&(q.top().b<f1[i].a))
			{
//				cout<<q.top().a<<" "<<q.top().b<<endl;
				q.pop();
			}
			if(q.size()>=gn)continue;
			q.push(f1[i]);
//			cout<<"gn"<<i<<" ";
			tot++;
		}
		while(!q.empty())q.pop();
		//国外 
		for(int i=1;i<=m2;i++)
		{
			if(gy==0)break;
			while((!q.empty())&&(q.top().b<f2[i].a))
			{
//				cout<<q.top().a<<" "<<q.top().b<<endl;
				q.pop();
			}
			if(q.size()>=gy)continue;
			q.push(f2[i]);
//			cout<<i<<" ";
			tot++;
		}
		ans=max(ans,tot);
	}
	printf("%d",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

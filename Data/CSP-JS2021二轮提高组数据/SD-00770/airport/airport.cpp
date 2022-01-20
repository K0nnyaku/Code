#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
#include<deque>
#include<set>
#include<map>
#include<vector>
#include<cstdlib>
using namespace std;
int read()
{
	int x=0;bool f=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')f=0;ch=getchar();}
		while(ch<='9'&&ch>='0'){x=(x<<3)+(x<<1)+ch-'0';ch=getchar();}
	return f?x:(~x)+1;
}
struct node
{int q,z;};
bool cmmp(node a,node b){return a.q<b.q;}
int n,m1,m2;
node gn[100005],gw[100005];
int dpn[100005]={0},dpw[100005]={0};//给他分配的每一个廊桥
//最多能停几架飞机 
struct feiji 
{
	int lang,mo;//廊桥号 
	bool operator<(const feiji &a)const{
		return a.mo<mo;
	}
};
priority_queue<feiji>qn;
priority_queue<feiji>qw;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();m2=read();
	for(int i=1;i<=m1;i++){gn[i].q=read();gn[i].z=read();}
	for(int i=1;i<=m2;i++){gw[i].q=read();gw[i].z=read();}
	sort(gn+1,gn+m1+1,cmmp); sort(gw+1,gw+m2+1,cmmp);
	qn.push((feiji){1,gn[1].z});
	int topn=1;
	dpn[1]=1;
	for(int i=2;i<=m1;i++)
	{
		feiji k=qn.top();
		if(gn[i].q>k.mo)
		{
			dpn[k.lang]++;
			qn.pop();
			qn.push((feiji){k.lang,gn[i].z});
		}
		else 
		{
			dpn[++topn]=1;
			qn.push((feiji){topn,gn[i].z});
		}
	}	
	for(int i=1;i<=n;i++)
	dpn[i]=dpn[i]+dpn[i-1];
	qw.push((feiji){1,gw[1].z});
	int topw=1;
	dpw[1]=1;
	for(int i=2;i<=m2;i++)
	{
		feiji k=qw.top();
		if(gw[i].q>k.mo)
		{
			dpw[k.lang]++;
			qw.pop();
			qw.push((feiji){k.lang,gw[i].z});
		}
		else 
		{
			dpw[++topw]++;
			qw.push((feiji){topw,gw[i].z});
		} 
	}
	for(int i=1;i<=n;i++)
	dpw[i]=dpw[i]+dpw[i-1];   
	int ans=0; 
	for(int i=0;i<=n;i++)
	ans=max(ans,dpn[i]+dpw[n-i]);
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


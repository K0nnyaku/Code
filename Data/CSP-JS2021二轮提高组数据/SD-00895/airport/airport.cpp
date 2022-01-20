#include<bits/stdc++.h>
using namespace std;
int n,m,im,answer;
struct node{
	int st,en;
}f[200005],g[200005];
int num[100005],inum[100005];
int sum[100005];
int ans[100005],ians[100005];
bool pd(node a,node b)
{    
      return a.st<b.st; 
}
priority_queue<int,vector<int>,greater<int> >q;
priority_queue<int,vector<int>,greater<int> >Q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m>>im;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&f[i].st,&f[i].en);
	}
	
	sort(f,f+m+1,pd);
	for(int i=1;i<=im;i++){
		scanf("%d%d",&g[i].st,&g[i].en);
	}
	sort(g,g+im+1,pd);
	//for(int i=1;i<=m;i++)
	 //cout<<f[i].st<<" "<<f[i].en<<endl;
	//for(int i=1;i<=im;i++)
	  //cout<<g[i].st<<" "<<g[i].en<<endl; 
	q.push(f[1].en);
	num[1]=1;
	int line=1;
	sum[f[1].en]=1;
	for(int i=2;i<=m;i++){
		int x=q.top();
		if(f[i].st<x){
		   q.push(f[i].en);
		   line++;
		   num[line]++;
		   sum[f[i].en]=line;
		}
		else if(f[i].st>x)
		{
			q.pop();
			q.push(f[i].en);
			num[sum[x]]++;
			sum[f[i].en]=sum[x];
		}
	}
	memset(sum,0,sizeof(sum));
	while(!q.empty())
	  q.pop();
	q.push(g[1].en);
	inum[1]=1;
	 int iline=1;
	 sum[g[1].en]=1;
	for(int i=2;i<=im;i++)
	{
		int x=q.top();
		if(g[i].st<x){
		   q.push(g[i].en);
		   //cout<<x<<" "<<g[i].st<<endl;;
		   iline++;
		   inum[iline]++;
		   sum[g[i].en]=iline;
		}
		else if(g[i].st>x)
		{
			q.pop();
			q.push(g[i].en);
			inum[sum[x]]++;
			sum[g[i].en]=sum[x];
		}
		//cout<<iline<<" "<<sum[x]<<" "<<inum[iline]<<" "<<inum[sum[x]]<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		ans[i]=ans[i-1]+num[i];
		ians[i]=ians[i-1]+inum[i];
	//	cout<<num[i]<<" "<<ans[i]<<" "<<inum[i]<<" "<<ians[i]<<endl;
	}
	for(int i=0;i<=n;i++)
	  answer=max(answer,ans[i]+ians[n-i]);
	cout<<answer<<endl;
	return 0;
}

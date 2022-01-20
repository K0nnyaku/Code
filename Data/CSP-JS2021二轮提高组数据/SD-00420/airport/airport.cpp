#include<bits/stdc++.h>
using namespace std;
queue<pair<int,int> >q;
int n,num,numm,js,ans[100008],jnum,flag,jl[100008],jjnum,jll[1000008],anss[100008],zzda;
struct gn
{
	int qd,zd;
}a[100006];
struct gj
{
	int qd,zd;
}b[100006];
bool cmp(gn x,gn y)
{
	if(x.qd==y.qd)
	{
		return x.zd<y.zd;
	}
	else
	{
		return x.qd<y.qd;
	}
}
bool cmmp(gj xx,gj yy)
{
	if(xx.qd==yy.qd)
	{
		return xx.zd<yy.zd;
	}
	else
	{
		return xx.qd<yy.qd;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>num>>numm;
	for(int i=1;i<=num;i++)
		cin>>a[i].qd>>a[i].zd;
	for(int i=1;i<=numm;i++)
		cin>>b[i].qd>>b[i].zd;
	sort(a+1,a+num+1,cmp);
	sort(b+1,b+numm+1,cmmp);
	for(int i=1;i<=num;i++)
	{
		//if(q.size()==0)
		//{
			if(jl[i]==1)
				continue;
			ans[++js]=ans[js-1]+1;
			jnum=a[i].zd;
			q.push(make_pair(a[i].qd,a[i].zd));
			jl[i]=1;
			while(q.size())
			{
				for(int j=1;j<=num;j++)
				{ 			
					if(a[j].qd>jnum and jl[j]!=1)
					{
						q.push(make_pair(a[j].qd,a[j].zd));
						jl[j]=1;
						jnum=a[j].zd;
						ans[js]++;
						q.pop();
						flag=1;
					}
					else
					{
						flag=0;
					}
				}	
				if(flag==0)
					q.pop();
				flag=0;
			}
		//}
	}
	flag=0;
	js=0;
	for(int i=1;i<=numm;i++)
	{
		//if(q.size()==0)
		//{
			if(jll[i]==1)
				continue;
			anss[++js]=anss[js-1]+1;
			jjnum=b[i].zd;
			q.push(make_pair(b[i].qd,b[i].zd));
			jll[i]=1;
			while(q.size())
			{
				for(int j=1;j<=numm;j++)
				{ 			
					if(b[j].qd>jjnum and jll[j]!=1)
					{
						q.push(make_pair(b[j].qd,b[j].zd));
						jll[j]=1;
						jjnum=b[j].zd;
						anss[js]++;
						q.pop();
						flag=1;
					}
					else
					{
						flag=0;
					}
				}	
				if(flag==0)
					q.pop();
				flag=0;
			}
		//}
	}
	//q.push(make_pair(0,1));
	//cout<<q.front().second;
	for(int i=0;i<=n;i++)
	{
		zzda=max(zzda , ans[i]+anss[n-i]);
	}
	cout<<zzda;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


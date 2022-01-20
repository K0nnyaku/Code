#include<iostream>
#include<cstdio>
#include<algorithm>
#include<queue>

using namespace std;
//n 100000 m 100000
int n,m[2];

int ans,mans;

struct airport{
	int a,b;int num;
}ap[100001],bp[100001],alp[100001],blp[100001];

priority_queue<int,vector<int>,greater<int> > wait;

bool cmp(airport x,airport y)
{
	if(x.b<=y.b)return true;
	else return false;
}

bool cmpa(airport x,airport y)
{
	if(x.a<=y.a)return true;
	else return false;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	//input-s
	cin>>n>>m[0]>>m[1];//0国内 1国外; 
	for(int i=1;i<=m[0];i++)
	{
		cin>>ap[i].a>>ap[i].b;
	}
	for(int i=1;i<=m[1];i++)
	{
		cin>>bp[i].a>>bp[i].b;
	}
	//input-f
	//init-s
	sort(ap+1,ap+m[0]+1,cmp);
	sort(bp+1,bp+m[1]+1,cmp);
	for(int i=1;i<=m[0];i++)
	{
		ap[i].num=i;
		alp[i]=ap[i];
	}
	for(int i=1;i<=m[1];i++)
	{
		bp[i].num=i;
		blp[i]=bp[i];
	}
	sort(alp+1,alp+m[0]+1,cmpa);
	sort(blp+1,blp+m[1]+1,cmpa);
	//init-f
	int o=min(m[0],n);
	ans=0;
	for(int i=0;i<=o;i++)
	{
		mans=0;
		while(!wait.empty())wait.pop();
		for(int j=1;j<=m[0];j++)
		{
			while(!wait.empty()&&ap[wait.top()].b<=alp[j].a)wait.pop();
			if(wait.size()<i)
			{
				mans++;
				wait.push(alp[j].num);
			}	
		}
		while(!wait.empty())wait.pop();
		for(int j=1;j<=m[1];j++)
		{
			while(!wait.empty()&&bp[wait.top()].b<=blp[j].a)wait.pop();
			if(wait.size()<n-i)
			{
				mans++;
				wait.push(blp[j].num);
			}	
		}
		if(mans>ans)ans=mans;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

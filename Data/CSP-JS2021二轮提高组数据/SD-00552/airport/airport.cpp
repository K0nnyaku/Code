
#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<deque>
#include<cmath>
#include<cstring>
#include<unordered_map>
#include<map>
#include<set>
#include<vector>
using namespace std;
const int _max=1e8+9;
const int lesn=1e6+9;
int n,fm,fn;
int d[_max],c[_max];
int p,q;

pair<int,int>mark_d[lesn];
pair<int,int>mark_c[lesn];

int vis[lesn];
int maple1[lesn],maple2[lesn];
int lowbit(int k)
{
	return k&-k;
}
void updata_d(int x,int k)
{
	
	while(x<=p)
	{
		d[x]+=k;
		x+=lowbit(x);
	}
		
} 

int ask_d(int k)
{
	int sum=0;
	while(k)
	{
		sum+=d[k];
		k-=lowbit(k);
	}
	return sum;
}

void updata_c(int x,int k)
{
	
	while(x<=q)
	{
		c[x]+=k;
		x+=lowbit(x);
	}
		
} 

int ask_c(int k)
{
	int sum=0;
	while(k)
	{
		sum+=c[k];
		k-=lowbit(k);
	}
	return sum;
}

int cmp(pair<int,int> a,pair<int,int> b)
{
	return a.first>b.first;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n;
	scanf("%d%d",&fm,&fn);
	int ans_d=0;
	for(int i=1;i<=fm;i++)
	{
		cin>>mark_d[i].first>>mark_d[i].second;
		
		if(p<mark_d[i].second ) p=mark_d[i].second;
	}
	for(int i=1;i<=fm;i++)
	{
		updata_d(mark_d[i].first ,1);
		updata_d(mark_d[i].second+1,-1);
	}
	
	for(int i=1;i<=fm;i++)
	{
		ans_d=max(ask_d(mark_d[i].first),ans_d);
		
	}
	maple1[ans_d]=fm;
	for(int i=ans_d-1;i>=0;i--)
	{
		maple1[i]=maple1[i+1];
		for(int j=1;j<=fm;j++)
		{
			if(!vis[j])
			{
				if(ask_d(mark_d[j].first)>i) {
					cout<<ask_d(mark_d[j].first)<<" ";
					updata_d(mark_d[j].first ,-1);
					updata_d(mark_d[j].second +1,1);
					vis[j]=1;
					maple1[i]--;
				}
		
			}
		}
	}
	
	//////////////////////////////////////////////
	int ans_c=0;
	for(int i=1;i<=fn;i++)
	{
		cin>>mark_c[i].first>>mark_c[i].second;
		if(q<mark_c[i].second) q=mark_c[i].second;
	}
	
	for(int i=1;i<=fn;i++)
	{
		updata_c(mark_c[i].first,1);
		updata_c(mark_c[i].second+1,-1);
	}
	
	for(int i=1;i<=fn;i++)
	{
		ans_c=max(ans_c,ask_c(mark_c[i].first));
	}
	memset(vis,0,sizeof(vis));
	maple2[ans_c]=fn;
	for(int i=ans_c-1;i>=0;i--)
	{
		maple2[i]=maple2[i+1];
		for(int j=1;j<=fn;j++)
		{
			if(!vis[j])
			{
				if(ask_c(mark_c[j].first)>i) {
					updata_c(mark_c[j].first ,-1);
					updata_c(mark_c[j].second+1,1);
					vis[j]=1;
					maple2[i]--;
				}
			}
		
		}
	}
	if(n>=ans_c+ans_d) cout<<fm+fn;
	else
	{
		int sum=0;
		for(int i=0,j=n-i;i<=n&&j>=0;i++,j--)
		{
			//cout<<i<<"个de时候国内"<<maple1[i]<<"     "<<j<<"个的时候国际"<<maple2[j] <<endl;
			sum=max(sum,maple1[i]+maple2[j]);	
		} 
		cout<<sum;
	}
	
	//cout<<ans_d<<" "<<ans_c;
		fclose(stdin);
		fclose(stdout);
	return 0;
} 

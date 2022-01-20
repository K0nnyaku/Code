#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
long long int n,m1,m2,ans,can1[1000000],can2[1000000],back1[1000000],back2[1000000];
struct plain
{
	long long int l,r;
}t1[1000000],t2[1000000];
bool cmp(plain a,plain b)
{
	return a.l<b.l;
}
void go(int x)
{
	if(x==1)
	{
	//cout<<m1<<endl;
		back1[1]=t1[0].r;
		can1[1]++;
		for(int i=1;i<m1;i++)
		{
			for(int j=1;;j++)
			{
				if(t1[i].l>back1[j])
				{
					//cout<<"*"<<t1[i].l<<" "<<back1[j]<<endl;
					back1[j]=t1[i].r;
//					cout<<j<<" "<<i<<endl; 
					can1[j]++;
					break;
				}
			}
		}
	}
	else
	{
		//cout<<m2<<endl;
		back2[1]=t2[0].r;
		can2[1]++;
		for(int i=1;i<m2;i++)
		{
			for(int j=1;;j++)
			{
				if(t2[i].l>back2[j])
				{
					//cout<<"*"<<t2[i].l<<" "<<back2[j]<<endl;
					back2[j]=t2[i].r;
					can2[j]++;
//					cout<<j<<" "<<i<<endl;
					break;
				}
			}
		}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	//求各分配的数 
	for(int i=0;i<m1;i++)
	{
		cin>>t1[i].l>>t1[i].r;
	}
	sort(t1,t1+m1,cmp);
	go(1);
	
	for(int i=0;i<m2;i++)
	{
		cin>>t2[i].l>>t2[i].r;
	}
	sort(t2,t2+m2,cmp);
	go(2);
	//总共的飞机数 
	for(int i=1;i<=n;i++)
	{
		can1[i]+=can1[i-1];
//		cout<<can1[i]<<" ";
	}
//	cout<<endl;
	
	for(int i=1;i<=n;i++)
	{
		can2[i]+=can2[i-1];
//		cout<<can2[i]<<" ";
	}
//	cout<<endl;
	//总结 
	for(int i=0;i<=n;i++)
	{
		ans=max(can1[i]+can2[n-i],ans);
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

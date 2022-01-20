#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>

using namespace std;

int n,m1,m2;

bool gnflag[100000]={false},gwflag[100000]={false};

int cnt=0,summ[100005]={0}; 
int num=0;

int tme=0;

struct gn{
	int come1;
	int leave1;
}e1[100005];

struct gw{
	int come2;
	int leave2;
}e2[100005];

int leave3=0,leave4=0;

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int t1=0,t2=n;
	for(int i=1;i<=m1;i++)
	{
		cin>>e1[i].come1>>e1[i].leave1 ;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>e2[i].come2>>e2[i].leave2 ;
	}
	for(int k=0;k<=n;k++)
	{
		for(int i=1;i<=t1;i++)
	{
		gnflag[i]=true;
	}
	
	for(int i=1;i<=t2;i++)
	{
		gwflag[i]=true;
	}
	for(int k=1;k<=100000;k++)
	{
		tme++;
		for(int i=1;i<=m1+m2;i++)
	{
		for(int j=1;j<=m1+m2;j++)
		{
			if(e1[i].come1==tme && gnflag[j]==true)
			{
				
				gnflag[j]=false; 
				cnt++;
				if(e1[i].leave1 == tme)
				{
					gnflag[i]=true;
				}
			}
			if(e2[i].come2==tme && gwflag[j]==true )
			{
				gwflag[j]=false; 
				cnt++;
				if(e2[i].leave2 == tme)
				{
					gwflag[i]=true;
				}
			}
		} 
		summ[k]=cnt;
	}
	}
}
	t1++;
	t2--;

	for(int i=0;i<=m1+m2;i++)
	{
		if(num<summ[i])
		{
			num=summ[i];
		}
	}
	cout<<num;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


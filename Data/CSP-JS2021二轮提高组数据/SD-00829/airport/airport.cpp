#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>

using namespace std;

int n,m1,m2,a1[100005],b1[100005],a2[100005],b2[100005],bb1[1000005],bb2[100005],l1=1,l2=1,q1[1111],q2[1112],dq1=0,dq2=0,ans1=0,ans2=0;
int flag1=1,flag2=1;
int anss[100005];
int p,q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
	 	cin>>a1[i]>>b1[i];
	 	bb1[i]=b1[i];
	}
	sort(bb1,bb1+m1);

	for(int i=1;i<=m2;i++)
	{
		cin>>a2[i]>>b2[i];
		bb2[i]=b2[i];
	}
	sort(bb2,bb2+m2);
	for(int i=1;i<=m1;i++)
	{p=bb1[m1-1];}
	for(int i=1;i<=m2;i++)
	{q=bb2[m2-1];}
	for(int l1=0;l1<=n;l1++)
	{
		l2=n-l1;
		for(int t=1;t<=1000000000;t++)
		{	q1[t]=1;q2[t]=1;
			for(int i=1;i<=m1;i++)
			{
				if(a1[i]==t&&dq1<l1)
				{q1[t]=0;dq1++;ans1++;}
				if(b1[i]==t&&dq1>=l1&&q1[a1[i]]==0)
				{q1[t]=1;dq1--;}
				if(t>=p)
				{flag1=0;dq1=0;}
			}
			for(int i=1;i<=m2;i++)
			{
				if(a2[i]==t&&dq2<l2)
				{q2[t]=0;dq2++;ans2++;}
				if(b2[i]==t&&dq2>=l2&&q2[a2[i]]==0)
				{q2[t]=1;dq2--;}
				if(t>=q)
				{flag2=0;dq2=0;}
			}
			if(flag1==0&&flag2==0){flag1=1;flag2=1;break; }
		}
		
		anss[l1]=ans1+ans2;
		ans1=0;ans2=0;
	}
	sort(anss,anss+n);
	
	cout<<anss[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
 } 
 


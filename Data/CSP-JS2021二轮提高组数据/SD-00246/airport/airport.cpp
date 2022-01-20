#include<iostream>
#include<cstdio>
using namespace std;
int n,m1,m2,m11=100000000,m12=0,m21=100000000,m22=0;
int M11[100001],M12[100001],M21[100001],M22[100001];
int C11[100001],C12[100001],C21[100001],C22[100001];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	C11[0]=0;C12[0]=0;C21[0]=0;C22[0]=0;
	int max=0;
	cin>>n>>m1>>m2;	
	for(int i=1;i<=m1;i++)
	{
		cin>>M11[i]>>M12[i];
		if(m11>=M11[i])
			m11=M11[i];
		if(m12<=M12[i])
			m12=M12[i];
		C11[i]=M11[i];
		for(int k11=1;k11<=i;k11++)
		{
			if(C11[i]<C11[k11])
			{	
				for(int kk11=i;kk11>k11;kk11--)
				{
					C11[kk11]=C11[kk11-1];
				}
				C11[k11]=M11[i];
				break;
			}
		}
		C12[i]=M12[i];
		for(int k12=1;k12<=i;k12++)
		{
			if(C12[i]<C12[k12])
			{	
				for(int kk12=i;kk12>k12;kk12--)
				{
					C12[kk12]=C12[kk12-1];
				}
				C12[k12]=M12[i];
				break;
			}
		}
	}
	for(int j=1;j<=m2;j++)
	{
		cin>>M21[j]>>M22[j];
		if(m21>=M21[j])
			m21=M21[j];
		if(m22<=M22[j])
			m22=M22[j];
		C21[j]=M21[j];
		for(int k21=1;k21<=j;k21++)
		{
			if(C21[j]<C21[k21])
			{	
				for(int kk21=j;kk21>k21;kk21--)
				{
					C21[kk21]=C21[kk21-1];
				}
				C21[k21]=M21[j];
				break;
			}
		}
		C22[j]=M22[j];
		for(int k22=1;k22<=j;k22++)
		{
			if(C22[j]<C22[k22])
			{	
				for(int kk22=j;kk22>k22;kk22--)
				{
					C22[kk22]=C22[kk22-1];
				}
				C22[k22]=M22[j];
				break;
			}
		}
	}
	int a,b;
	for(a=0;a<=n;a++)
	{
		b=n-a;
		int ping=0,ped=0,qing=0,qed=0,d1=1,d2=1,e1=1,e2=1;
		for(int t=m11;t<=m12;t++)
		{
			for(int d=d1+1;d<=m1;d++)
			{
				if(C11[d]=t&&ping<=a&&a!=0)
				{
					ping=ping+1;
					ped=ped+1;
					d1=d;
				}
				if(C12[d]=t)
				{
					ping=ping-1;
					d2=d;
				}
			}
		}
		for(int s=m21;s<=m22;s++)
		{
			for(int e=e1+1;e<=m2;e++)
			{
				if(C21[e]=s&&qing<=b&b!=0)
				{
					qing=qing+1;
					qed=qed+1;
					e1=e;
				}
				if(C22[e]=s)
				{
					qing=qing-1;
					e2=e;
				}
			}
		}
		if(max<=ped+qed)
			max=ped+qed;
	}
	cout<<max;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

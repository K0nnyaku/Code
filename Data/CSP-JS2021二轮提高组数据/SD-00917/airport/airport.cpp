#include<bits/stdc++.h>
using namespace std;
int read()
{
	int o=0,e=1;
	char z;
	z=getchar();
	while(z<'0'||z>'9') {if(z=='-') e=-1;z=getchar();}
	while(z>='0'&&z<='9') {o=(o<<1)+(o<<3)+z-'0';z=getchar();}
	return o*e;
}
const int N=100010;
int n,m1,m2;
int a1[2*N],b1[N],a2[2*N],b2[N];
struct TI{
	int tm,ex,yz;								//ex 0入 1出，yz为出点的入点的数组坐标 
}t1[2*N],t2[2*N];
bool cmp1(TI a,TI b) {return a.tm<b.tm;}
int bol1[2*N],bol2[2*N];
int ans=1e9;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	freopen("in.in","r",stdin);
	
	n=read(),m1=read(),m2=read();
	for(int i=1;i<=2*m1;i+=2)
	{
		t1[i].tm=read();
		t1[i].ex=0;
		t1[i].yz=-1;
		t1[i+1].tm=read();
		t1[i+1].ex=1;
		t1[i+1].yz=t1[i].tm;
	}
	sort(t1+1,t1+1+2*m1,cmp1);
	for(int i=1;i<=2*m1;i++)
	{
		if(t1[i].ex==1)
		{
			for(int j=i;j>=1;j--)
			{
				if(t1[j].tm==t1[i].yz)
				{
					t1[i].yz=j;
					break;
				}
			}
		}
	}
	
	for(int i=1;i<=2*m2;i+=2)
	{
		t2[i].tm=read();
		t2[i].ex=0;
		t2[i].yz=-1;
		t2[i+1].tm=read();
		t2[i+1].ex=1;
		t2[i+1].yz=t2[i].tm;
	}
	sort(t2+1,t2+1+2*m2,cmp1);
	for(int i=1;i<=2*m2;i++)
	{
		if(t2[i].ex==1)
		{
			for(int j=i;j>=1;j--)
			{
				if(t2[j].tm==t2[i].yz)
				{
					t2[i].yz=j;
					break;
				}
			}
		}
	}
	
	for(int s=0;s<=n;s++) 
	{
		int res1=0;
		int res2=0;
		int cn1=s;
		int cn2=n-s;
		memset(bol1,0,sizeof(bol1));
		memset(bol2,0,sizeof(bol2));
		for(int i=1;i<=2*m1;i++)
		{
			if(t1[i].ex==0)
			{
				if(cn1>0)
				{
					cn1-=1;
					bol1[i]=1;					//表示在廊 
				}
				else
				{
					bol1[i]=0;					//进入猿猴 
					res1+=1;
				}
			}
			if(t1[i].ex==1)
				if(bol1[t1[i].yz]==1)
					cn1+=1;
		}
		for(int i=1;i<=2*m2;i++)
		{
			if(t2[i].ex==0)
			{
				if(cn2>0)
				{
					cn2-=1;
					bol2[i]=1;					//表示在廊 
				}
				else
				{
					bol2[i]=0;					//进入猿猴 
					res2+=1;
				}
			}
			if(t2[i].ex==1)
				if(bol2[t2[i].yz]==1)
					cn2+=1;
		}
		ans=min(res1+res2,ans);
	}
	cout<<m1+m2-ans<<endl;
	return 0;
}

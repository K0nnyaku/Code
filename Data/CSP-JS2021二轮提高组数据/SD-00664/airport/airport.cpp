#include<bits/stdc++.h> 
using namespace std;
const int mx=100010;
int n,m1,m2;
struct n1{
	long long a,b,d;
};
n1 s1[mx];
struct n2{
	long long a,b,d;
};
n2 s2[mx];
long long st1[mx],st2[mx];
bool cmp1(n1 a,n1 b)
{
	return a.a<b.a;
}
bool cmp2(n2 a,n2 b)
{
	return a.a<b.a;
}
inline int read()
{
	int x=0,y=1;char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		y=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return x*y;
}
int ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;++i)
	s1[i].a=read(),s1[i].b=read();
	for(int i=1;i<=m2;++i)
	s2[i].a=read(),s2[i].b=read();
	sort(s1+1,s1+1+m1,cmp1);
	sort(s2+1,s2+1+m2,cmp2);
	int fl1=1,f1=2,fl2=1,f2=2,o1=1,o2=1,as1=0,as2=0,ans=0;
	st1[fl1]=s1[1].b;st2[fl2]=s2[1].b;
	for(int i=0;i<=n;++i)
	{
	int j=n-i;
	while(f1<=m1)
	{
		bool in=0,o=0;
			while(o1<i&&!o)
			{
				fl1++;	o1++;
			 	st1[o1]=s1[f1++].b;
				as1++;
			}
		for(int s=1;s<=o1;++s)
		{
		
		if(st1[s]<s1[f1].a&&st1[s])
		{
			o1--;
			fl1--;
			for(int k=s;k<=o1;++k)
			st1[k]=st1[k+1];
		}
		}
		f1++;
		if(f1==m1)
		{
		fl1=1;f1=2;o1=1;
		memset(st1,0,sizeof(st1));
		st1[1]=s1[1].b;
		as1++;
		break;
		}
	}
	while(f2<=m2)
	{
		bool in=0,o=0;
			while(o2<j&&!o)
			{
				fl2++;	o2++;
			 	st2[o1]=s1[f2++].b;
				as2++;
			}
		for(int s=1;s<=o1;++s)
		{
		if(st2[s]<s2[f2].a&&st2[s])
		{
			o2--;
			fl2--;
			for(int k=s;k<=o1;++k)
			st2[k]=st2[k+1];
		}
		}
		f2++;
		if(f2==m2)
		{
		fl2=1;f2=2;o2=1;
		memset(st2,0,sizeof(st2));
		st2[1]=s2[1].b;
		as2++;
		break;
		}
	}
	ans=max(ans,as1+as2);
	as1=0;
	as2=0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long read()
{
	long long ans=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*f;
}
struct port
{
	int in;
	int leave;
}gn[5000000],gw[5000000];
struct sit
{
	int lt;
	int num;
}lt1[5000000],lt2[5000000];
bool cmp(port a,port b)
{
	return a.in<b.in;
}
bool cmp2(sit a,sit b)
{
	return a.lt<b.lt;
}
int gnkt[5000000]={0};
int gwkt[5000000]={0};
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	int n,m1,m2;
	n=read();
	m1=read();
	m2=read();
	int ans=0;
	for(int i=0;i<m1;i++)
		gn[i].in=read(),gn[i].leave=read();
	for(int i=0;i<m2;i++)
		gw[i].in=read(),gw[i].leave=read();
	sort(gn,gn+m1,cmp);
	sort(gw,gw+m2,cmp);
	int gnc=1,gwc=1;
	int line1=1,line2=1,h1=1,h2=1;
	for(int i=0;i<m1+m2;i++,line1++,line2++,h1++,h2++)
	{
		if(i<m1)
		{
			bool flag=0;
			lt1[line1].lt=gn[i].leave;
			sort(lt1+gnc,lt1+line1,cmp2);
			while(gn[i].in>lt1[gnc].lt)
			{
				lt1[line1].num=lt1[gnc].num;
				gnc++;
				h1--;
				flag=1;
			}
			if(!flag)
				lt1[line1].num=h1;
			if(gn[i].in<=lt1[gnc].lt)
				gnkt[lt1[line1].num]++;
		}
		if(i<m2)
		{
			bool flag=0;
			lt2[line2].lt=gw[i].leave;
			sort(lt2+gwc,lt2+line2,cmp2);
			while(gw[i].in>lt2[gwc].lt)
			{
				lt2[line2].num=lt2[gwc].num;
				gwc++;
				h2--;
				flag=1;
			}
			if(!flag)
				lt2[line2].num=h2;
			if(gw[i].in<=lt2[gwc].lt)
				gwkt[lt2[line2].num]++;
		}
		if(i>=m1&&i>=m2)
			break;
	}
	int maxn=0;
	for(int i=1;i<=lt1[gnc].num+1;i++)
		gnkt[i]+=gnkt[i-1];
	for(int i=1;i<=lt2[gwc].num+1;i++)
		gwkt[i]+=gwkt[i-1];
	for(int i=0;i<=lt1[gnc].num,i<=n;i++)
		for(int j=0;j<=n-i;j++)
			maxn=max(maxn,gnkt[i]+gwkt[j]);
	cout<<maxn;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring> 
using namespace std;
int re()
{
	int s=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=s*10+ch-48,ch=getchar();
	return s*f;
}
void wr(int s)
{
	if(s<0)s=-s,putchar('-');
	if(s>9)wr(s/10);
	putchar(s%10+48);
}
const int inf=5e4+7;
int m_1,m_2,n,ans,a,b;
int max1,min1=0x7f7f7f7f;
int max2,min2=0x7f7f7f7f;
int from1[inf],end_1[inf],from2[inf],end_2[inf];
bool v1[inf],v2[inf],v3[inf],v4[inf];
bool vis1[inf],vis2[inf];
struct shi_jian{
	int from,to;
}sj1[5007],sj2[5007];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=re();m_1=re();m_2=re();
	for(int i=1;i<=m_1;i++)
	{
		a=re(),b=re();
		sj1[i].from=a,sj1[i].to=b;
		from1[a]=i;end_1[b]=i;
		v1[a]=1;v2[b]=1;
		min1=min(a,min1);max1=max(max1,b);
	}
	for(int i=1;i<=m_2;i++)
	{
		a=re(),b=re();
		sj2[i].from=a,sj2[i].to=b;
		from2[a]=i;end_2[b]=i;
		v3[a]=1;v4[b]=1;
		min2=min(a,min2);max2=max(max2,b);
	}
	for(int i=0;i<=n;i++)
	{
		int num1=0,num2=0,j=n-i,ans_=0;
		for(int k=min1;k<=max1;k++)
		{
			if(v1[k]==1)
				if(num1<i)
				{
					num1++,ans_++;
					vis1[from1[k]]=1;
				}
			if(v2[k]==1)
				if(vis1[end_1[k]])
					num1--,vis1[end_1[k]]=0;
		}
		for(int k=min2;k<=max2;k++)
		{
			if(v3[k]==1)
				if(num2<j)
				{
					num2++,ans_++;
					vis2[from2[k]]=1;
				}
			if(v4[k]==1)
				if(vis2[end_2[k]])
					num2--,vis2[end_2[k]]=0;
		}
		ans=max(ans,ans_); 
	}
	wr(ans),putchar('\n');
	return 0;
}

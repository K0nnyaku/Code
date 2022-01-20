#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2,mt1[100009],mt2[100009],flag,nd,s1,s2,maxa;
struct note
{
	int bg;
	int ed;
	int book;
};
note a1[100009];
note a2[100009];
int cmp(note x,note y)
{
	if(x.bg<y.bg)return 1;
		return 0;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a1[i].bg,&a1[i].ed);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&a2[i].bg,&a2[i].ed);
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int k=1;k<=n;k++)
	{
		if(flag==0)
		{
			nd=0;
			for(int i=1;i<=m1;i++)
			{
				if(a1[i].book)continue;
				if(a1[i].bg>=nd)
				{
					a1[i].book=1;
					nd=a1[i].ed;
					s1++;
				}
			}
		}
		if(s1>=m1)
		{
			s1=m1;
			flag=1;
		}
		mt1[k]=s1;
	}
	flag=0;
	for(int k=1;k<=n;k++)
	{
		if(flag==0)
		{
			nd=0;
			for(int i=1;i<=m2;i++)
			{
				if(a2[i].book)continue;
				if(a2[i].bg>=nd)
				{
					a2[i].book=1;
					nd=a2[i].ed;
					s2++;
				}
			}
		}
		if(s2>=m2)
		{
			s2=m2;
			flag=1;
		}
		mt2[k]=s2;
	}
	for(int i=0;i<=n;i++)
	{
		if(mt1[i]+mt2[n-i]>maxa)
			maxa=mt1[i]+mt2[n-i];
	}
	cout<<maxa;
	return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>
#include<string>
#include<set>
using namespace std;
inline int read()
{
	int num=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while('0'<=ch&&ch<='9') {num*=10;num+=(ch-'0');ch=getchar();}
	return num*w; 
}
int n,m1,m2,last,ans,minn;
int cnt1,cnt2;
int pos1[100001];
int pos2[100001];
int fa1[100001];
int fa2[100001];
int sum1[100001];
int sum2[100001];
struct node
{
	int a;
	int b;
	int sum;
}p1[100001],p2[100001];
bool cmp_a(node xx,node yy) {return xx.a<yy.a;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	if(n>=m1+m2) {cout<<(m1+m2)<<endl;return 0;}
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&p1[i].a,&p1[i].b);
		p1[i].sum=1;
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&p2[i].a,&p2[i].b);
		p2[i].sum=1;
	}
	sort(p1+1,p1+m1+1,cmp_a);
	sort(p2+1,p2+m2+1,cmp_a);
	for(int i=1;i<=m1;i++)
	{
		fa1[i]=i;
	}
	for(int i=1;i<=m1;i++)
	{
		if(fa1[i]==i)
		{
			pos1[++cnt1]=i;
			last=p1[i].b;
			for(int j=i+1;j<=m1;j++)
			{
				if(p1[j].a>last&&fa1[j]==j) 
				{
					p1[i].sum++;
					fa1[j]=i;
					last=p1[j].b;
				}
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		fa2[i]=i;
	}
	for(int i=1;i<=m2;i++)
	{
		if(fa2[i]==i)
		{
			pos2[++cnt2]=i;
			last=p2[i].b;
			for(int j=i+1;j<=m2;j++)
			{
				if(p2[j].a>last&&fa2[j]==j)
				{
					p2[i].sum++;
					fa2[j]=i;
					last=p2[j].b;
				}
			}
		}
	}
	if(n>=cnt1+cnt2) {printf("%d\n",(m1+m2));return 0;}
	minn=min(n,cnt1);
	for(int i=1;i<=minn;i++)
	{
		sum1[i]=sum1[i-1]+p1[pos1[i]].sum;
	}
	minn=min(n,cnt2);
	for(int i=1;i<=minn;i++)
	{
		sum2[i]=sum2[i-1]+p2[pos2[i]].sum;
	}
	for(int i=0;i<=minn;i++)
	{
		ans=max(ans,sum2[i]+sum1[n-i]);
	}
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

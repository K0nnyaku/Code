#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#define maxn 200050
using namespace std;
int n,m1,m2,tot1,tot2;
int ans=-1,s1[maxn],s2[maxn];
std::priority_queue <int> q;
std::priority_queue <int> p;
int read()
{
	int f=1,s=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1; ch=getchar();} 
	while(ch>='0'&&ch<='9'){s=s*10+ch-'0';ch=getchar();}
	return s*f;
}
struct wor{
	int t,num,c;
}line1[maxn],line2[maxn];
struct pla{
	int st,en;
}p1[maxn],p2[maxn];
int search1(int x)
{
	int l=1,r=tot1,mid=(l+r)>>1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(line1[mid].t<x) l=mid+1;
		else r=mid;
	}
	return r;
}
int search2(int x)
{
	int l=1,r=tot2,mid=(l+r)>>1;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(line2[mid].t<x) l=mid+1;
		else r=mid;
	}
	return r;
}
int cmp(wor x,wor y)
{
	return x.t<y.t;
}
void get_data()
{
	int a,b;
	n=read(); m1=read(); m2=read();
	for(int i=1;i<=m1;i++)
	{
		a=read(); b=read();
		line1[++tot1].t=a;
		line1[tot1].c=1;
		line1[tot1].num=i;
		line1[++tot1].t=b;
		line1[tot1].c=-1;
		line1[tot1].num=i;
		p1[i].st=a;
		p1[i].en=b;
	}
	for(int i=1;i<=m2;i++)
	{
		a=read(); b=read();
		line2[++tot2].t=a;
		line2[tot2].c=1;
		line2[tot2].num=i;
		line2[++tot2].t=b;
		line2[tot2].c=-1;
		line2[tot2].num=i;
		p2[i].st=a;
		p2[i].en=b;
	}
}
int solve1(int sum)
{
	int ans1=0;
	bool f=false;
	int x1;
	if(sum==0) return 0;
	int tmt;
	int now=0,i=0;
	while(i<tot1)
	{
		while(now<sum)
		{
			if(i>=tot1) break;
			i++;
			if(now+line1[i].c<0) 
			{
				i++;continue;
			}
			now+=line1[i].c;
			if(line1[i].c==1)
			{
				q.push(-p1[line1[i].num].en);
				ans1++;
			}
		}
		while(1)
		{
			if(q.empty()) break;
			tmt=-q.top();
			x1=search1(tmt);
			q.pop();
			if(i<x1) 
			{
				i=x1; f=true;
				break; 
			}
		}
		if(f) now+=line1[i].c;
	}
	return ans1;
}
int solve2(int sum)
{
	int ans1=0;
	bool f=false;
	int x1;
	if(sum==0) return 0;
	int tmt;
	int now=0,i=0;
	while(i<tot2)
	{
		while(now<sum)
		{
			if(i>=tot2) break;
			i++;
			if(now+line2[i].c<0) 
			{
				i++;continue;
			}
			now+=line2[i].c;
			if(line2[i].c==1)
			{
				p.push(-p2[line2[i].num].en);
				ans1++;
			}
		}
		while(1)
		{
			if(p.empty()) break;
			tmt=-p.top();
			x1=search2(tmt);
			p.pop();
			if(i<x1) 
			{
				i=x1; f=true;
				break; 
			}
		}
		if(f) now+=line2[i].c;
	}
	return ans1;
}
void out_answer()
{
	int j;
	sort(line1+1,line1+tot1+1,cmp);
	sort(line2+1,line2+tot2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		j=n-i;
		ans=max(ans,solve1(i)+solve2(j));
	}
	printf("%d\n",ans);
	return;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	get_data();
	out_answer();
	return 0;
}

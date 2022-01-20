#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define Maxn 1000005
using namespace std;
int k,n,l[Maxn],num[Maxn],r[Maxn],steps[Maxn],vis[Maxn];
bool vis[Maxn];
void read(int &x)
{
	char ch=getchar();x=0;int f=1;
	while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch<='9'&&ch>='0'){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
	x*=f;
}
int find_d(int s)
{
	int ls=l[s],rs=r[s];
	while(ls!=rs)
	{
		if(num[ls]>num[rs]) return 1;//”“ 
		if(num[ls]<num[rs]) return 0;//◊Û 
		ls=l[ls],rs=r[rs];
	}
	return 0;
}
int find_pair(int s)
{
	if(find_d(s))
	{
		int p=r[s];
		while(num[p]!=num[s]){
			p=r[p];
			if(vis[p]) return 0;
		}
	}
	else
	{
		int p=l[s];
		while(num[p]!=num[s])
		{
			p=l[p];
			if(vis[p]) return 0;
		}
	}
	return p;
}
void bfs1()
{
	
}
void bfs2()
{
	
}
void delet(int p)
{
	r[l[p]]=r[p];
	l[r[p]]=l[p];
}
int main()
{
	read(k);
	for(int i=1;i<=k;++i)
	{
		read(n);n*=2;
		for(int j=1;j<=n;++j)
		{
			read(num[j]);
			l[j]=j-1;r[j]=j+1;
		}
		l[1]=n;r[n]=1;
		int s=min(num[1],num[n]);
		int p=find_pair(s);
		if(p)
		{
			if(find_d(s)) bfs1();
		}
		else
		 cout<<-1;
	}
	return 0;
}

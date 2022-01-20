#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1e5+10,M=1e3+10;
int n,T,p[N];

int Get_bits(int x)
{
	int cnt=0;
	while(x)
	{
		cnt++;
		x>>=1;
	}
	return cnt;
}

bool Small_check(int i,int j,int k)
{
	if(p[i]==i)
	{
		int cnt=0;
		while(j!=p[j]) j=p[j],cnt++;
		if(j!=i) return false;
		return cnt<=k;
	}
	if(p[j]==j)
	{
		int cnt=0;
		while(i!=p[i]) i=p[i],cnt++;
		if(j!=i) return false;
		return cnt<=k;
	}
	
	int way1[M],way2[M],idx1=0,idx2=0;
	way1[++idx1]=i,way2[++idx2]=j;
	while(i!=p[i])
	{
		i=p[i];
		way1[++idx1]=i;
	}
	while(j!=p[j])
	{
		j=p[j];
		way2[++idx2]=j;
	}
	
	for(int i=1;i<=idx1;i++)
	for(int j=1;j<=idx2;j++)
	if(way1[i]==way2[j])
	{
		if(i+j-2<=k) return true;
		else return false;
	}
	return false;
}

int main()
{
	freopen("dis.in","r",stdin);
	freopen("dis.out","w",stdout);
	scanf("%d%d",&n,&T);
	if(n<=50)
	{
		p[1]=1;
		for(int i=2;i<=n;i++)
			p[i]=i/2;
		while(T--)
		{
			char ch[2];
			int op;
			scanf("%s%d",ch,&op);
			if(ch[0]=='-')
			{
				p[op]=op;
			}
			else 
			{
				int cnt=0;
				for(int i=1;i<=n;i++)
				for(int j=i+1;j<=n;j++)
					if(Small_check(i,j,op)) cnt++;
				printf("%d\n",cnt);
			}
		}
	}
	return 0;
}

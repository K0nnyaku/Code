#include<bits/stdc++.h>
using namespace std;

struct qsj{
	int le,rg;
};

qsj qj1[10000050],qj2[10000050];

int n,msf,mss,ans,tong1[100000050],xq1[500000],xq2[500000],tong2[100000050],maxn1,maxn2,qz1[100000050],qz2[100000050];

inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0',ch=getchar();}
    return s*w;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout); 
	
	cin>>n>>msf>>mss;
	for(int i=1;i<=msf;i++)
	{
	    qj1[i].le=read(),qj1[i].rg=read();
		maxn1=max(maxn1,qj1[i].rg);
	    tong1[qj1[i].le]++,tong1[qj1[i].rg]--;
	}
	for(int i=1;i<=mss;i++)
	{
	    qj2[i].le=read(),qj2[i].rg=read();
	    maxn2=max(maxn2,qj2[i].rg); 
	    tong2[qj2[i].le]++,tong2[qj2[i].rg]--;
	}
    for(int i=1;i<=maxn1;i++) qz1[i]=qz1[i-1]+tong1[i];
	
    for(int i=1;i<=maxn2;i++) qz2[i]=qz2[i-1]+tong2[i];

	for(int i=1;i<=maxn1;i++)
	{
		if(qz1[i]==qz1[i-1]+1) 
		{
			xq1[qz1[i-1]]++;
		}
	}
	for(int i=1;i<=maxn2;i++)
	{
		if(qz2[i]==qz2[i-1]+1) 
		{
			xq2[qz2[i-1]]++;
		}
	}
	int tmp;
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(j>xq1[i]) ans+=xq1[i];
			if(n-j>xq2[i]) ans+=xq2[i];
		}
		tmp=max(tmp,ans);
	}
	
	
	cout<<tmp-1;

	
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/

/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/

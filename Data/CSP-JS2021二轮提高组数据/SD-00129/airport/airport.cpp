#include<bits/stdc++.h>
using namespace std;
#define LL long long
inline int Read()
{
	int x;
	char ch;
	bool neg=0;
	while ((ch=getchar())<'0'||ch>'9') neg=(ch=='-');
	x=ch-'0';
	while ((ch=getchar())>='0'&&ch<='9') x=(x<<1)+(x<<3)+ch-'0';
	return neg?-x:x;
}
const int N=100000+10;
int n,m1,m2;
int a1[N],b1[N];
int a2[N],b2[N];
int t1[N],t2[N];
int ans1[N],ans2[N];

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j,k,t,ans=0;
	n=Read(),m1=Read(),m2=Read();
	for (i=1;i<=m1;i++)
	{
		a1[i]=Read(),b1[i]=Read();
		
	}
	for (i=1;i<=m2;i++)
	{
		a2[i]=Read(),b2[i]=Read();
		
	}
	bool o;
	for (i=1;i<=m1;i++)
	{
		t=a1[i];
		o=0;
		for (j=1;j<=i;j++)
		{
			if (t1[j]<t)
			{
				o=1;
				break;
			}
		}
		t1[j]=b1[i];
		ans1[j]++;
		
	}
	for (i=1;i<=m2;i++)
	{
		t=a2[i];
		o=0;
		for (j=1;j<=i;j++)
		{
			if (t2[j]<t)
			{
				o=1;
				break;
			}
		}
		t2[j]=b2[i];
		ans2[j]++;
		
	}
	for (i=1;i<=n;i++)
	{
		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
	}
	for (i=0;i<=n;i++)
		ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%d\n",ans);
	fclose(stdin);
	fclose(stdout);
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

7
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

4
*/

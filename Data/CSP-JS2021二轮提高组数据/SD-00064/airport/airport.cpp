#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
const int NR=1e5+10;
struct node{
	int st,ed;
};
node p1[NR],p2[NR];

int n,m1,m2,ans;
int cnt1[NR],cnt2[NR],last1[NR],last2[NR];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>p1[i].st>>p1[i].ed;
		for(int j=1;j<=n;j++)
		{
			if(p1[i].st>last1[j])
			{
				cnt1[j]++;
				last1[j]=p1[i].ed;
				break;
			}
		}
	} 
	for(int i=1;i<=m2;i++) 
	{
		cin>>p2[i].st>>p2[i].ed;
		for(int j=1;j<=n;j++)
		{
			if(p2[i].st>last2[j])
			{
				cnt2[j]++;
				last2[j]=p2[i].ed;
				break;
			}
		}
	} 
	for(int i=1;i<=n;i++)
	{
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
	}
	for(int i=1;i<=n;i++) ans=max(ans,cnt1[i]+cnt2[n-i]);
	cout<<ans<<endl;
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

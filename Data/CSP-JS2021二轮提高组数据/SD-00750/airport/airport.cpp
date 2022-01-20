#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
int n,m1,m2,ans1[maxn],ans2[maxn],ans[maxn];
int m1_min,m2_min;
struct node1
{
	int start;
	int end;
	bool park;
} nat[maxn];
struct node2
{
	int start;
	int end;
	bool park;
} intnat[maxn];
bool cmp1(node1 x,node1 y){return x.start<y.start;}
bool cmp2(node2 x,node2 y){return x.start<y.start;}
int dp1(){
	int qw1 = 0,c1 = 0,can1 = 0;
	for(int i = 1;i<=m1;i++)
	{
		if(nat[i].park == 1) 
		{
			c1++;
			if(c1 == 1) can1 = nat[i].end,nat[i].park = 0,qw1++;
			if(c1!=1&&nat[i].start>=can1) nat[i].park = 0,can1 = nat[i].end,qw1++;
		}
	}
	return qw1;}
int dp2(){
	int qw2 = 0,c2 = 0,can2 = 0;
	for(int i = 1;i<=m2;i++)
	{
		if(intnat[i].park == 1) {c2++;
		if(c2 == 1) can2 = intnat[i].end,intnat[i].park = 0,qw2++;
		if(c2!=1&&intnat[i].start>=can2) intnat[i].park = 0,can2 = intnat[i].end,qw2++;}
	}
	return qw2;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(ans1,0,sizeof(ans1));
	memset(ans2,0,sizeof(ans2));
	scanf("%d%d%d",&n,&m1,&m2);
	if(n>=m1+m2) {cout<<m1+m2;return 0;}
	for(int i=1;i<=m1;i++)
	scanf("%d%d",&nat[i].start,&nat[i].end),nat[i].park = 1;
	for(int i=1;i<=m2;i++)
	scanf("%d%d",&intnat[i].start,&intnat[i].end),intnat[i].park = 1;
	sort(nat+1,nat+m1+1,cmp1);
	sort(intnat+1,intnat+m2+1,cmp2);
	ans1[0] = 0,ans2[0] = 0,ans1[n] = n, ans2[n] = n;
	for(int i = 1;i<m1;i++)
	ans1[i] = ans1[i-1]+dp1(); 
	for(int j = 1;j<m2;j++)
	ans2[j] = ans2[j-1]+dp2();
	int answ = 0;
	for(int i = 0;i<=n;i++)
	{ ans[i] = ans1[i]+ans2[n-i];if(ans[i]>answ) answ = ans[i]; }
	cout<<answ;
	return 0;	
} 

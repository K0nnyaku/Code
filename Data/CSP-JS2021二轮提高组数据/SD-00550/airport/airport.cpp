#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
int a,b,c,f[105][105][105],l[105][105][105];
struct node
{
	int l,r;
}t1[100005],t2[100005];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>a>>b>>c;
	for(int m=1;m<=b;m++)
		cin>>t1[m].l>>t1[m].r;
	for(int m=1;m<=c;m++)
		cin>>t2[m].l>>t2[m].r;
	if(b+c==a)
	{
		cout<<b+c;
		return 0;
	}
	sort(t1+1,t1+b+1,cmp);
	sort(t2+1,t2+c+1,cmp);
	for(int n=1;n<=a;n++)
		for(int m=1;m<=b;m++)
			for(int i=1;i<=n;i++)
				if(t1[f[i][f[i][0][n]][n]].r<=t1[m].l)
				{
					f[i][0][n]++;
					f[i][f[i][0][n]][n]=m;
					break;
				}
	for(int n=1;n<=a;n++)
		for(int m=1;m<=c;m++)
			for(int i=1;i<=n;i++)
				if(t2[l[i][l[i][0][n]][n]].r<=t2[m].l)
				{
					l[i][0][n]++;
					l[i][l[i][0][n]][n]=m;
					break;
				}
	int maxx=0;
	for(int m=1;m<=a;m++)
	{
		int tt1=0,tt2=0;
		for(int n=1;n<=m;n++)
			tt1+=f[n][0][m];
		for(int n=1;n<=a-m+1;n++)
			tt2+=l[n][0][a-m];
		maxx=max(maxx,tt1+tt2);
	}
	cout<<maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

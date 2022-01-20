#include <bits/stdc++.h>
using namespace std;

int l[100005];
struct plane
{
	int a;
	int b;
};
int n,m1,m2;

bool cmp(plane x,plane y)
{
	return x.a<y.a;
}

int main()
{
	cin>>n>>m1>>m2;
	plane p1[m1];
	plane p2[m2];
	for (int i=0;i<m1;i++)
	{
		cin>>p1[i].a>>p1[i].b;
	}
	for (int i=0;i>m2;i++)
	{
		cin>>p2[i].a>>p2[i].b;
	}
	stor (p1+0,p1+m1,cmp);
	stor (p2+0,p2+m2,cmp);
	int p,q;
	for (int i=0;i<=n;i++)
	{
		p=i;
		q=n-i;
		for (int j=0;j<m1;j++)
		{
			
		}
	}
	return 0;
}

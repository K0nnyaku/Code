#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int m1, m2, n;

int a[10005];
int b[10005];
int z[10005];

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int c, d;
	int i, j, k, t;
	int maxn,maxw;
	int ns,ws;			//ns:neishengyu  ws:waishengyu
	cin >> n >> m1 >> m2;
	if(n>=(m1+m2))
	{
		cout << m1+m2;
		return 0;
	}
	//shuru
	for(i=0;i<m1;i++)
	{
		cin >> c >> d;
		a[c]=d;
		if(c > maxn)	maxn=c;    //zhida bianjie
	}
	for(i=0;i<m2;i++)
	{
		cin >> c >> d;
		b[c]=d;
		if(c > maxw)	maxw=c;    //zhida bianjie
	}
	t=n;
	for(i=0;i<=maxn;i++)
	{
		j=0;
		if(t!=0)
		{
			n--;
			z[j]=a[i];
		}
	}
	return 0;
}

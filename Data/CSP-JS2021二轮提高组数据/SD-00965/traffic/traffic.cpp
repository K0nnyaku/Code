#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t,sum=0;
	int min;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>t;
			t+=t;
		}
	}
	printf("%d",t);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

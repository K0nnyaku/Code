#include<bits/stdc++.h>
using namespace std;
//-----
int n;
int m;
int a[50001];
//-----
//=====//=====//=====//=====


//=====//=====//=====//=====
int main( )
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&m)
	for (int l=1;l<=m;l++)
	{
		scanf("%d",&n);
		for (int l=1;l<=2*n;l++)
		{
			scanf("%d",&a[l]);
		}
		for (int l=1;l<=2*n;l++)
		{
			if (a[l]%2==1)
			{
				cout<<"L";
			}
			else if (a[l]%2==0)
			{
				cout<<"R";
			}
		}
	}
	return 0;
}

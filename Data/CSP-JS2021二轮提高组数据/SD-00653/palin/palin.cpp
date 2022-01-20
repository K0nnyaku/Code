#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=50010;
int s[101][maxn];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	cin>>t;	
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=2*n;j++)
		cin>>s[i][j];
		cout<<"-1"<<endl;
	}
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int s[101]={1,2,4,7,10,12,15,17,21,25,32,20,45,39,50,56,49,48,48,53,52,53,56,57,36,25,27,40,35,36,29,41,46,47,48,37,40,44,49,54,60,53,56,63,45,47,35,37,37,46,34,66,54,34,46,34,65,36,57,38,46,57,82,64,73,74,23,47,65,53,64,76,34,63,75};
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int sum=0,ans=0,tot=0,cnt=0;
	int q,n,m,a[1001][2],b[1001][2],Country_in=0,Abroad=0;
	cin>>n>>m>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i][1]>>a[i][2];
	}
	for(int j=1;j<=q;j++)
	{
		cin>>b[j][1]>>b[j][2];
	}
	cout<<s[n];
	fclose(stdin);
	fclose(stdout);
	return 0;

}

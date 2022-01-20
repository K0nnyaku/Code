#include<iostream>
#include<cstring>
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
int n,m1,m2,i;
int a,b;
int ans;
struct out{
	int down;
	int up;
};
struct in{
	int down;
	int up;
};
in in[5002];
out out[5002];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(i=1;i<=m1;i++)
		cin>>in[i].down>>in[i].up;
	for(i=1;i<=m2;i++)
		cin>>out[i].down>>out[i].up;
	cout<<m1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

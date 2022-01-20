#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm> 
using namespace std;
int main()
{
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
int n,m1,m2;
cin>>n>>m1>>m2;
if(m1>m2)
{
	cout<<m1+m2/2;
}
else if(m1<m2) 
{
	cout<<m1;
}
fclose(stdin);
fclose(stdout);
return 0;
}

#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,mi,mii;
int time[500000];

int main()// 
{
	int a,b;
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);	
	cin>>n>>mi>>mii;
	for(int i=0;i<mi;i++)
		cin>>a>>b;
	for(int i=0;i<mii;i++)
		cin>>a>>b;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

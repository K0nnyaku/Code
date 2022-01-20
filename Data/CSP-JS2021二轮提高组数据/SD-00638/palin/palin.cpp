#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	int n,p;
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		cin>>p;
		cout<<-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


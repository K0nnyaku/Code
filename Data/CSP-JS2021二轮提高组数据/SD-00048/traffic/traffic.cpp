#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	for(int i=1;i<=c;i++)
		cout<<a*b*2<<endl;
	return 0;
}

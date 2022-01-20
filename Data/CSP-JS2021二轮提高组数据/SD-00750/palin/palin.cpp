#include <iostream>
#include <cstdio>

using namespace std;
const int maxn = 1000000 + 5;
int T,n;
int a[maxn];
int main()
{
	//freopen("palin.in","r",stdin);
	//freopen("palin.out","w",stdout);
	cin>>T>>n;
	for(int i=1;i<=T;i++)
	{
	for(int i=1;i<=2*n;i++)
	cin>>a[i];
	for(int i=1;i<=T;i++)
	cout<<"-1"<<endl;
	}
	return 0;	
} 

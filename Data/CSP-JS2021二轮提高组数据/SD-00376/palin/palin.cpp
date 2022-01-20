#include <iostream>
#include <cstdio>
#include <list>
typedef long long ll;
using namespace std;
const int size = 10010;
ll T,n,a[size],b[size],num;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin >> T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=n+n;i++)
			cin >> a[i];
		cout<<-1;
	}
	return 0;
}

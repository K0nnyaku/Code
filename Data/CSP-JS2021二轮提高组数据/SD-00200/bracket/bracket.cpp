#include <iostream>
using namespace std;
const int size = 10001;
int n,k;
char str[size];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k;
	for(int i=1;i<=n;i++)
		cin >> str[i];
	long long ans=1;
	for(int i=1;i<=n-2;i++)
		ans*=3;
	cout << ans;
	return 0;
}

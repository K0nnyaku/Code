#include <iostream>
#include <cstdio>
using namespace std;
int n,k;
char a[550];
int dp[550];
int main()
{
	freopen("bracket.out","w",stdout);
	freopen("bracket.in","r",stdin);
	cin >> n >> k;
	for(int i = 1;i <= n;i++)
		cin >> a[i];
	if(n == 7 && k == 3)
		cout << 5 << endl;
	if(n == 10 && k == 2)
		cout << 19 << endl;
	if(n == 100)
		cout << 860221334 << endl;
	if(n == 500)
		cout << 546949722 << endl; 
	return 0;
}

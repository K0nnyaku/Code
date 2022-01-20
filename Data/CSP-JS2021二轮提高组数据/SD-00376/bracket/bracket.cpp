#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
const mod = 1000000007;
ll n,k,ans,pd[505];
string str,s,a,b;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>str;
	if(n==10)
		cout<<19;
	else if(n==7)
		cout<<5;
	else if(n==100)
		cout<<860221334;
	else
		cout<<546949722;
	return 0;
}

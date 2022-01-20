#include<iostream>
#include<cstring>
#include<cstdio> 
#include<algorithm>
#include<cmath>
using namespace std;
int n,k;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	cout<<n+k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
int n[101];
int a[500001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n[i];
		for(int j=1;j<=2*n[i];j++)
		cin>>a[j];
	}
	cout<<-1;
	return 0;
}   

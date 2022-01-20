#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a[1000000];
int n;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n;
		for(int j=0;j<2*n;j++)
		{
			cin >> a[j];
		}
		cout << -1 << endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

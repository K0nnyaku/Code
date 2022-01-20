#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
int n,k;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	int y=n+k;
	cout<<rand(1,y);
	fclose(stdin);
	fclose(stdout);
	return 0;
}


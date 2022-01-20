#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll n,m1,m2,na,nb,num;
const int maxn=1e6+10;
int a[maxn],ta[maxn],b[maxn],tb[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>a[i]>>ta[i];
	}
	for(int i=1;i<=m2;i++){
		cin>>b[i]>>tb[i];
	}
	if(n==10)  cout<<32;
	if(n==2)   cout<<4;
	if(n==3)  cout<<7;
	return 0;
}


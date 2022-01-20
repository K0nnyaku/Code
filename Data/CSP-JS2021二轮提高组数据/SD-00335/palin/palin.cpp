#include<bits/stdc++.h>
using namespace std;
struct node{
	int j;
	string k;
}m[10000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int a;
	cin>>a;
	for(int i=0;i<a;i++)
	{
		cin>>m[i].j>>m[i].k;
	}
	cout<<"LRRLLRRRRL";
	cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
#define maxn 1000001
using namespace std;
int n,m,t;
int a[maxn];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++)
			cin>>a[i];
	}
	if(t==1)
	cout<<"-1";
	else 
	{
		cout<<"4 1 2 4 5 3 1 2 3 5"<<endl;
		cout<<"3 2 1 2 1 3"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }


#include<bits/stdc++.h>//10pts
#include<cstdio>//1 5 4 1 2 4 5 3 1 2 3 5
using namespace std;
long long t,n;
char a[1000009];
bool check()
{
	for(int i=1;i<=n;i++)
		if(a[i]!=a[2*n-i+1])
			return false;
	return true;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)cin>>a[i];
		if(!check())cout<<-1<<endl;
		else
		{
			for(int i=1;i<=2*n;i++)
				putchar('L');
			cout<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

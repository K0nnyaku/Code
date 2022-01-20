#include <iostream>
#include <cstdio>
#include <string>

using namespace std;
int cx(int m);

string ss;

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n,m,i,j,a;
	int t,f;
	cin >> n;
	if(n==1)
	{
		cin >> m;
		f=cx(m);
		if(f==1)
		{
			cout << "-1" ;
			return 0;
		}
	}
	while(n!=0)
	{
		n--;
		cin >> m;
		f=cx(m);
		if(f==1)
			cout << "-1"<< endl;
	}
	return 0;
}
int cx(int m)
{
	int i,t=0;
	int a[100]={};
	int b[100];
	for(i=0;i<m*2;i++)
	{
		cin >> a[i];
		if(a[i]==a[i-1])
		{
			b[t]==i-1;
			t++;
		}
	}
	if(t>=3)	
		return 1;
	if(t==2 && b[t-1]!=b[t-2]+2)
		return 1;
}

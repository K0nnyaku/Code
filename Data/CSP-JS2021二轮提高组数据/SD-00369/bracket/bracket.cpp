#include<iostream>
#include<cstdio>
using namespace std;
char a[505];
long long sum;
int n,k,b[505],c[505];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>a;
	int x;
	if(n%2!=0&&k%2==0)
		cout<<0;
	else
	{
		if(n%2==0&&k%2!=0)
			cout<<0;
		else
		{
			cout<<(n%10)*x+k/10;	
		}
	}	
	return 0;
	fclose(stdin);
	fclose(stdout);
}

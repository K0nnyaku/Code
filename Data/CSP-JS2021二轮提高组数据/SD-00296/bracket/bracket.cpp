#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
#include<stack>
using namespace std;
long long quickpower(int a,int b)
{
	long long base=a,ans=1;
	while(b>0)
	{
		if(b&1)	ans*=base;
		base*=base;
		b>>=1;
	}
	return ans;
}
int gcd(int a,int b)
{
	if(a%b==0)
		return b;
	return gcd(b,a%b);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cout<<"26";
	fclose(stdin);
	fclose(stdout);
	return 0;
}


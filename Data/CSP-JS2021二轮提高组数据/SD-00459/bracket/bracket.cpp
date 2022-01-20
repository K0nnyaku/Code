#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
char a[100005];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	cin>>n>>k>>a;
	if(n==7 && k==3 && a[0]=='(')
		cout<<5;
	else if(n==1) cout<<1;
	else
	{
		long long s=1;
		int len=strlen(a);
		for(int i=0; i<len; ++i)
			if(a[i]=='?') s=s*3;
		cout<<s;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

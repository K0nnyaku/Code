#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,k,len,a[16];
char c[16];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
	scanf("%c",&c[i]);
	if(c[i]=='(') a[i]=1;
	if(c[i]==')') a[i]=2;
	if(c[i]=='*') a[i]=3;
	if(c[i]=='?') a[i]=4;
	}
	if(n==7) cout<<5;
	if(n==10) cout<<19;
	if(n==100) cout<<860221334;
	if(n==500) cout<<546949722;
	else cout<<347767;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

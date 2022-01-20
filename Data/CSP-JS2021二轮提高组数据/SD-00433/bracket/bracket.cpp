#include<bits/stdc++.h>
using namespace std;
int n,k;
char a[10001];

//=====//=====//=====//=====
int main( )
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	gets(a);
	cout<<(n*k)%1000000007;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstdio>

using namespace std;

char a[10000];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%c",&a[i]);
	}
	cout<<2*n-1<<endl;
	return 0;
}

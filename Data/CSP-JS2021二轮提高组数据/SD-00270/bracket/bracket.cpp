#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int mod=1e9+7;
const int maxn=507;
char a[maxn];
ll n,k,temcp=0;

int main()
{
	//È«²¿¿ªlong long
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);	
	scanf("%lld%lld",&n,&k);
	if (n<=1) cout<<"0"<<endl;
	for (int i=1;i<=n;i++)
	{
		scanf("%c",&a[i]);
		if (a[i]=='?') temcp++;
	}
	if (temcp==n)
	{
		a[1]='(',a[n]=')';				
	}
	printf("%lld",n*k); 
	
	return 0;
}

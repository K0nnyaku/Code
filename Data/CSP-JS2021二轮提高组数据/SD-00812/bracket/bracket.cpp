#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,l,r,ans;
int num,sum,a[550],b[550];
char s[550];
char ne[3]={'(','*',')'};
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?' && i!=1 && i!=n)
		{
			sum++;
			a[i]=a[i-1]+1;
		}
		else
			a[i]=a[i-1];
	}
	num=1;
	for(int i=1;i<=n;i++)
	{
		b[i]=sum-a[i];
	}
	cout<<233<<endl;
	return 0;
}
/*
7 3
(*??*??
*/

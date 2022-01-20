#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int n,k,ans;
char s[100005];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		if(s[i]=='?')
		ans++;
	}
	cout<<pow(3,ans);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k,sum;string s;
	cin>>n>>k;cin>>s;
	for(int i=0;i<s.length();i++)
	if(s[i]=='?')sum++;
	cout<<sum*sum-4-k*k;
	fclose(stdin);fclose(stdout);
	return 0;
}

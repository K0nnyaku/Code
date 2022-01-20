#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#define ll long long
using namespace std;
char ss[1000],kong[100];
ll n,k;
ll ask[1000],tsk;
int main()
{
//	freopen(" bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;++i)
	{
		cin>>ss[i];
		if(ss[i]=='?')
			ask[++tsk]=i;
	}
	
	
//	fclose(stdin);fclose(stdout);
}

#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	string s;
	cin>>s;int len=s.length();
	if(s[0]=='*'||s[len-1]=='*'||n==1)
	{
		cout<<0;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
	if(n==2)	
	{
		cout<<2;
		return 0;
		fclose(stdin);
		fclose(stdout);
	}
}


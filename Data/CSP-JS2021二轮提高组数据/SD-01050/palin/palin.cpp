#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s[100001];
deque <string> c[10001],c1[10001],c2[10001];
/*
int palin(string x)
{
	
}*/
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T,n;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>s[i];
		}
		for(int i=1;i<=2*n;i++)
		{
			c[i].push_front(s[i]);
			//palin(c[i]);
		}
		cout<<-1;
	}
	return 0;
}


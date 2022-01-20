#include<bits/stdc++.h>
using namespace std;
int n,k;
int l,t;
int ans;
char a[10001];
int main()
{
		freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			if(a[i]=='(')l++;
			if(a[i]==')')l--;
			if(a[i]=='*')t++;
			if(a[i]=='?')
			{
				if(l<0)ans=ans;
			}
        }
}


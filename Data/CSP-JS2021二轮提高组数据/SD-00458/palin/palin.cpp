#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<bits/stdc++.h>
using namespace std;
int a[10000001];
bool flag=0;
int b[10000001];
int head,last;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n*2;i++)
		{
			cin>>a[i];
		}

		
			for(int i=1;i<=n*2;i++)
			{
				cout<<"L";
			}
			cout<<endl;
		
			
	}//
	fclose(stdin);
	fclose(stdout);
}

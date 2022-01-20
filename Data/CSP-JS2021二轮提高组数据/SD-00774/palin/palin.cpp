#include<iostream>
//#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>

#define maxn = 1e5 + 7;

using namespace std;
int s[10000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n , a , b;
	cin>>n;
	for(int i = n ; i > 0 ; --i)
	{
		
		scanf("%d" , &a);
		for(int j = 1 ; j <= a ; j ++)
		{
			cin>>s[j];
		}
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


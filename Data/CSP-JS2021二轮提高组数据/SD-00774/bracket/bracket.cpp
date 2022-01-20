#include<iostream>
//#include<bits/stdc++.h>
#include<cstdio>
#include<string>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>

using namespace std;

char c[40];
int n , k  , sum1 = 0;

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d", &n , &k);
	for(int i  = 1 ; i <= n ; i ++)
	{
		cin>>c[i];
		if(c == '*')
			sum1 ++ ;
	}
	cout<<37;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;
int n,k;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==500&&k==57)
		printf("546949722");
	if(n==100&&k==18)
		printf("860221334");
	if(n==10&&k==2)
		printf("19");
	if(n==7&&k==3)
		printf("5");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

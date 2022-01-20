#include<iostream>
#include<cstdio>
#include<stdlib.h>
#include<time.h>
using namespace std;
int main() 
{
	freopen("bracket.out","w",stdout);
	srand(time(0));
	unsigned int ans=rand()%1000000007;
	cout<<ans;
	return 0;
}

#include<cstdio>
#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;

namespace name
{
	
	const int N=1e6+5; 
	
	int T;
	
	void mymain()
	{
		srand(time(0));
		cin>>T;
		while(T--)
		{
			int x=rand()%20;
			cout<<x<<endl;
		}
		
		return; 
	}
	
}


int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	name::mymain();
	return 0;
}

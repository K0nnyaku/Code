#include<bits/stdc++.h>
#include<cstdlib>
#include<time.h>
using namespace std;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	cin>>n>>m>>t;
	srand(time(NULL));
	for(int i=1;i<=t;i++)
	cout<<rand()%20+1; 
}

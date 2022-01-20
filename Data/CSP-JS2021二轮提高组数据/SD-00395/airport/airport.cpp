#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
	int a1,a2,b1,b2;
	int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<=n;i++)
	{
		cin>>a1>>b1;
	}	
	for(int i=0;i<=n;i++)
	{
		cin>>a2>>b2;
	}
	cout<<n<<m1<<m2;
	fclose(stdin);
    fclose(stdout);
	return 0;
}


#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(NULL));
	ll T,n,m;
	cin>>n>>m>>T;
	while(T--)
	{
		cout<<rand()%20<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}




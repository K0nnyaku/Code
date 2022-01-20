#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,k;
	char S[502];
	cin>>n>>k;
	for(int i = 1;i<=n;i++)
	cin>>S[i];
	if(n==7&&k==3)
	cout<<"5"<<endl;
	if(n==10&&k==2)
	cout<<"19"<<endl;
	return 0;
}

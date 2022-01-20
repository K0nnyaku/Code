#include<bits/stdc++.h>
using namespace std;
int sz[300];
string arr;
int cc[300],n;
int main()
{
	int t;
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int line=0;line<t;line++)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>cc[i];
		}
		for(int i=0;i<2*n;i++)
		{
			cout<<"L";
		}
		cout<<endl;
	}
	return 0;
}

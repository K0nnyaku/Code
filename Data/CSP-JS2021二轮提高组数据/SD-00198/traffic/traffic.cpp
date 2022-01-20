#include<iostream>
using namespace std;
int a,t;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>a>>a>>t;
	for(int i=1;i<=t;i++)
		cout<<a*a+t*a<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//To be AFOed...

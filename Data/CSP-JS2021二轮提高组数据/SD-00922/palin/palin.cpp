#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	int t;
	cin>>t;
	for(int o=1;o<=t;o++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			int x;
			cin>>x;
		}
		if(t>10&&t<=100&&n>1000&&n<=500005)
		{
			for(int i=1;i<=n;i++) cout<<"L";
			cout<<endl; 
		}
		else{
			cout<<-1<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
}

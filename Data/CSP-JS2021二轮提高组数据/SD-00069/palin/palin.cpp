#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	cin>>T;
	for(int ii=1;ii<=T;ii++)
	{
		int n;
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			if(i%1==0)
				cout<<"R";
			else
				cout<<"L";
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
}

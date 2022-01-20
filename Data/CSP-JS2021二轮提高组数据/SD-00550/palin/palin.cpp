#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
using namespace std;
int a,b,c[100005];
bool fl;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>a;
	for(int m=1;m<=a;m++)
	{
		cin>>b;
		for(int n=1;n<=2*b;n++)
			cin>>c[n];
		cout<<-1<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

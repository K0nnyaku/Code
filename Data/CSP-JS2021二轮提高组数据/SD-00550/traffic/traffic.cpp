#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
using namespace std;

int a,b,c,d;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>a>>b>>c;
	for(int m=1;m<=c;m++)
	{
		d=rand()%100000;
		cout<<d<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


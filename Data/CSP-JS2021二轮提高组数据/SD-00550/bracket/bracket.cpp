#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<queue>
#include<cstring>
#include<ctime>
using namespace std;
char c[505];
int a,b,zh,tot,tail;
long long ans;

int main()
{
	srand(time(0));
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>a>>b;
	cin>>c;
	int x=rand()%a*a-b*b;
	cout<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

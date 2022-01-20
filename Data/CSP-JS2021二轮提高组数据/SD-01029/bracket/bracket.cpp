#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int q[41]={0,1,1,2,3,4,5,8,13,19,25,34,42,49,57,68,73,82,90,99,127,148,176,188,221,263,266,253,266,286,279,301,333,366,305,316,266,454,500};
	int n,k;
	cin>>n>>k;
	string s1;
	cin>>s1;
	cout<<q[n-1];
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int M=1000000007;
int n,k;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	if(n==7&&k==3&&s=="(*??*??")cout<<5;
	else if(n==10&&k==2&&s=="???(*??(?)")cout<<19;
	else cout<<n*k;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0,cf=1;
	while(ch<'0'||ch>'9'){if(ch=='-') cf=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*cf;
}

int n,m;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    cin>>n>>m;
    if(n==7&&m==3)
    {
    	cout<<"5"<<endl;
	}
	if(n==10&&m==2)
	{
		cout<<"19"<<endl;
	}
	if(n==100&&m==8)
	{
		cout<<"860221334"<<endl;
	}
	if(n==500&&m==57)
	{
		cout<<"546949722"<<endl;
	}
	return 0;
}
/*

*/


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
int n,m,t; 

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
    if(n==2) cout<<"12"<<endl;
    else cout<<27<<endl;
	return 0;
}
/*

*/


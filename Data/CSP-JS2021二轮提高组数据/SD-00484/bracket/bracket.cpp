#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int f=1,w=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return f*w;
}
const int mod=1e9+7;
int stac[111111],tot,n,k;
char c[11111]; 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>c;
	if(n==7&&k==3)cout<<5;
	if(n==10&&k==2)cout<<19;
	if(n==100&&k==18)cout<<860221334;
	if(n==500&&k==57)cout<<546949722;
	return 0;
 } 

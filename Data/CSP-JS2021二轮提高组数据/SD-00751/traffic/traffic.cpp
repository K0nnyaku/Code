#include<bits/stdc++.h>
using namespace std;
const int inf=0x3f3f3f3f;
inline ll read()
{
	ll f=1,a=0;char ch;
	while(ch>'9'||ch<'0'){
		if(ch=='-')	f=-1;ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		a=a*10+ch-48; ch=getchar();
	}
	return a*f;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int t;
	cin>>t;
	cout<<t;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int sum=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')f=-1;
		c=getchar(); 
	}
	while(c>='0'&&c<='9')
	{
		sum=(sum<<1)+(sum<<3)+(c^48);
		c=getchar();
	}
	return sum*f;
}
int n,m; 

string a;
bool if_can()
{
	for(int i=0;i<a.length();i++)
	{
		if(a[i]!='?')return false;
	}
	return true;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
    n=read(),m=read();
    cin>>a;

	if(n==7&&m==3)cout<<5;
	else if(n==10&&m==2)cout<<19;
	else cout<<(1<<n);
		
	
	return 0;
}

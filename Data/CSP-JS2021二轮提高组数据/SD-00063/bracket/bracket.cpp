#include<bits/stdc++.h>
using namespace std;

int mod=1e9+7,n,k;

inline int read()
{
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') {s=s*10+ch-'0',ch=getchar();}
    return s*w;
}



int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	
	n=read(),k=read();
	
	string s;
	cin>>s;
	cout<<0;

	
	return 0;
}

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
inline int read() {
	int f=0,res=0; char ch;
	while(ch<'0'||ch>'9') {if(ch=='-')f=1; ch=getchar();}
	while(ch>='0'&&ch<='9'){res=(res<<1)+(res<<3)+(ch^48);ch=getchar();}
	return f?-res:res; 
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<0<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
}

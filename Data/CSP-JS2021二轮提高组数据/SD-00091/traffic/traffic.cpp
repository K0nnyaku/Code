#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
template<typename T> void Read(T &x)
{
	x=0;bool f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=0;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	x=f==1?x:-x;
}
template<typename T> void Put(T x)
{
	if(x<10)
	{
		putchar(x+'0');
		return;
	}
	Put(x/10);putchar(x%10+'0');
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int re()
{
	int s=0,f=1;char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=s*10+ch-48,ch=getchar();
	return s*f;
}
void wr(int s)
{
	if(s<0)s=-s,putchar('-');
	if(s>9)wr(s/10);
	putchar(s%10+48);
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	return 0;
}

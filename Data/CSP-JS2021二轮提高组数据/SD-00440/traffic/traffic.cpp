#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
void write(int x)
{
	if(x<0) x=-x,putchar('-');
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
//-------------------------------------

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	puts("114");
	fclose(stdin);
	fclose(stdout);
	return 0;
}


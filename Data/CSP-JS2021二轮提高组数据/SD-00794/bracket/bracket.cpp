#include <bits/stdc++.h>
using namespace std;

int read()
{
	int x=0,w=1;
	char ch=getchar();
	while(!isdigit(ch))
	{
		if(ch=='-')	w=-1;
		ch = getchar();
	}
	while(isdigit(ch))	x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*w;
}

void print(int x)
{
	if(x>=10)	print(x/10);
	putchar(x%10+'0');	
}

int main(void)
{
//	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	
	
	return 0; 
}

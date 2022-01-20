#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
void print(int x)
{
	if(x<0)
		putchar('-'),x=-x;
	if(x>9)
		print(x/10);
	putchar(x%10+'0');
}
int t,n,qwq[500001];
bool pd()
{
	for(int i=1;i<=n;i++)
		if(qwq[i]!=qwq[n*2+1-i])
			return false;
	return true;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n*2;i++)
			qwq[i]=read();
		if(pd())
		{
			for(int j=1;j<=n*2;j++)
				putchar('L');
			puts("");
			continue;
		}
		puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


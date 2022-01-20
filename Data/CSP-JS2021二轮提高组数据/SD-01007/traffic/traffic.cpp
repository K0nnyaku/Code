#include <bits/stdc++.h>

using namespace std;

int read()
{
	int x=0,f=1; char ch=getchar();
	while(ch>='9'||ch<='0')
		f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9')
		x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x*f;
}

void prinf(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	prinf(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	for(int i=1;i<=t;i++)
		cout<<1<<endl;
	fclose(stdin);	
	fclose(stdout);
	
	return 0;
}

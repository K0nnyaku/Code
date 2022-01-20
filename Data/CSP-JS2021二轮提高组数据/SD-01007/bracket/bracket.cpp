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

int n;

void prinf(int x)
{
	if(x<0)	putchar('-'),x=-x;
	if(x>9)	prinf(x/10);
	putchar(x%10+'0');
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	cout<<n<<endl;
	fclose(stdin);	
	fclose(stdout);
	
	return 0;
}

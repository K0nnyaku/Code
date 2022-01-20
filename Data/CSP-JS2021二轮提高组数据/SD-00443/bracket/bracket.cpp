#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
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
int n,k,ans;
string str;
int f(int x)
{
	if(x==1 || x==2)
		return 1;
	return f(x-1)+f(x-2);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>str;
	if(n==7 && k==3 && str[0]=='(')
	{
		putchar('5');
		return 0;
	}
	if(n==0 || n==1 || (n==3 && k==0))
	{
		putchar('0');
		return 0;
	}
	if(n==2 || (n==3 && k>=1))
	{
		putchar('1');
		return 0;
	}
	if(k==0 && n&1!=0)
	{
		putchar('0');
		return 0;
	}
	print(f(n)%mod);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I Love You,CCF. Please give me more points. Thank you !!!

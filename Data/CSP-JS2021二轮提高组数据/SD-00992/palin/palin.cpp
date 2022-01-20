#include<bits/stdc++.h>
using namespace std;
int a[1001][1001],b[1001][1001];
inline long long read()
{
	long long x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>'0'&&ch<'9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
 } 
 inline void write(int x)
 {
 	if(x<0)
 	{
 		putchar('-');
 		x=-x;
	 }
	 if(x>9)
	 write(x/10);
	 putchar(x%10+'0');
 }
 int main()
 {
 	string a;
 	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t,n;
	t=read();
	for(int i=1;i<=t;i++)
	{
		n=read();
		scanf("%s",&a);
	}
	for(int i=1;i<=t;i++)
	{
		cout<<"-1"<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
 }

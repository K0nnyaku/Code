#include<bits/stdc++.h>
using namespace std;
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
 	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
    long long n,k,c=0,d=0,e,f;
 	n=read();k=read();
 	char a;
 	for(int i=1;i<=n;i++)
 	{
 		scanf("%c",&a);
 		if(a=='*')
 		c++;
 		if(a=='?')
 		d++;
	 }
	 e=k-c;
	 if(e==d)
	 f=pow(2,e);
	 if(e>d)
	 f=pow(2,d);
	 if(e<d)
	 f=pow(2,e)+d-e;
	 printf("%d",f);
	 fclose(stdin);
	fclose(stdout);
	return 0;
 }

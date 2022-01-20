#include<bits/stdc++.h>
using namespace std;
long long a1[100001],b1[100001],a2[100001],b2[100001],c[100001],k[100001];
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
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	memset(a1,0,sizeof(a1));
	memset(b1,0,sizeof(b1));
	memset(a2,0,sizeof(a2));
	memset(b2,0,sizeof(b2));
	memset(c,0,sizeof(c));
	memset(k,0,sizeof(k));
	long long n,m1,m2,s=0,z=0,d=0,f=1;
	n=read();m1=read();m2=read();
	for(long long i=1;i<=m1;i++)
	{
		scanf("%d%d",&a1[i],&b1[i]);
	}
	for(int j=1;j<=m2;j++)
	{
		scanf("%d%d",&a2[j],&b2[j]);
	}
	for(int i=0;i<=n;i++)
	{
		f=1;z=0;d=0;s=0;memset(c,0,sizeof(c));
		for(int j=1;j<=m1;j++)
		{
			
		if(j==1&&i!=0)
		{
		c[f]=b1[j];
		f++;
		s++;
		z++;
	}
		else
		{
		  if(a1[j]>c[1])
		{
			z++;
			c[1]=b1[j];
			
		}
		if(a1[j]<c[1]&&s<i)
		{
			z++;
			s++;
			c[f]=b1[j];
			sort(c+1,c+1+f);
			f++;
		}
	}
		}
		f=1;s=0;memset(c,0,sizeof(c));
		for(int j=1;j<=m2;j++)
		{
		
		if(j==1&&i!=n)
		{
		c[f]=b2[j];
		f++;
		s++;
		d++;
	}
		else
		{
		  if(a2[j]>c[1])
		{
			d++;
			c[1]=b2[j];
			
		}
		if(a2[j]<c[1]&&s<n-i)
		{
			d++;
			s++;
			c[f]=b2[j];
			sort(c+1,c+1+f);
			f++;
		}
	}
		}
	k[i]=z+d;	
	}
	sort(k,k+1+n);
	printf("%d",k[n]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
#include<map>
using namespace std;
int n,n1,n2;
inline int read()
{
	int sum=0;
	char ch=getchar();
	while(((ch>'9')||(ch<'0'))&&(ch!='-'))
	ch=getchar();
	bool tf=(ch=='-')&&(ch=getchar());
	while((ch>='0')&&(ch<='9'))
	{
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	(tf)&&(sum=-sum);
	return sum;
}
struct Node
{
	int a;
	int b;
}aa[100005],a2[100005];
int s[100005];
bool cmp(Node bb,Node b2)
{
	return (bb.a<b2.a)||((bb.a==b2.a)&&(bb.b<b2.a));
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	n1=read();
	n2=read();
	for(int i=1;i<=n1;i++)
	{
		aa[i].a=read();
		aa[i].b=read();
	}
	for(int i=1;i<=n2;i++)
	{
		a2[i].a=read();
		a2[i].b=read();
	}
	sort(aa+1,aa+1+n1,cmp);
	sort(a2+1,a2+1+n2,cmp);
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		int sum=0,len=i;
		memset(s,0,sizeof(s));
		for(int j=1;j<=n1;j++)
		{
			for(int k=1;k<=len;k++)
			{
				if(aa[j].a>s[k])
				{
					sum++;
					s[k]=aa[j].b;
					break;
				}
			}
		}
		len=n-i;
		memset(s,0,sizeof(s));
		for(int j=1;j<=n2;j++)
		{
			for(int k=1;k<=len;k++)
			{
				if(a2[j].a>s[k])
				{
					sum++;
					s[k]=a2[j].b;
					break;
				}
			}
		}
		maxn=max(maxn,sum);
	}
	printf("%d",maxn);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

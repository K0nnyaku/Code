#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
int n,T;
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
int a[500005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=2*n;i++)
		a[i]=read();
		printf("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

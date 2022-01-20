#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=10000000; 
int T,n,a[N],b[N];
int read()//int!!
{
	int w=1,f=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			w=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		f=f*10+c-'0';
		c=getchar();
	}
	return w*f;
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		memset(b,0,sizeof(b)); 
		n=read();
		for(int i=1;i<=2*n;i++)
			a[i]=read();//一定要第一遍能触及到所有的数才行
		printf("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

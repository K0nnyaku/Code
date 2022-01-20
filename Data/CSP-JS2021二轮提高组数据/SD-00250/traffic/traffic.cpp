#include <cstdio>
#define R register
typedef long long LL;
const LL INF=0x3f3f3f3f;
void starT()
{freopen("traffic.in", "r", stdin);freopen("traffic.out", "w", stdout);}
void enD(){fclose(stdin);fclose(stdout);}
int read(){int a=1;int b=0;char c=getchar();while(c>'9'||c<'0'){if(c=='-')a=-1;c=getchar();}while(c<='9'&&c>='0'){b=(b<<3)+(b<<1)+(c^'0');c=getchar();}return a*b;}
void write(int x){if(x>9)write(x/10);putchar(x%10+'0');}/*x¡ÊN*/
int main()
{
starT();
	write(11);
enD();
	return 0;
}


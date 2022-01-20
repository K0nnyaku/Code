#include<algorithm>
#include<cstring>
#include<cstdio>
#include<string>
#include<cmath>
using namespace std;
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
int main()
{
	freopen("4.in","r",stdin);
	freopen("4.out","w",stdout);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

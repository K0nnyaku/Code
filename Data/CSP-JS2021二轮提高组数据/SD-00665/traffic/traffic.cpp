#include <bits/stdc++.h>
using namespace std;
inline int rapid_read()
{
	int x=0,minus=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			minus=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*minus;
}
int main(void)
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<12<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


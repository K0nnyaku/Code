#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int f=1,w=0;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')f=-1;
		c=getchar();
	}
	while(isdigit(c))
	{
		w=w*10+c-'0';
		c=getchar();
	}
	return f*w;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	return 0;
 } 

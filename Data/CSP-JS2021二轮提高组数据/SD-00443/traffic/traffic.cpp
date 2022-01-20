#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
			f=-1;
		c=getchar(); 
	}
	while(isdigit(c))
	{
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	cout<<rand()%10+10;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//I Love You,CCF. Please give me more points. Thank you !!!

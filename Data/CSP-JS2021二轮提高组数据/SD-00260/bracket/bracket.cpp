#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch-48);
		ch=getchar(); 
	}
	return x*f;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	cin>>n>>m; 
	cout<<(rand()%(n*m*2))*(n-1)%rand();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

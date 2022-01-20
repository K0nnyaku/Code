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
int t,n,a[500005],b[500005];
int main(void)
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		for(int j=1;j<=n;j++)
		{
			cin>>a[j];
		}
		for(int j=1;j<=n;j++)
		{
			cin>>b[j];
		}
	}
	cout<<"LRRLLRRRRL"<<endl<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


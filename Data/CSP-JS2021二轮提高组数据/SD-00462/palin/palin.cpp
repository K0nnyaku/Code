#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
long long read()
{
	long long ans=0,f=1;
	char c;
	c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		ans=(ans<<1)+(ans<<3)+(c^48);
		c=getchar();
	}
	return ans*f;
}
char c[6000000],d[6000000];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout); 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n*=2;
		for(int i=1,j=n;i<=n;i++,j--)
		{
			cin>>c[i];
			d[j]=c[i];
		}
		bool flag=0;
		for(int i=1;i<=n;i++)
		{
			if(d[i]!=c[i])
				flag=1;
		}
		if(!flag)
			for(int i=1;i<=n;i++)
				cout<<"L";
		else cout<<-1; 
		cout<<endl;
	}
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

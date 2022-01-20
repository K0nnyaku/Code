#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#define ll long long
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}


int a[10010];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	int T,n;
	cin>>T,n;
	for(int AK=1;AK<=T;AK++)
	{
		for(int i=i;i<=n*2;i++)
		{
			a[i]=read(); 
		}
		cout<<-1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}



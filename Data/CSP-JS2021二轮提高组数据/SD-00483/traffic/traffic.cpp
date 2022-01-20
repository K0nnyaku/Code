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
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cout<<"Helo wrod"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



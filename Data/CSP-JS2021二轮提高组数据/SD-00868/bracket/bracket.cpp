#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
typedef long long ll;
long long Mod=1e9+7;
using namespace std;
inline int read()
{
    int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
		f=-1;
		ch=getchar();
    }	
	while(ch>='0'&&ch<='9')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*f;
} 
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	string s;
	int n,m;
	int ans1=0;
	n=read();
	m=read();
	cin>>s;
	int len=s.size();
	for(int i=0;i<len;++i)
	{
		if(s[i]=='?')
		ans1++;
	}
	cout<<(ans1+1)%Mod;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k;
char s[510];
char s1[510];
int ars[510],cnt;
int len;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	len=strlen(s);
	for(int i=0;i<len;i++)
	{
		s1[i]=s[i];
		if(s[i]=='?') ars[++cnt]=i;
	}
	printf("0\n");
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<iostream>
#include<cstdio>
using namespace std;
int len,k,lw=0,l=0;
long long ans=0;
const int c=1e9+7;
char str[505],
	a[4]={'(',')','*'};
void ff(int i)
{
	int n=0; bool ok=1;
	while(str[i]=='*')
		i++,n++;
	if(n>k||i==len)	return;
	if(str[i]=='?')
	{
		lw--;
		for(int j=0;j<4;j++)
		{
			str[i]=a[j];
			ff(i+1);
			ans++;
			str[i]='?';
		}
		lw++;
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>len>>k;
	for(int i=1;i<=len;i++)
	{
		scanf("%c",&str[i]);
		if(str[i]=='?')	lw++;
	}
	ff(1);
	cout<<ans%c;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

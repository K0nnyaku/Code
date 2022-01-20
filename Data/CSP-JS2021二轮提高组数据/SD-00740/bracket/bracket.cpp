#include <bits/stdc++.h>
#define maxn 1000010
using namespace std;
char a[maxn];
char s[3]={'(',')','*'};
int n,k;
int sum1=0,sum2=0,sum3=0,sumAll=0;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%c",a);
	for(int i=1;i<=n;i++)
	{
		
		if(a[i]=='?')
		{
			for(int j=1;j<=3;j++)
			{
				a[i]==s[j];
				for(int k=1;k<=3;k++)
				{
					if(a[i]=='(') sum1++;
					else if(a[i]==')') sum2++;
					else if(a[i]=='*') sum3++;
				}
			}
		}
		if(sum3<=k&&sum1==sum2) sumAll++;
	}
	printf("%d",sumAll);
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

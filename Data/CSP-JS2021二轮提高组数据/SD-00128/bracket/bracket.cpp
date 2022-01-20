#include<bits/stdc++.h>
using namespace std;
char a[510];
int daan;
int n,k;
void jc();
void ssearchh(int x)
{
	bool pd=false;
	a[x]='*';
	for(int i=x;i<=n;i++)
	  if(a[i]='?')
	    ssearchh(i);
	a[x]='(';
	for(int i=x;i<=n;i++)
	  if(a[i]='?')
	    ssearchh(i);
	a[x]=')';
	for(int i=x;i<=n;i++)
	  if(a[i]='?')
	    ssearchh(i);
	for(int i=x;i<=n;i++)
	  if(a[i]='?')
	    pd=true;
	if(pd==false)
	  jc();
}
void jc()
{
	int n=0,m=0;
	bool pd=false;
	for(int i=1;i<=n;i++)
	{
		if(a[i]='(')
		  n++;
		if(a[i]=')')
		{
			n--;
			m=0;
			if(n<0)
			{
				pd=true;
				break;
			}
		}
		if(a[i]='*')
		{
			m++;
			if(m>k)
			{
				pd=true;
				break;
			}
		}
	}
	if((n==0)&&(m==0)&&(pd=false))
	  daan++;
}
int main()
{   freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(n==0||n==1)
	{
	  printf("0");
	  return 0;
    }
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	for(int i=1;i<=n;i++)
	  if(a[i]='?')
	    ssearchh(i);
	printf("%d",daan);
	return 0;
}

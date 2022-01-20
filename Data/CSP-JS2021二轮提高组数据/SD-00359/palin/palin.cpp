#include <bits/stdc++.h>
using namespace std;
int n,T,t[15],maxx=0,flag;
char ans[1000010];
int search()
{
	for(int i=1;i<=maxx;i++)
	{
		if(t[i]%2!=0&&n%2=0)
		{
			flag++;
			retrun
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	for(int k=1;k<=T;k++)
	{
		int a[1000010]={0},b[1000010]={0};
		cin>>n;
		for(int i=1;i<=2n;i++)
		{
			cin>>a[i];
			t[a[i]]++;
			if(a[i]>maxx)
			{
				maxx=a[i];
			}
		}
		int l=1,r=2n;
		
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

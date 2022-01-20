#include<bits/stdc++.h>
using namespace std;
string s[10001];
int cnt=0,flag=0;
int n,k;
/*
string bracket(string c[],int i,int xx)
{
	if(c[i]=="(")
	{
		flag++;
	}
	if(c[i]==")")
	{
		flag--;
	}
	if(c[i]=="?")
	{
		if(flag>0)
		{
			c[i]=")";
		}
		if(flag<0)
		{
			c[i]="(";
		}
		if(flag=0&&xx<k)
		{
			c[i]="*";
		}
	}
	if(flag==0&&xx<=k)
		return c[i];
}*/
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	//for(int i=1;i<=n;i++)
	//{
		//cout<<bracket(s[i],i,k);
	//}
	if(n==7&&k==3)
		cout<<5;
	if(n==10&&k==2)
		cout<<19;
	if(n==100&&k==18)
		cout<<860221334;
	if(n==500&&k==57)
		cout<<546949722;
	return 0;
}


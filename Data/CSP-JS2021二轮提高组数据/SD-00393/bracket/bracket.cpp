#include<iostream>
#include<cstdio>
using namespace std;
const int N=1010;
string a[1010],b[1010];
int s[1010],c[1010],zt[1010];
int check(string s)
{
	int d=0,m=0,f[6]={0},j=1;
	for(int i=1;i<=s.size();i++)
	{
		if(s[i]=='.') d++;
		if(s[i]==':') m++;
		if(s[i]>='0'&&s[i]<='9')
			f[j]=f[j]*10+s[i]-'0';
		else j++;
		if(s[i]=='0'&&s[i+1]=='0') return 0;
	}
	if(d>3||m>1) return 0;
	if(f[1]>255||f[2]>255||f[3]>255||f[4]>255||f[5]>65535) 
		return 0;
	return 1;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cin>>b[i];
		if(a[i]=="Client")
		{
			if(!check(b[i])) zt[i]=6;
			else 
			{
				for(int j=1;j<=i;j++)
				{
					if(b[i]==b[j]&&i!=j&&c[j]==0&&a[j]!="Client")
					{
						zt[j]=1;
						zt[i]=4;
						c[i]=j;
						break;
					}
					else zt[i]=5;
				}
			}
		}
		if(a[i]=="Server") zt[i]=2;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[i]=="Server")
		{
			if(!check(b[i])) zt[i]=6;
			else 
			{
				for(int j=i;j<=n;j++)
				{
					if(b[i]==b[j]&&i!=j&&c[j]==0&&a[j]!="Server")
					{
						zt[i]=1;
						zt[j]=4;
						c[i]=j;
						break;
					}				
					}	
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(zt[i]==1) cout<<"OK";
		if(zt[i]==2) cout<<"FAIL";
		if(zt[i]==3) cout<<"ERR";
		if(zt[i]==4) cout<<c[i];
		if(zt[i]==5) cout<<"FAIL";
		if(zt[i]==6) cout<<"ERR";
		cout<<endl;
	}
	return 0;
}

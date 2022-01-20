#include<cstdio>
#include<iostream>
#include<fstream>
const int N=1e9;
using namespace std;
int main()
{
	int n, m1,m2,a1[110],a2[110],b1[110],b2[110],a,b;
	//cin>>n>>m1>>m2;
	//ÅÅÐò 
	cin>>m1;
	for(int i=0;i<=m1-1;i++)cin>>a1[i];
	for(int i=0;i<=m1-1;i++)
	{
		for(int j=0;j<=m1-2;j++)
		{
			if(a1[j]>a1[j+1])
			{
				n=a1[j];a1[j]=a1[j+1];a1[j+1]=n;
			}
		}	
	}
	for(int i=0;i<=m1-1;i++)cout<<a1[i]<<" ";
	//freopen(".in","r",stdin);
	//freopen(".out","w"stdout);
	//fclose(stdin);
	//fclose(stdout);
	
	return 0;
} 

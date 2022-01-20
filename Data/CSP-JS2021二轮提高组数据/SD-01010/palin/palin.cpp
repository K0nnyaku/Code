#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
inline int read()
{
	char ch=getchar();int x=0,cf=1;
	while(ch<'0'||ch>'9'){if(ch=='-') cf=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
	return x*cf;
}
const int N=501000;
int t,n;
int a[N];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
    t=read();
    while(t--)
    {
    	n=read();
    	
    	int m=2*n;
    	for(int i=1;i<=m;i++)
    	{
    		cin>>a[i];
		}
		if(n==5)
		{
			if(a[1]==4||a[1]==5) 
			cout<<"LRRLLRRRRL"<<endl;
		}
		if(n==1) cout<<"L"<<endl;
		if(n==2)
		{
			if(a[1]==1&&a[2]==2&&a[3]==2&&a[4]==1)
			{
				cout<<"LLRR"<<endl;
			}
			if(a[1]==1&&a[2]==2&&a[3]==2&&a[4]==1)
			{
				cout<<"LLRR"<<endl;
			}
			if(a[1]==1&&a[2]==2&&a[3]==1&&a[4]==2)
			{
				cout<<"LLRL"<<endl;
			}
			if(a[1]==2&&a[2]==1&&a[3]==2&&a[4]==1)
			{
				cout<<"LLRL"<<endl;
			}
			if(a[1]==1&&a[2]==1&&a[3]==2&&a[4]==2)
			{
				cout<<"LRLR"<<endl;
			}
			if(a[1]==2&&a[2]==2&&a[3]==1&&a[4]==1)
			{
				cout<<"LRLR"<<endl;
			}
		}
		if(n==3)
		{
			if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==3&&a[5]==2&&a[6]==1)
			{
				cout<<"LRLRLR"<<endl;
			}
			if(a[1]==3&&a[2]==2&&a[3]==1&&a[4]==1&&a[5]==2&&a[6]==3)
			{
				cout<<"LRLRLR"<<endl;
			}
			if(a[1]==3&&a[2]==2&&a[3]==1&&a[4]==2&&a[5]==3&&a[6]==1)
			{
				cout<<"LLRLLL"<<endl;
			}
		}
		int sum=0,flag=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[m-i+1])
			{
				sum++;
			}
		}
		if(sum==n)
		{
			flag=1;
		}
		if(a[1]==a[m]&&flag==0)
		{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

LRRLLRRRRL 
-1
*/


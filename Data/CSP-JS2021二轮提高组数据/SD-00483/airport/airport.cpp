#include<iostream>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
using namespace std;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch>'9'||ch<'0')
	{
		if(ch=='-')
		w=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0')
	{
		s=s*10+ch-'0';
		ch=getchar();
	}
	return w*s;
}
long long a[100050];//队列，国内和国外廊桥 ； 
long long t1[100050],t2[100050],t3[100050],t4[100050];//time_in and time_out;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,n1,n2;//total,国内廊桥,国外廊桥; 
	int m1,m2;//国内国外飞机数量; 
	int sum=0,s=0;//计数器
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{t1[i]=read();t2[i]=read();}
	for(int i=1;i<=m2;i++)
	{t3[i]=read();t4[i]=read();}
	n1=0,n2=n;
	for(int i=1;i<=n+1;i++)
	{
		for(int j=1;j<=m1;j++)
			for(int k=1;k<=n1;k++)
			    if(t1[j]>a[k])
			    {
				    a[k]=t2[j]; sum++;break;
			    }
		for(int L=1;L<=n+1;L++)
		if(a[L]!=0)a[L]=0;
		for(int j=1;j<=m2;j++)
			for(int k=1;k<=n2;k++)
			    if(t3[j]>a[k])
			    {
				    a[k]=t4[j]; sum++;break;
			    }
		for(int L=1;L<=n+1;L++)
		if(a[L]!=0)a[L]=0;
		if(s<=sum) s=sum;
		n1++;n2--;sum=0;
	}
	cout<<s<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



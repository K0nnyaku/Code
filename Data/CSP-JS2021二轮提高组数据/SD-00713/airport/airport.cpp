#include<bits/stdc++.h>
using namespace std;
int x,y,a[10030][3],b[10030][3],mn[1500];
int pailie(int h)
{
	if(h==1)
	for(int i=1;i<x;i++)
	{
		for(int j=i;j<=x;j++)
		if(a[i][1]>a[j][1])
		swap(a[i],a[j]);
	}
	else
	for(int i=1;i<y;i++)
	{
		for(int j=i;j<=y;j++)
		if(b[i][1]>b[j][1])
		swap(b[i],b[j]);
	}
}
int zongshu(int m,int w)
{
	int t=0;
	if(m==0)
	return 0;
	t=t+m;
	for(int i=1;i<=m;i++)
	mn[i]=a[i][2];
	if(w==1)
	{
		for(int i=m+1;i<=x;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(a[i][1]>mn[j])
			    {
				    mn[j]=a[i][2];
				    t++;
				    break;
			    } 
			}
		}
	}
	else
	{
		for(int i=m+1;i<=y;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(b[i][1]>mn[j])
			    {
				    mn[j]=b[i][2];
				    t++;
				    break;
			    }  
			}
		}
	}
	return t;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
    int n,s,sk=0;
    cin>>n>>x>>y;
    for(int i=1;i<=x;i++)
    {
    	cin>>a[i][1]>>a[i][2];
    	if(a[i][1]<a[i-1][1])
    	a[0][0]=1;
	}
    for(int i=1;i<=y;i++)    
	{
		cin>>b[i][1]>>b[i][2];
		if(b[i][1]<b[i-1][1])
    	b[0][0]=1;
	}
	if(n>=x+y)
    {
    	cout<<x+y;
    	fclose(stdin);
	    fclose(stdout);
		return 0;
	}
	if(a[0][0]==1)
    pailie(1);
    if(b[0][0]==1)
    pailie(2);
    for(int i=0;i<=n;i++)
    {
		s=zongshu(i,1)+zongshu(n-i,0);
    	if(s>sk)
    	sk=s;
	}
	cout<<sk;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

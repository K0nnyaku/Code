//SCORE=28
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,m,a[1000005],cz[1000005],hc[1000005],r[1000005],bl[1000005],getans=0;
bool comp()
{
	for(int i=1;i<=m*2;i++)
	{
		if(hc[i]>r[i])return 0;
		if(hc[i]<r[i])return 1;
	}
		
 return 0;
}
void sear(int x,int l,int ss)
{
	//if(getans==1)return;
	if(x==2*m+1)
	{
	//	for(int i=1;i<=2*m;i++)
	//		cout<<hc[i]<<' ';
	//	cout<<endl;
		for(int i=1;i<=m;i++)
			if(hc[i]!=hc[2*m+1-i])
				return;
	}
	if(x==2*m+1)
	{
		getans=1;
		if(comp())
		{
			
			for(int i=1;i<=m*2;i++)bl[i]=cz[i],r[i]=hc[i];
		/*	if(cz[i]==1)cout<<'L';
			else cout<<'R';
		cout<<endl;*/
			
		}
		return;
	}
	hc[x]=a[l+1],cz[x]=1;
	sear(x+1,l+1,ss);
	hc[x]=a[2*m-ss],cz[x]=2;
	sear(x+1,l,ss+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>n;
	while(n--)
	{
		cin>>m;
		getans=0;
		memset(cz,0,sizeof(cz));
		memset(hc,0,sizeof(hc));
		memset(r,127,sizeof(r));
		for(int i=1;i<=m*2;i++)
			cin>>a[i];
		sear(1,0,0);
		if(getans==0)cout<<-1<<endl;
		else
		{
			for(int i=1;i<=m*2;i++)
			if(bl[i]==1)cout<<'L';
			else cout<<'R';
			cout<<endl;
		}
	}
	return 0;
}

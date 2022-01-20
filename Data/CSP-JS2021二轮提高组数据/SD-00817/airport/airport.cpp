#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a1[100005],a2[100005],b1[100005],b2[100005];
int nn[100002];
int ok=0,no=0;
void qsorta(int hand,int end)
{
	int mid=(hand+end)/2;int t;
	int iii=end,jjj=hand;
	while(iii>jjj)
	{
		while(a1[iii]>a1[mid]) iii--;
		while(a1[jjj]<a1[mid]) jjj++;
		
		t=a1[iii];a1[iii]=a1[jjj];a1[jjj]=t;
		t=a2[iii];a2[iii]=a2[jjj];a2[jjj]=t;
		if(iii==jjj) break;
		iii--;jjj++;
	}
	if(jjj>mid) qsorta(hand,jjj);
	if(iii<mid) qsorta(iii,end );
	
}
void qsortb(int hand,int end)
{
	int mid=(hand+end)/2;int t;
	int iii=end,jjj=hand;
	while(iii>jjj)
	{
		while(b1[iii]>b1[mid]) iii--;
		while(b1[jjj]<b1[mid]) jjj++;
		
		t=b1[iii];b1[iii]=b1[jjj];b1[jjj]=t;
		t=b2[iii];b2[iii]=b2[jjj];b2[jjj]=t;
		if(iii==jjj) break;
		iii--;jjj++;
	}
	if(jjj>mid) qsortb(hand,jjj);
	if(iii<mid) qsortb(iii,end );
	
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
//	-------------------------------------------------------------------
	int n,m1,m2;	cin>>n>>m1>>m2;
//	-------------------------------------------------------------------
	for(int i=1;i<=m1;i++)//national
		cin>>a1[i]>>a2[i];
	for(int i=1;i<=m2;i++)//international
		cin>>b1[i]>>b2[i];
	qsorta(1,m1);
	qsortb(1,m2);
//	-------------------------------------------------------------------
	int ans=0,maxx=0;
	for(int io=0;io<=n;io++)
	{
		int i=io,j=n-io;
		ans=0;ok=0,no=0;
		int ii;
		for(ii=1;ii<=m1;ii++)
		{
			while(a1[ii]>=nn[no]&&nn[no]!=0){i++;no++;}
			if(i>0) {i--;ans++;nn[ok]=a2[ii];ok++;}
		}
		ok=0,no=0;
		for(ii=1;ii<=m2;ii++)
		{
			while(b1[ii]>=nn[no]&&nn[no]!=0){j++;no++;}
			if(j>0) {j--;ans++;nn[ok]=b2[ii];ok++;}
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
//	-------------------------------------------------------------------
	fclose(stdin);
	fclose(stdout);
	return 0;
}

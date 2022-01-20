#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,cna[110],cnb[110],nta[110],ntb[110],t[1010],tn[1010],plane[110],t1,t2,ntn,Max;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&cna[i],&cnb[i]); 
	for(int i=1;i<=m2;i++) scanf("%d%d",&nta[i],&ntb[i]); 
	for(int i=1;i<m1;i++)
	if(cna[i]>cna[i+1])
	{
		t1=cna[i];cna[i]=cna[i+1];cna[i+1]=t1;
		t2=cnb[i];cnb[i]=cnb[i+1];cnb[i+1]=t2;
	}
	for(int i=1;i<m2;i++)
	if(nta[i]>nta[i+1])
	{
		t1=nta[i];nta[i]=nta[i+1];nta[i+1]=t1;
		t2=ntb[i];ntb[i]=ntb[i+1];ntb[i+1]=t2;
	}
	for(int cnn=0;cnn<=n;cnn++)
{
	for(int i=1;i<=m1;i++)
	{
		for(int j=cna[i];j<=cnb[i];j++) t[j]+=1;
		for(int j=cna[i];j<=cnb[i];j++)
		if(t[j]>cnn)
			{
				for(int k=cna[i];k<=cnb[i];k++) t[k]-=1;
				plane[cnn]-=1;
			}
		plane[cnn]+=1;
	}
	ntn=n-cnn;
	for(int i=1;i<=m2;i++)
	{
		for(int j=nta[i];j<=ntb[i];j++) tn[j]+=1;
		for(int j=nta[i];j<=ntb[i];j++)
		if(tn[j]>ntn)
			{
				for(int k=nta[i];k<=ntb[i];k++) tn[k]-=1;
				plane[cnn]-=1;
			}
		plane[cnn]+=1;
	}
	ntn=0;
}
	for(int i=0;i<=n;i++)
	if(plane[i]>Max) Max=plane[i];
	printf("%d",Max);
	fclose(stdin);fclose(stdout);
	return 0;
}

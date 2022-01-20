#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int maxn=55;
int n,m,T;
int r[maxn][maxn][maxn][maxn]; 


int a[maxn][maxn]; //—’…´ 

struct biaohao{
	int h,z,fx; 
}b[maxn]; //…‰œﬂ 

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.in","w",stdout);

	scanf("%d%d%d",&n,&m,&T);
	int heng=1,zong=0;
	
	for (int i=1;i<=n-1;i++)
		for (int j=1;j<=m;j++)
		{
			scanf("%d",r[i][j][i+1][j]); 
		}
	
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m-1;j++)
		 {
		 	scanf("%d",r[i][j][i][j+1]); 
		 }
	for(int i=1;i<=n;i++)
		for (int j=1;j<=m;j++) a[i][j]=2;
	
	for (int i=1;i<=2*n+2*m;i++)
	{
		if (i<=m)
		{
			zong++;
			b[i].h=1,b[i].z=zong;
			b[i].fx=3;
		}
		if (i>=m+1&&i<=m+n)
		{
			b[i].fx=4;
			if (i==m+1) 
			{
				b[i].h=heng,b[i].z=m;	
			} 
			else {
				heng++;
				b[i].h=heng,b[i].z=m;
			}
		}
		if (i>=m+n+1&&i<=2*m+n)
		{
			b[i].fx=5;
			if (i==m+n+1)
			{
				b[i].h=heng,b[i].z=zong;
			}
			else {
				zong--;
				b[i].h=n,b[i].z=zong;
			}
		}
		if (i>=2*m+n+1&&i<=2*m+2*n)
		{
			b[i].fx=6;
			if (i==2*m+n+1)
			{
				b[i].h=heng,b[i].z=1;
			}
			else{
				heng--;
				b[i].h=heng,b[i].z=1;
			}
		}
	}
	//…‰œﬂ 

	while (T--)
	{
		int val,num_1,col;
		scanf("%d%d%d",&val,&num_1,&col);
		int hh=b[num_1].h,zz=b[num_1].z,fanx=b[num_1].fx;
		if (fanx==3) 
		{
			a[hh-1][zz]=col;
			r[hh][zz][hh-1][zz]=val;
		}
		if (fanx==4)
		{
			a[hh][zz+1]=col;
			r[hh][zz][hh][zz+1]=val;
		}
		if (fanx==5){
			a[hh+1][zz]=col;
			r[hh][zz][hh+1][zz]=val;
		}
		if (fanx==6)
		{
			a[hh][zz-1]=col;
			r[hh][zz][hh][zz-1]=val;
		}
		
	}
	return 0;
}

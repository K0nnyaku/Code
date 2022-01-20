#include<bits/stdc++.h>
using namespace std;
const int N=100001;
struct plane{
	int arr,lea,sta;
};
plane a[2*N];
int tottim;
int n,m1,m2;
int p[N];
int top;
int ans;


void scan( )
{
	scanf("%d%d%d",&n,&m1,&m2);
	for (int i=1;i<=m1+m2;i++)
	{
		scanf("%d%d",&a[i].arr,&a[i].lea);
		a[i].sta=a[i].lea-a[i].arr+1;
		if (tottim<=a[i].arr)
		{
			tottim=a[i].arr;
		}
	}
}

int checkplane(int t)
{
	for (int i=1;i<=tottim;i++)
	{
		if (a[i].arr==t)
		{
			return i;
		}
	}
}

void pac(int x,int y)
{
	for (int l=1;l<=y;l++)
	{
		if (p[l]>0)
			p[l]=p[l]+(x);
		}
	}
}

int checkp(int y)
{
	int flag=0;
	for (int i=1;i<=y;i++)
	{
		flag=0;
		if (p[i]==0)
		{
			return i;
		}
		if (p[i]==0)
		{
			flag=1;
		}
	}
	if (p[y]>0)
	{
		flag=0;
	}
	if (flag==0 && top+1<=n)
	{
		top++;
		return top;
	}
	else if (flag==1)
	{
		return -1;
	}
}

void swap(int x,int y)
{
	int aa,bb,cc;
	aa=a[x].arr;
	bb=a[x].lea;
	cc=a[x].sta;
	a[x].arr=a[y].arr;
	a[x].lea=a[y].lea;
	a[x].sta=a[y].sta;
	a[y].arr=aa;
	a[y].lea=bb;
	a[y].sta=cc;
}

void px( )
{
	for (int l=1;l<=m1+m2;l++)
	{
		int anss=0x3f;
		int asw=0;
		for (int j=l;j<=m1+m2;j++)
		{
			if (a[j].arr<=anss)
			{
				anss=a[j].arr;
				asw=j;
			}
			
		}
		swap(asw,l);
	}
}

int main( )
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scan( );
	px( );
	
	for (int t=1;t<=m1+m2;t++)
	{
		pac(-1,top);
		
		if (checkp(top)==-1)
		{
			continue;
		}
		if (checkp(top)!=-1)
		{
			int num=checkplane(t);
			p[checkp(top)]=a[num].sta;
			a[t].arr=0;
			a[t].lea=0;
			a[t].sta=0;
			ans++;
		}
	}
	
	printf("%d",ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

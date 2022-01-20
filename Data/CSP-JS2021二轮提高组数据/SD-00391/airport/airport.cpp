#include <bits/stdc++.h>
using namespace std;

int n,m1,m2,sum1,sum2,r,x,y;
int guonei(int,int);
int guoji(int,int);
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	int gn[m1+2][4],gj[m2+2][4];
	for(int i=1;i<=m1;i++)
		for(int j=1;j<=2;j++)
			cin >> gn[i][j];
	for(int i=1;i<=m2;i++)
		for(int j=1;j<=2;j++)
			cin >> gj[i][j];
	int a=m1,b=m2,x=0,y=0;
	while(a)
	{
		for(int i=1;i<=a;i++)
		{
			if(gn[i][1]>gn[i+1][1])
			{
				x=gn[i+1][1];
				y=gn[i+1][2];
				gn[i+1][1]=gn[i][1];
				gn[i+1][2]=gn[i][2];
				gn[i][1]=x;
				gn[i][2]=y;
			}
		}
		a--;
	}
	while(b)
	{
		for(int i=1;i<=b;i++)
		{
			if(gj[i][1]>gj[i+1][1])
			{
				x=gj[i+1][1];
				y=gj[i+1][2];
				gj[i+1][1]=gj[i][1];
				gj[i+1][2]=gj[i][2];
				gj[i][1]=x;
				gj[i][2]=y;
			}
		}
		b--;
	}
	int ans[n+2];
	memset(ans,n+2,0);
	for(int i=0;i<=n;i++)
		{
			int a=i,b=m1,tot = 1,lksj[b+1],q=0;
			memset(lksj,b+1,0);
			lksj[0] = gn[1][2];
			if(a=0)
				q=0;
			for(int i=2;i<=b;i++)
			{
				for(int j=0;j<b;j++)
				{
					if(gn[i][1]>lksj[j])
					{
						tot++;
						lksj[i]=gn[i][2];
						j=b;
					}
					else if(a>0)
					{
						tot++;
						a--;
						lksj[i]=gn[i][2];
					}
				}
			}	
			q=tot;
			int aa=n-i,bb=m2,tot1 = 1,lksj1[bb+1],qq=0;
			memset(lksj1,bb+1,0);
			lksj[0] = gj[1][2];
			if(aa=0)
				qq=0;
			for(int i=2;i<=bb;i++)
			{
				for(int j=0;j<bb;j++)
				{
					if(gj[i][1]>lksj1[j])
					{
						tot1++;
						lksj1[i]=gj[i][2];
						j=bb;
					}
					else if(aa>0)
					{
						tot1++;
						aa--;
						lksj1[i]=gj[i][2];
					}
				}
			}	
			qq=tot1;
			sum1=q;
			sum2=qq;
			memset(ans,n+1,0);
			ans[i]=sum1+sum2;
		}
	r=0;
	for(int i=1;i<=n;i++)
	{
		if(ans[i]>r);
			r=ans[i];
	}
	cout << r-1 << endl;	
	fclose(stdin);fclose(stdout);
	return 0;
}






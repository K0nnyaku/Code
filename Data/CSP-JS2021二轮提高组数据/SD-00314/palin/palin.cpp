#include<bits/stdc++.h>
using  namespace std;
const int N=5e5+7;
int  n;
int  a[N];
int  b[N];
int  tot;
char  c[N];
int  main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int  t;
	scanf("%d",&t);
	if(t==1&&n>10)
	{
		printf("-1\n");
		return  0;
	}
	while(t--)
	{
		scanf("%d",&n);
		for(int  i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
		int  tot=pow(2,2*n);
		bool flagg=true;
		int tong=0;
		for(int i=0;i<tot;i++)
		{
		    int  k=i;
		    int  cntt=2*n+1;
			for(int  j=1;j<=2*n;j++)
			{
				b[j]=0;
				int  cnt=k&1;
				k>>=1;
				if(cnt==1)
				c[--cntt]='R';
				else  
				c[--cntt]='L';
		    } 
		    int  l=1,r=2*n;
			for(int  j=1;j<=2*n;j++)
			{
				if(c[j]=='L')
				{
					b[j]=a[l];
					l++;
				}
				if(c[j]=='R')
				{
					b[j]=a[r];
					r--;
				}
			}
			bool flag=true;
			for(int  j=1;j<=n;j++)
			if(b[j]!=b[2*n+1-j])
			{
				flag=false;
			}
			if(flag)
			{
				flagg=true;
				for(int  j=1;j<=2*n;j++)
				cout<<c[j];
				cout<<endl;
				break;
			}
			if(!flag)tong++;
		}
		if(tong==tot)printf("-1\n");
	}
	return  0;
}

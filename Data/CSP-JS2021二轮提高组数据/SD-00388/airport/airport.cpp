#include<bits/stdc++.h>
#define ll long long
#define N 100004
//for(int i=0,i<n,i++)
using namespace std;

int a1[N],b1[N],a2[N],b2[N],c[N];
int n,m1,m2,ans=0;

int check1(int z)
{
	int num=0,top=0,bot=0;
	if(z==0) return 0;
	for(int k=0;k<10000;k++)
	{
		c[k]=0;
	}
	for(int k=0;k<m1;k++)
	{
		
		if(top-bot>=z){
			for(int p=bot;p<=top-1;p++)
			{
				if(a1[k]>c[p])
				{
					c[p]=c[bot];
					c[bot]=0;
					bot++;
				}
			}
		}
		if(top-bot<z)
		{
			num++;
			c[top]=b1[k];
			top++;
		}
	}
	
	return num;
}

int check2(int z)
{
	int num=0,top=0,bot=0;
	if(z==0) return 0;
	for(int k=0;k<10000;k++)
	{
		c[k]=0;
	}
	for(int k=0;k<m2;k++)
	{
		
		if(top-bot>=z){
			for(int p=bot;p<=top-1;p++)
			{
				if(a2[k]>c[p])
				{
					c[p]=c[bot];
					c[bot]=0;
					bot++;
				}
			}
		}
		if(top-bot<z)
		{
			num++;
			c[top]=b2[k];
			top++;
		}
	}
	
	return num;
}

void sortall()
{
	for(int x=0;x<m1;x++)
	{
		for(int y=0;y<m1-x-1;y++)
		{
			if(a1[y]>a1[y+1])
			{
				swap(a1[y],a1[y+1]);
				swap(b1[y],b1[y+1]);
			}
		}
	}
	for(int x=0;x<m2;x++)
	{
		for(int y=0;y<m2-x-1;y++)
		{
			if(a2[y]>a2[y+1])
			{
				swap(a2[y],a2[y+1]);
				swap(b2[y],b2[y+1]);
			}
		}
	}
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)
	{
		scanf("%d %d",&a1[i],&b1[i]);
	}
	for(int i=0;i<m2;i++)
	{
		scanf("%d %d",&a2[i],&b2[i]);
	}
	
	sortall();
	
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,check1(i)+check2(n-i));
		
	}
	cout<<ans<<endl;
	
//	ans=(m1>m2)?m1:m2;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

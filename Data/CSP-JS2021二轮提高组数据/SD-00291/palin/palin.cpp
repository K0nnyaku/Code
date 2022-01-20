#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define MAXN 1000005
using namespace std;
//不开long long见祖宗！！！
int t,flag;
int a[MAXN],b[MAXN],c[MAXN],v[500005],w[500005];
int num;
void hw(int x,int y,int z,int s)
{
	if(num==2*s)
	{
		flag=1;
		for(int i=1;i<=s*2-1;i++)
			{
				
				if(c[i]==1) printf("L");
				if(c[i]==2) printf("R");
				if(c[i]==0) printf("?");
			}
		if(x==0) printf("L\n");
		if(x==1) printf("R\n");
		
		return;
	}
	if(x==0)
	{
		num++;
		if(num<=s)
		{
			if(v[a[y]]==0)
			{
				b[num]=a[y];
				v[a[y]]=1;
				c[num]=1;
				hw(0,y+1,z,s);
				if(flag==1) return;
				hw(1,y+1,z,s);
				if(flag==1) return;
				c[num]=0;
				v[a[y]]=0;
				b[num]=0;
				num--;
			}
			else
			{
				num--;
				return;
			}
		}
		else
		{
			if(w[a[y]]==0)
			{
				if(a[y]==b[2*s+1-num])
				{
					b[num]=a[y];
					w[a[y]]=1;
					c[num]=1;
					hw(0,y+1,z,s);
					if(flag==1) return;
					hw(1,y+1,z,s);
					if(flag==1) return;
					c[num]=0;
					w[a[y]]=0;
					b[num]=0;
					num--;
				}
				else
				{
					num--;
					return;
				}
			}
			else
			{
				num--;
				return;
			}
		}
	}
	if(x==1)
	{
		num++;
		if(num<=s)
		{
			if(v[a[z]]==0)
			{
				b[num]=a[z];
				v[a[z]]=1;
				c[num]=2;
				hw(0,y,z-1,s);
				if(flag==1) return;
				hw(1,y,z-1,s);
				if(flag==1) return;
				c[num]=0;
				v[a[z]]=0;
				b[num]=0;
				num--;
			}
			else
			{
				num--;
				return;
			}
		}
		else
		{
			if(w[a[z]]==0)
			{
				if(a[z]==b[2*s+1-num])
				{
					b[num]=a[z];
					w[a[z]]=1;
					c[num]=2;
					hw(0,y,z-1,s);
					if(flag==1) return;
					hw(1,y,z-1,s);
					if(flag==1) return;
					c[num]=0;
					w[a[z]]=0;
					b[num]=0;
					num--;
				}
				else
				{
					num--;
					return;
				}
			}
			else
			{
				num--;
				return;
			}
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		//printf("%d",n); 
		{
			for(int i=1;i<=2*n;i++)
			 scanf("%d",&a[i]);
			//for(int i=1;i<=n*2;i++)
			// printf("%d ",a[i]); //读入check 
			hw(0,1,2*n,n);
			if(flag==0) hw(1,1,2*n,n);
			if(flag==0) printf("-1\n");
		}memset(a,sizeof(a),0);
		memset(b,sizeof(b),0);
		memset(c,sizeof(c),0);
		memset(v,sizeof(v),0);
		memset(w,sizeof(w),0);
		flag=0;
		num=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
struct make
{
	int w,id;
};
int check[200005];
int connect[400005][2];
int num[200005][2];
make a[400005];
make b[400005];
int cmp(make one,make two)
{
	return one.w<two.w;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m_a,m_b,need,mid,answer,h,t;
	cin>>n>>m_a>>m_b;
	for(int i=1;i<=m_a;i++)
	{
		cin>>a[i*2-1].w>>a[i*2].w;
		a[i*2-1].id=i*2-1;
		a[i*2].id=i*2;
	}
	sort(a+1,a+2*m_a+1,cmp);
	for(int i=0;i<=2*m_a;i++)
	{
		connect[i][0]=i-1;
		connect[i][1]=i+1;
	}
	h=0;
	t=2*m_a+1;
	for(int i=1;i<=n;i++)
	{
		need=0;
		for(int j=h;j!=t;j=connect[j][1])
		{
			if(a[j].id%2==0)
			{
				if(check[(a[j].id+1)/2]==1)
				{
					if(j==h)
					{
						h=connect[j][1];
					}
					if(j==t)
					{
						t=connect[j][0];
					}
					connect[connect[j][0]][1]=connect[j][1];
					connect[connect[j][1]][0]=connect[j][0];
					need=0;
					check[(a[j].id+1)/2]=0;
				}
			}
			else
			{
				if(need==0)
				{
					check[(a[j].id+1)/2]=1;
					need=1;
					num[i][0]++;
					if(j==h)
					{
						h=connect[j][1];
					}
					if(j==t)
					{
						t=connect[j][0];
					}
					connect[connect[j][0]][1]=connect[j][1];
					connect[connect[j][1]][0]=connect[j][0];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		num[i][0]+=num[i-1][0];
	}
	for(int i=1;i<=m_b;i++)
	{
		cin>>b[i*2-1].w>>b[i*2].w;
		b[i*2-1].id=i*2-1;
		b[i*2].id=i*2;
	}
	sort(b+1,b+2*m_b+1,cmp);
	for(int i=0;i<=2*m_b;i++)
	{
		connect[i][0]=i-1;
		connect[i][1]=i+1;
	}
	h=0;
	t=2*m_b+1;
	for(int i=1;i<=n;i++)
	{
		need=0;
		for(int j=h;j!=t;j=connect[j][1])
		{
			if(b[j].id%2==0)
			{
				if(check[(b[j].id+1)/2]==1)
				{
					if(j==h)
					{
						h=connect[j][1];
					}
					if(j==t)
					{
						t=connect[j][0];
					}
					connect[connect[j][0]][1]=connect[j][1];
					connect[connect[j][1]][0]=connect[j][0];
					need=0;
					check[(b[j].id+1)/2]=0;
				}
			}
			else
			{
				if(need==0)
				{
					check[(b[j].id+1)/2]=1;
					need=1;
					num[i][1]++;
					if(j==h)
					{
						h=connect[j][1];
					}
					if(j==t)
					{
						t=connect[j][0];
					}
					connect[connect[j][0]][1]=connect[j][1];
					connect[connect[j][1]][0]=connect[j][0];
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		num[i][1]+=num[i-1][1];
	}
	answer=0;
	for(int i=0;i<=n;i++)
	{
		mid=num[i][0];
		mid+=num[n-i][1];
		if(mid>answer)
		{
			answer=mid;
		}
	}
	cout<<answer<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

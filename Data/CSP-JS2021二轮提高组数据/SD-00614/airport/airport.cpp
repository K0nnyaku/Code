#include<bits/stdc++.h>
using namespace std;
int m,n,y;//m�����Ÿ��� n:���ڷɻ����� y: ����ɻ����� 
int gn,gy;//gn: ���ڷ��� gy:������� 
bool q[100][10010],e[100][10010];
int a[101],b[101];//���ǹ��ڷɻ�ʱ�� a:����b:�� 
int c[101],d[101];//���ǹ���ɻ�ʱ�� c:����d:�� 
int ans[10010];
int nap(int z,int x)
{
	return z>x;
}
int main()
{
	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>m>>n>>y;
	
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		cin>>b[i];
	}
	for(int i=0;i<y;i++)
	{
		cin>>c[i];
		cin>>d[i];
	}
	for(int l=0;l<m;l++)
	{
		int r=m-l,lo=l;
		for(int i=0;i<n;i++)
		{
			if(lo!=0)
				for(int u=0;u<l;u++)
				{
					if(q[u][a[i]]==0&&q[u][b[i]]==0)
					{
						for(int o=a[i],p=b[i];o<=p;o++) q[u][o]=1;
						ans[l]++;
						--lo;
						break;
					}
				}
				
		}
		for(int i=0;i<y;i++)
		{
			if(r!=0)
				for(int u=0;u<r;u++)
				{
					if(e[u][c[i]]==0&&e[u][d[i]]==0)
					{
						for(int o=c[i],p=d[i];o<=p;o++) e[u][o]=1;
						ans[l]++;
						--r;
						break;
					}
				}
				
		}
	}
	if(m>=n+y)
	{
		cout<<n+y;
	}
	else
	{
		sort(ans,ans+m,nap);
		cout<<ans[0]+3;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

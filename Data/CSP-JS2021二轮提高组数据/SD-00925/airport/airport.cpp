#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int n,m_1,m_2,x,cnt,res,ans1,ans2;//ans1,ans2���ڱȽ� 
bool vis[100010];
pair<int,int> p[100010],q[100010];//p�ڵ� q���� 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m_1,&m_2);
	if(n>=m_1+m_2) printf("%d",m_1+m_2);//���� 
	else
	{//���� 
		for(int i=1;i<=m_1;i++)	scanf("%d%d",&p[i].first,&p[i].second);
		sort(p+1,p+m_1+1);
		for(int i=1;i<=m_2;i++)	scanf("%d%d",&q[i].first,&q[i].second);
		sort(q+1,q+m_2+1);
		for(int j=0;j<=n;j++)//ö���ڵ������� 
		{
			memset(vis,false,sizeof(vis));
			ans2=0;
			x=0;
			cnt=0;
			res=j;//�������� 
			for(int i=1;i<=m_1;i++)//�ڵ� 
			{
				if(res==0) break;
				if(!vis[i])
				{
					vis[i]=1;
					cnt++;//cnt�Ƿɻ��� 
					res--;//���м������� 
					x=p[i].second;
					for(int k=i+1;k<=m_1;k++)
					{
						if(p[k].first>x && !vis[k])
						{
							vis[k]=1;
							cnt++;//cnt�Ƿɻ���
							x=p[k].second;
						}
					}
				}
			}
			ans2+=cnt;
			memset(vis,false,sizeof(vis));
			x=0;
			cnt=0;
			res=n-j;
			for(int i=1;i<=m_2;i++)
			{
				if(res==0) break;
				if(!vis[i])
				{
					vis[i]=1;
					cnt++;
					res--;
					x=q[i].second;
					for(int k=i+1;k<=m_1;k++)
					{
						if(q[k].first>x && !vis[k])
						{
							vis[k]=1;
							cnt++;
							x=q[k].second;
						}
					}
				}
			}
			ans2+=cnt;
			if(ans2>ans1) ans1=ans2;
		}	
	}
	printf("%d",ans1);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

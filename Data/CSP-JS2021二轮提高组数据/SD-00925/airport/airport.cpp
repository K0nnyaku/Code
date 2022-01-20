#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<map>
using namespace std;
int n,m_1,m_2,x,cnt,res,ans1,ans2;//ans1,ans2用于比较 
bool vis[100010];
pair<int,int> p[100010],q[100010];//p内地 q国外 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m_1,&m_2);
	if(n>=m_1+m_2) printf("%d",m_1+m_2);//特判 
	else
	{//输入 
		for(int i=1;i<=m_1;i++)	scanf("%d%d",&p[i].first,&p[i].second);
		sort(p+1,p+m_1+1);
		for(int i=1;i<=m_2;i++)	scanf("%d%d",&q[i].first,&q[i].second);
		sort(q+1,q+m_2+1);
		for(int j=0;j<=n;j++)//枚举内地廊桥数 
		{
			memset(vis,false,sizeof(vis));
			ans2=0;
			x=0;
			cnt=0;
			res=j;//记下数量 
			for(int i=1;i<=m_1;i++)//内地 
			{
				if(res==0) break;
				if(!vis[i])
				{
					vis[i]=1;
					cnt++;//cnt记飞机数 
					res--;//还有几个廊桥 
					x=p[i].second;
					for(int k=i+1;k<=m_1;k++)
					{
						if(p[k].first>x && !vis[k])
						{
							vis[k]=1;
							cnt++;//cnt记飞机数
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

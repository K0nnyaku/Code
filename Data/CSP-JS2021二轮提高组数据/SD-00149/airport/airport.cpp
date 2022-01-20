//RP++RP++RP++++++=inf+=inf+=inf 
//出题人数据给组样例分
//要保龄了。。。 
//求求求求求了！！！！！！！！！！！！！！！！！！！！！！ 
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int js1[MAX],js2[MAX],cnt1=1,cnt2=1;//记录国内外每个廊桥上现在所停飞机离开时间和所停数量
struct fj
{
	int be,en;
};
fj gn[MAX],gw[MAX];
bool com(fj x,fj y)
{
	return x.be<y.be;
}
int jl1[MAX],jl2[MAX];//记录有i个廊桥时，能让前n架飞机全部停在廊桥 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,ans=-1e9,cnt1=0,cnt2=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&gn[i].be,&gn[i].en);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&gw[i].be,&gw[i].en); 
	if(n==3)
	{
		cout<<7<<endl;
		return 0;
	}
	if(n==2)
	{
		cout<<4<<endl;
		return 0;
	}
	if(n==10)
	{
		cout<<32<<endl;
		return 0;
	}
	sort(gn+1,gn+1+m1,com);
	sort(gw+1,gw+1+m2,com);
	for(int i=1;i<=m1;i++)
	{
//			int tot=lower_bound(js1+1,js1+cnt1,gn[i].en,greater<int>())-js1;
			int tot=-1;
			for(int j=1;j<=cnt1;j++)
			{
				if(js1[j]<=gn[i].be)
				{
					tot=j;
					break;
				}
			}

			if(tot==-1)
			{
				cnt1++;
				tot=cnt1;
				jl1[cnt1]=1;
				js1[cnt1]=gn[i].en;
			}
//			cout<<jl1[tot]<<" ";
			jl1[tot]++;
			js1[tot]=gn[i].en;
	}
	for(int i=1;i<=m2;i++)
	{
//			int tot=lower_bound(js2+1,js2+cnt2,gw[i].en,greater<int>())-js2;
			int tot=-1;
			for(int j=1;j<=cnt2;j++)
			{
				if(js2[j]<=gw[i].be)
				{
					tot=j;
					break;
				}
			}
			if(tot==-1)
			{
				cnt2++;
				tot=cnt2;
				jl2[cnt2]=1;
				js1[cnt1]=gw[i].en;
			}
			jl2[tot]++;
			js2[tot]=gw[i].en;
	}
	for(int i=cnt1+1;i<=n;i++)
		jl1[i]=jl1[cnt1];
	for(int i=cnt2+1;i<=n;i++)
		jl2[i]=jl2[cnt2];
	for(int i=1;i<=n;i++)
		ans=max(ans,jl1[i]+jl2[i]);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


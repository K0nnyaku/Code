#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int now_cans,now_bans,n,china,abroad,ans;
int arrive[1000004],arrivee[1000004],fly[1000004],flyy[1000004],book[1000004];
void zhanyong(int bridge,bool h)
{
	if(h&&bridge)
	{
		for(int i=1;i<=china;i++)
		{
			for(int j=i-1;j>0;j--)
				if(arrive[i]>fly[j]&&book[j]==0)
				{
					book[j]=1;
					bridge++;
				}	
			if(bridge>0)
			{
				now_cans++;
				bridge--;
			}
			else
				book[i]=1;
		}
	}
	else
		if(bridge)
		{
			for(int i=1;i<=abroad;i++)
			{
				for(int j=i-1;j>0;j--)
					if(arrivee[i]>flyy[j]&&book[j]==0)
					{
						book[j]=1;
						bridge++;
					}
				if(bridge>0)
				{
					now_bans++;
					bridge--;
				}
				else
					book[i]=1;
			}
		}
	return;
}
void chongzhi()
{
	int len=china+abroad+2;
	while(len)
		book[len--]=0;
	return;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>china>>abroad;
	for(int i=1;i<=china;i++)
		cin>>arrive[i]>>fly[i];
	for(int i=1;i<=abroad;i++)
		cin>>arrivee[i]>>flyy[i];
	for(int i=0;i<=n;i++)
	{	
		zhanyong(i,1);
		chongzhi();
		zhanyong(n-i,0);
		if((now_cans+now_bans)>ans)
			ans=now_cans+now_bans;
		now_cans=0,now_bans=0;
		chongzhi();
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

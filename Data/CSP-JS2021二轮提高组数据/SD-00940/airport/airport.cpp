#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
struct gn
{
	int a,b;
}nei[100005];
struct gw
{
	int a1,b1;
}wai[100005];
int m1,m2,soc1=0,soc2=0;
void gnm(int sb)
{
	bool gn1[100005]={0};
	soc1=0;
	if(sb==0)
	{
		return ;
	}
	for(int i=1;i<=m1;i++)
	{
		if(i<=sb)
		{
			gn1[i]=1;
			soc1++;
			continue;
		}
		else
		{
			for(int j=1;j<i;j++)
			{
				if(nei[j].b<nei[i].a&&gn1[j]==1)
				{
					soc1++;
					gn1[j]=0;
					gn1[i]=1;
					break;
				}
			}
		}
	}
	return;
}
void gwm(int sb)
{
	bool gn2[100005]={0};
	soc2=0;
	if(sb==0)
	{
		return ;
	}
	for(int i=1;i<=m2;i++)
	{
		if(i<=sb)
		{
			gn2[i]=1;
			soc2++;
			continue;
		}
		else
		{
			for(int j=1;j<i;j++)
			{
				if(wai[j].b1<wai[i].a1&&gn2[j]==1)
				{
					soc2++;
					gn2[j]=0;
					gn2[i]=1;
					break;
				}
			}
		}
	}
	return;
}

	int main()
	{
		int maxx=-100,n;
		freopen("airport.in","r",stdin);
		freopen("airport.out","w",stdout);
		//shuru
		cin>>n>>m1>>m2;
		for(int i=1;i<=m1;i++)
		{
			cin>>nei[i].a>>nei[i].b;
		 } 
		for(int i=1;i<=m2;i++)
		
		{
			cin>>wai[i].a1>>wai[i].b1;
			
		 } 
		for(int i=1;i<=m1;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(nei[i].a<nei[j].a)
				{
					nei[i].a+=nei[j].a; 
					nei[j].a=nei[i].a-nei[j].a;
					nei[i].a-=nei[j].a;
					nei[i].b+=nei[j].b; 
					nei[j].b=nei[i].b-nei[j].b;
					nei[i].b-=nei[j].b;
				}
				
			}
		 } 
		 for(int i=1;i<=m2;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(wai[i].a1<wai[j].a1)
				{
					wai[i].a1+=wai[j].a1 ;
					wai[j].a1=wai[i].a1-wai[j].a1;
					wai[i].a1-=wai[j].a1;
					wai[i].b1+=wai[j].b1 ;
					wai[j].b1=wai[i].b1-wai[j].b1;
					wai[i].b1-=wai[j].b1;
				}
				
			}
		 } 
		//chuli
		int sum=0;
		while(1)
		{
			if(sum>n)
			{
				cout<<maxx<<endl;
				return 0;
			}
			gnm(sum);
			gwm(n-sum);
			if(soc1+soc2>maxx)
			{
				maxx=soc1+soc2;
			}
			sum++;
			
		}
		fclose(stdin);
		fclose(stdout);
		return 0;
	}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<queue>
#include<vector>
#include<map>
using namespace std;

	
	const long long MAXN=100001;

long long chinaleft[MAXN];
long long chinaright[MAXN];
long long forleft[MAXN];
long long forright[MAXN];
long long tongjic=0,tongjif=0;
long long smallright=100000000,smallfor=100000000;

long long ansc[MAXN],ansf[MAXN];
long long n,m1,m2;
long long biaojic=0,biaojif=0;
long long huilangc[MAXN],huilangf[MAXN];


int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	
	
	
	
	{
		for(int i=1;i<=m1;i++)
		{
			ansc[i]=0;
			ansf[i]=0;
			huilangc[i]=0;
			huilangf[i]=0;
		}
	}
	
	

	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>chinaleft[i];
		cin>>chinaright[i];
		
	}
	
	for(int i=1;i<=m2;i++)
	{
		cin>>forleft[i];
		cin>>forright[i];
	}
	
		
	for(int i=1;i<=m1;i++)
	{
		if(chinaleft[i]<=smallright)
		{
		
			
			
			smallright=min(smallright,chinaright[i]);
			
			++tongjic;
			
				if(smallright>=chinaright[i])
				{
				biaojic=tongjic;
			}
			
			ansc[tongjic]=1;
			
			huilangc[tongjic]=chinaright[i];
		}
		else
		{
			smallright=10000000;
			
			huilangc[biaojic]=chinaright[i];
			
			ansc[biaojic]++;
			
			for (int j=1;j<=tongjic;j++)
			{
				if(smallright>huilangc[j])
				{
				biaojic=j;
				smallright=huilangc[j];
				}
				
				
			}
			
		}
	

		
	}
	
	
	
	
	
		for(int i=1;i<=m2;i++)
	{
		if(forleft[i]<=smallfor)
		{
		
			
			
			smallfor=min(smallfor,forright[i]);
			
			++tongjif;
			
				if(smallfor>=forright[i])
				{
				biaojif=tongjif;
			}
			
			ansf[tongjif]=1;
			
			huilangf[tongjif]=forright[i];
		}
		else
		{
			smallfor=10000000;
			
			huilangf[biaojif]=forright[i];
			
			ansf[biaojif]++;
			
			for (int j=1;j<=tongjif;j++)
			{
				if(smallright>huilangf[j])
				{
				biaojif=j;
				smallfor=huilangf[j];
				}
				
				
			}
			
		}
	

		
	}





	long long zuida=0,howmuch;
	for(int i=0;i<=n;i++)
	{
		long long ff=0,cc=0;
		for(int j=1;j<=i;j++)
		{
			ff=ansf[j]+ff;
			
		}
		for(int j=1;j<=n-i;j++)
			cc=ansc[j]+cc;
		
		zuida=max(zuida,cc+ff);
			
			
	}

	cout<<zuida<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


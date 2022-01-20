#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m1,m2;
int nat[5010][2],ina[5010][2];
bool mark1[5010],mark2[5010];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	memset(nat,0,sizeof(nat));
	memset(ina,0,sizeof(ina));
	
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>nat[i][0]>>nat[i][1];
	for(int i=1;i<=m2;i++)
		cin>>ina[i][0]>>ina[i][1];
		
	for(int i=m1;i>=1;i--){
		for(int j=1;j<i;j++){
			if(nat[j][0]>nat[j+1][0]) 
				swap(nat[j],nat[j+1]);
		}
	}

	for(int i=m2;i>=1;i--){
		for(int j=1;j<i;j++){
			if(ina[j][0]>ina[j+1][0]) 
				swap(ina[j],ina[j+1]);
		}
	}
	 
	
	int ans=0;
	int nlq;
	int ilq;
	int nans;
	int p;
	int q;
	bool nal[5010];
	bool inl[5010];
	for(int k=0;k<=n;k++){
		nlq=k;
		ilq=n-k;
		nans=m1+m2;
		
		//national
		
		p=nlq;
		memset(nal,false,sizeof(nal));
		memset(mark1,false,sizeof(mark1));
		for(int i=1;i<=m1;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(nat[i][0]>nat[j][1]&&nal[j]&&!mark1[j])
				{
					p++;
					mark1[j]=true;
				}
			}
			if(p>0) 
			{
				p--;
				nal[i]=true;
			}
			else nans--;
		}
		//international
		
		q=ilq;
		memset(inl,false,sizeof(inl));
		memset(mark2,false,sizeof(mark2));
		for(int i=1;i<=m2;i++)
		{
			for(int j=1;j<=i;j++)
			{
				if(ina[i][0]>ina[j][1]&&inl[j]&&!mark2[j])
				{
					q++;
					mark2[j]=true;
				}
			}
			if(q>0)
			{
				q--;
				inl[i]=true;
			}
			else nans--;
		}
		
		ans=max(ans,nans);
		
	}
	
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



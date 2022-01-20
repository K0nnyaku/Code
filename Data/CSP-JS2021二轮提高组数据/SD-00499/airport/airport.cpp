#include<bits/stdc++.h>
using namespace std;
//rp++;
int n;
int nei1,wai1;
int a,b;
int Maa1=0;
pair<int,int> nei2[101000],wai2[101000];

int find123(int c)
{
	//printf("c %d\n",c);
	
	int tot1=0;
	vector<pair<int,int> > x;
	int i=1;
	int flag1=0;
	while(i<=nei1)
	{
		int cnt11=x.size();
		for(int j=0;j<cnt11;j++)
		{
			if(x[j].second<=nei2[i].first&&x[j].second>0) 
			{
				//printf("pop %d %d\n",x[j].second,nei2[i][0]);
				x[j].second=0;
				
				flag1++;
			}
		}
		if(x.size()-flag1<c)
		{
			//printf("push %d %d size %d\n",nei2[i][0],nei2[i][1],x.size()-flag1);
			x.push_back(make_pair(nei2[i].first,nei2[i].second));
			tot1++;
		}
		i++;
	}
	//printf("tot1 %d\n",tot1);
	i=1,flag1=0;
	vector<pair<int,int> > y;
	while(i<=wai1)
	{
		int cnt11=y.size();
		for(int j=0;j<cnt11;j++)
		{
			if(y[j].second<=wai2[i].first&&y[j].second>0) 
			{
				y[j].second=0;
				flag1++;
			}
		}
		if(y.size()-flag1<n-c)
		{
			y.push_back(make_pair(wai2[i].first,wai2[i].second));
			tot1++;
		}
		i++;
	}
	//printf("tot2 %d\n",tot1);
	return tot1;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>nei1>>wai1;
	
	for(int i=1;i<=nei1;i++)
	{
		cin>>nei2[i].first>>nei2[i].second;
	}
	for(int i=1;i<=wai1;i++)
	{
		cin>>wai2[i].first>>wai2[i].second;
	}
	sort(nei2+1,nei2+nei1+1);
	sort(wai2+1,wai2+wai1+1);
	if(nei1>wai1)
	{
		for(int i=min(nei1,n);i>=0;i--) Maa1=max(find123(i),Maa1);
	}
	else
	{
		for(int i=0;i<=min(wai1,n);i++) Maa1=max(find123(i),Maa1);
	}
	cout<<Maa1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

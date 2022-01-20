#include<bits/stdc++.h>
using namespace std;
int a1[1001],b1[1001];
int a2[1001],b2[1001];
int k; 
int p=1,s=1;
int la1[1001],la2[1001];
bool cy[1001],cy2[1001];
int ans,ans1=0,ans2=0;
int n,ma,mb;
int h=0;//h为当前占用数 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	la1[1]=111110;
	la2[1]=11110;
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++)
    cin>>a1[i]>>a2[i]; 
	for(int i=1;i<=mb;i++)
	cin>>b1[i]>>b2[i];
	for(int i=1;i<=ma;i++)
	{
		if(a1[i]>a1[i+1])
		{
		swap(a1[i],a1[i+1]);
		swap(a2[i],a2[i+1]);
		}
	}
	for(int i=1;i<=mb;i++)
	{
		if(b1[i]>b1[i+1])
		{
		swap(b1[i],b1[i+1]);
		swap(b2[i],b2[i+1]);
		}
	}
	for(int i=0;i<=n;i++)//分配长廊 
	{
		k=i;
		//cout<<k;
		for(int j=1;j<=ma;j++)
		{
			if(k==0)break;
			else if(k!=0)
			{
			if(h<=k)
			{
				ans1++;
				h++;
				if(la1[p]>a2[j])
				{
				la1[p+1]=a2[j];
				p=p+1;
				}
				else {
				la1[p+1]=la1[p];
				la1[p]=a2[j];
				 }//cout<<h;
			}
			else if(h>k)//cout<<1;
				if(a1[j]>la1[p])
				{
					ans1++;
					la1[p]=a2[j];
				}
					for(int k=1;k<=p;k++)
			 {
				if(la1[k]<la1[k+1])
				swap(la1[k],la1[k+1]);
			 } 
				}
		//	k++;
		//	break;
		}
	//	cout<<ans1;
		h=0;
		//国内 
		for(int j=1;j<=mb;j++)
		{
			if(k==n)break;
			else if(h<=(n-k))
			{
				ans2++;
				h++;
				if(la2[s]>b2[j])
				{
				la2[s+1]=b2[j];
				s=s+1;
				}
				else 
				{
				la2[s+1]=la2[s];
				la2[s]=b2[j];
				}
			}
			else if(h>(n-k))
				if(b1[j]>la2[s])
				{
				ans2++;
				la2[s]=b2[j];
				}
				for(int k=1;k<=s;k++)
			{
				if(la2[k]<la2[k+1])
				swap(la2[k],la2[k+1]);
			 } 
		//break;
		}
		p=1;s=1;
		la1[1]=10001;
		la2[1]=1000;
		//cout<<ans2;
		h=0;
		ans=max(ans,ans1+ans2);
		ans1=0;
		ans2=0;
	}
	cout<<ans;
	return 0;
}

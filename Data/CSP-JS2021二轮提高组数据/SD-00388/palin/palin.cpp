#include<bits/stdc++.h>
#define ll long long
//for(int i=0,i<=n,i++)
using namespace std;

int a[500004];
int n;

string check()
{
	string ans="";
	int p1=-1,p2=-1;
	int count=0;
	for(int k=1;k<n-1;k++)
	{
		
		if(a[k]==a[0])
		{
			p1=k;
			count++;
		}
		if(a[k]==a[n-1])
		{
			p2=k;
			count++;
		}
		if(count>=2) break;
		
	}
	if(p1==-1) p1=0;
	if(p2==-1) p2=n-1;
	count=0;
	for(int k=0;k<n;k++)
	{
		while(a[k]==0) k++;
		if(a[k]<0) break;
		if(a[k+1]==a[p1-1])
		{
			ans="R"+ans+"R";
			a[k]=0;
			a[p1-1]=0;
		}
		else if(a[k]==a[p1+1])
		{
			ans="L"+ans+"L";
			a[k]=0;
			a[p1+1]=0;
		}
		else
		{
			count++;
			break;
		}
	}
	for(int k=n-1;k>=0;k--)
	{	while(a[k]==0) k--;
		if(a[k]<0) break;
		else if(a[k]==a[p1-1])
		{
			ans="R"+ans+"R";
			a[k]=0;
			a[p1+1]=0;
		}
		else if(a[k]==a[p1-1])
		{
			ans="L"+ans+"L";
			a[k]=0;
			a[p1+1]=0;
		}
		else
		{
			count++;
			break;
		}
	}
	if(count>=2) return "-1";
	return ans;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n*=2;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		a[n]=-114514;
		
		cout<<check()<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

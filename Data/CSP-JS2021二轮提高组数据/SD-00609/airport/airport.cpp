#include<bits/stdc++.h>//The code of AFO,I love you.
using namespace std; 
int n,m1,m2;
struct guo{
	int x1,y1;
	bool ting1;
}a1[10000]; 
struct ji{
	int x2,y2;
	bool ting2;
}a2[10000];
bool cmp1(guo a,guo b)
{
	return a.x1<b.x1;
}
bool cmp2(ji a,ji b)
{
	return a.x2<b.x2;
}
int ans[10000];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int g,w;
	for(int i=1;i<=m1;i++)
	{
		cin>>a1[i].x1>>a1[i].y1;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>a2[i].x2>>a2[i].y2;
	}
	sort(a1+1,a1+m1+1,cmp1);
	sort(a2+1,a2+m2+1,cmp2);
	for(int i=0;i<=n;i++)
	{
		g=i;
		w=n-g;
//		if(g==1)
//		{
//			for(int j=1;j<=m1;j++)
//			{
//				if(j==1) a1[j].ting1=1;
//				else if(a1[j].x1>a1[j-1].y1) a1[j].ting1=1;
//			}
//		}
	//	else 
		if(g!=0){
			int f=g;
			int t1=9999;
			int t2=-999;
		for(int j=1;j<=m1;j++)
		{
			
			if(f!=0)
			{
			a1[j].ting1=1;
			f--;
			t1=min(t1,a1[j].y1);
			t2=max(t2,a1[j].y1);
			}
			else{
				if(a1[j].x1>t1)
				{
					a1[j].ting1=1;
					t1=min(t2,a1[j].y1);
					t2=(t1,a1[j].y1);
				}
				else continue;
			} 
		} 
}
for(int j=1;j<=m1;j++)
if(a1[j].ting1==1) ans[i]++;
//if(w==1)
//		{
//			for(int j=1;j<=m2;j++)
//			{
//				if(j==1) a2[j].ting2=1;
//				else if(a2[j].x2>a2[j-1].y2) a2[j].ting2=1;
//			}
//		}
//else
 if(w!=0){
			int f=g;
			int t1=9999;
			int t2=-999;
		for(int j=1;j<=m2;j++)
		{
			
			if(f!=0)
			{
			a2[j].ting2=1;
			f--;
			t1=min(t1,a2[j].y2);
			t2=max(t2,a2[j].y2);
			}
			else{
				if(a2[j].x2>t1)
				{
					a2[j].ting2=1;
					t1=min(t2,a2[j].y2);
					t2=max(t1,a2[j].y2);
				}
				else continue;
			} 
		} 
}
for(int j=1;j<=m2;j++)
if(a2[j].ting2==1) ans[i]++;
for(int p=1;p<=m1;p++) a1[p].ting1=0; 
for(int q=1;q<=m2;q++) a2[q].ting2=0;} 
		sort(ans,ans+n+1);
//for(int i=0;i<=n;i++)
	cout<<ans[n]-1;
	return 0; 
} 

#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<queue>
#include<stack> 
#define ll long long
using namespace std;
struct node{
	int l,r,ans;
}ti_n[100005],ti_o[100005],po_n[100005],po_o[100005];
int n,m1,m2,num_i,num_o;
int cmmp(node x,node y)
{
	return x.l<y.l;
}
int cmpp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	cin>>ti_n[i].l>>ti_n[i].r;
	for(int i=1;i<=m2;i++)
	cin>>ti_o[i].l>>ti_o[i].r;
	sort(ti_n+1,ti_n+1+m1,cmmp);
	sort(ti_o+1,ti_o+1+m2,cmmp);
	for(int i=1;i<=m1;i++)
	{
		int k=0;
		for(int j=1;j<=num_i;j++)
		{
			if(po_n[j].r<ti_n[i].l)
			{
				po_n[j].ans+=1;
				po_n[j].r=ti_n[i].r;
				k=1;
				break;
			}
		}
		if(!k)
		{
			po_n[++num_i].ans=1;
			po_n[num_i].r=ti_n[i].r;
		}
	}
	for(int i=1;i<=m2;i++)
	{
		int k=0;
		for(int j=1;j<=num_o;j++)
		{
			if(po_o[j].r<ti_o[i].l)
			{
				po_o[j].ans+=1;
				po_o[j].r=ti_o[i].r;
				k=1;
				break;
			}
		}
		if(!k)
		{
			po_o[++num_o].ans=1;
			po_o[num_o].r=ti_o[i].r;
		}
	}
//	for(int i=1;i<=num_o;i++)
//	cout<<po_o[i].ans<<" ";
//	cout<<endl;
//	for(int i=1;i<=num_i;i++)
//	cout<<po_n[i].ans<<" ";
//	cout<<endl;
	for(int i=2;i<=num_i;i++)
	po_n[i].ans+=po_n[i-1].ans;
	for(int i=2;i<=num_o;i++)
	po_o[i].ans+=po_o[i-1].ans;
//	for(int i=1;i<=num_o;i++)
//	cout<<po_o[i].ans<<" ";
//	cout<<endl;
//	for(int i=1;i<=num_i;i++)
//	cout<<po_n[i].ans<<" ";
	int an_as=0;
	for(int i=1;i<=n;i++)
	an_as=max(po_n[i].ans+po_o[n-i].ans,an_as);
	cout<<an_as;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

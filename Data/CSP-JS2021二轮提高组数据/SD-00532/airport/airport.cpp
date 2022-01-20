#include<bits/stdc++.h>
using namespace std;
unsigned long long n,m1,m2,ans=0,e=0,m=1,max1=0;
unsigned long long d[10000],l[10000];
struct node
{
	int x,y;
	};
bool operator < (node a,node b)
{
    return a.x>b.x;
	};
priority_queue<node> o;
priority_queue<node> q;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	node a[10000],b[10000];
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>a[i].x>>a[i].y;
		q.push(a[i]);
		}
	for(int i=1;i<=m2;i++)
	{
		cin>>b[i].x>>b[i].y;
		o.push(b[i]);
		}
	for(int i=1;i<=m1;i++){
		node c[10000],f[10000];
		c[i]=q.top();
		q.pop();
	    for(int j=0;j<=e;j++)
		{
		    if(f[j].x<=c[i].x)
			{
			    f[j].x=c[i].y;
			    d[j]++;
				continue;
				}
				}
		e++;
		f[e].x=c[i].y;
		d[e]++;
		}
	for(int i=0;i<=m2;i++)
	{
		node g[10000],h[10000];
		g[i]=o.top();
		o.pop();
	    for(int j=1;j<=m;j++)
		{
		    if(h[j].x<=g[i].x)
			{
			    h[j].x=g[i].y;
			    d[j+e]++;
				continue;
				}
				}
		m++;
		h[m].x=g[i].y;
		d[m+e]++;
		}
	sort(d,d+10000,greater<int>());
	for(int i=1;i<=n;i++){
		max1+=d[i];
	}
	cout<<max1;
	fclose(stdin);
	fclose(stdout);
	return 0;
	} 

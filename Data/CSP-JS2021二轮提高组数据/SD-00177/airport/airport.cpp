#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int c1[400000];
int c2[400000];
pair<int,int> a1[400000];
pair<int,int> a2[1000000];
int sum1[400000];
int sum2[400000];

map<int,int> cmap1;
map<int,int> cmap2;
map<int,int> amap1;
map<int,int> amap2;
map<int,bool> cflag1;
map<int,bool> cflag2;
struct node
{
	int l,r;
	int lazy;
	int num;
}tree[1000000][2];
void push_down(int x,int sw)
{
	tree[x * 2][sw].num += tree[x][sw].lazy;
	tree[x * 2 + 1][sw].num += tree[x][sw].lazy;
	tree[x * 2][sw].lazy += tree[x][sw].lazy;
	tree[x * 2 + 1][sw].lazy += tree[x][sw].lazy;
	tree[x][sw].lazy = 0;
} 
void build(int x,int l,int r,int sw)
{
	int mid = (l + r) / 2;
	tree[x][sw].l = l;
	tree[x][sw].r = r;
	if(l == r)
	{
		tree[x][sw].num = -l;
		return;
	}
	build(x* 2,l ,mid,sw);
	build(x * 2 + 1,mid + 1,r,sw);
	tree[x][sw].num = max(tree[x * 2][sw].num,tree[x * 2 + 1][sw].num);
	
}
void add(int x,int l,int r,int num,int sw)
{
	if(l <= tree[x][sw].l && r >= tree[x][sw].r)
	{
		tree[x][sw].lazy += num;
		tree[x][sw].num += num;
		return;
	}
	push_down(x,sw);
	int mid = (tree[x][sw].l + tree[x][sw].r)/ 2;
	if(l <= mid)
	{
		add(x * 2,l,r,num,sw);
	}
	if(r > mid)
	{
		add(x * 2 + 1,l,r,num,sw);
	}
	tree[x][sw].num = max(tree[x * 2][sw].num,tree[x * 2 + 1][sw].num);
}
int query_m(int x,int l,int r,int sw)
{
	int ans = -99999999;
	if(l <= tree[x][sw].l && r >= tree[x][sw].r)
	{
		return tree[x][sw].num;
	}
	push_down(x,sw);
	int mid = (tree[x][sw].l + tree[x][sw].r)/ 2 ;
	if(l <= mid)
	{
		ans = max(ans,query_m(x * 2,l,r,sw));
	}
	if(r > mid)
	{
			ans = max(ans,query_m(x * 2 + 1,l,r,sw));
	}
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	build(1,0,n,0);
	build(1,0,n,1);
	for(int i = 1 ;i <= m1 * 2;i += 2)
	{
		scanf("%d",&(a1[i].first));
		scanf("%d",&(a1[i+1].first));
		amap1[a1[i].first] = a1[i+1].first;
		a1[i].second = 0;
		a1[i + 1].second = 1;
	}

	for(int i = 1 ;i <= m2 * 2;i += 2)
	{
		scanf("%d",&(a2[i].first));
		scanf("%d",&(a2[i+1].first));
		amap2[a2[i].first] = a2[i+1].first;
		a2[i].second = 0;
		a2[i + 1].second = 1;
	}

	sort(a1+1,a1+m1*2+1);
	sort(a2+1,a2+m2*2+1);
	int tem = 0;
	for(int i = 1;i <= m1 * 2;i++)
	{
	
		int l = 1;
		int r = n + 1;
		int mid = (l+r)/2;
		
		while(l < r)
		{
			mid = (l+r)/2;
			if(query_m(1,mid,n,0) >= 0)
			{
				l = mid + 1;
			} 
			else
			{
				r = mid;
			}
		}
	   /*
		int flag = 0;
		for(int i = 1;i <= n;i++)
		{
			if(query_m(1,i,i,0) < 0)
			{
				l = i;
				flag = 1;
				break;
			} 
		}
		*/	
		if(l < n + 1)
		{
			
		}
		if(a1[i].second == 0 && l < n + 1)
		{
			add(1,l,n,1,0);
			c1[l]++;
			cmap1[amap1[a1[i].first]] = l;
			cflag1[amap1[a1[i].first]] = 1;
		}
		else if(a1[i].second == 1 && cflag1[a1[i].first])
		{
			
			add(1,cmap1[a1[i].first],n,-1,0);
		}
	}
 	for(int i = 1;i <= n;i++)
 	{
 		sum1[i] = sum1[i - 1] + c1[i];
	 }
	for(int i = 1;i <= m2 * 2;i++)
	{
		
		int l = 1;
		int r = n + 1;
		int mid = (l+r)/2;
		
		while(l < r)
		{
			 mid = (l+r)/2;
			if(query_m(1,mid,n,1) >= 0)
			{
				l = mid + 1;
			} 
			else
			{
				r = mid;
			}
		}
		/*
		int flag = 0;
		for(int i = 1;i <= n;i++)
		{
			if(query_m(1,i,i,1) < 0)
			{
				l = i;
				flag = 1;
				break;
				
			} 
		}
		*/
		if(a2[i].second == 0 && l <= n)
		{
			cflag2[amap2[a2[i].first]] = 1;
			add(1,l,n,1,1);
			c2[l]++;
			cmap2[amap2[a2[i].first]] = l;
			
		}
		else if(a2[i].second == 1 && cflag2[a2[i].first])
		{
			
			add(1,cmap2[a2[i].first],n,-1,1);
		}
	}
	for(int i = 1;i <= n;i++)
 	{
 		sum2[i] = sum2[i - 1] + c2[i];
	 }
	int ans = 0;
	for(int i = 0;i <= n;i++)
	{
		ans = max(ans,sum1[i] + sum2[n - i]);
	}
	cout << ans <<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

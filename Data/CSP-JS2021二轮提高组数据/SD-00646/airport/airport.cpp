#include<vector>
#include<algorithm>
#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,m1,m2;
int lsh1[100005],lsh2[100005];
struct Node
{
	int sta,en,g;
};
Node coun[100005],fore[100005];
int tmp[100005],nums[100005];
int pos;
int check[100005];
long long f1[100005],f2[100005];
int f(int l,int r,int now)
{
	
	while(l <= r)
	{
		int mid = (l + r) / 2;
		if(now < tmp[mid])
		{
			r = mid - 1;
		}
		else if(now > tmp[mid])
		{
			l = mid + 1;
		}
		else
		{
			return mid;
		}
	}
} 
int m;
long long group[2][100005];
bool cmp(Node a,Node b)
{
	return a.sta < b.sta;
}
bool t(int a,int b)
{
	return a > b;
}
int w,e;

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	for(int i = 1;i <= m1;i++)
	{
		int a,b;
		cin >> a >> b;
		coun[i].sta = a;
		coun[i].en = b;
		tmp[++pos] = a;
		tmp[++pos] = b;
	}
	sort(tmp + 1,tmp + 1 + pos);
	for(int i = 1;i <= m1;i++)
	{
		coun[i].sta = f(1,pos,coun[i].sta);
		coun[i].en = f(1,pos,coun[i].en);
	}
	pos = 0;
	for(int i = 1;i <= m2;i++)
	{
		int a,b;
		cin >> a >> b;
		fore[i].sta = a;
		fore[i].en = b;
		tmp[++pos] = a;
		tmp[++pos] = b;
	}
	sort(tmp + 1,tmp + 1 + pos);
	for(int i = 1;i <= m1;i++)
	{
		fore[i].sta = f(1,pos,fore[i].sta);
		fore[i].en = f(1,pos,fore[i].en);
	}
	sort(coun + 1,coun + 1 + m1,cmp);
	sort(fore + 1,fore + 1 + m2,cmp);
	pos = 1;
	int last = 1;
	coun[1].g = 1;
	fore[1].g = 1;
	group[0][1] = 1;
	for(int i = 2;i <= m1;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(coun[i].sta < coun[j].en)
			{
				check[coun[j].g] = 1;
			}
		}
		for(int k = 1;k <= m1;k++)
		{
			if(check[k] == 0)
			{
				coun[i].g = k;
				group[0][k]++;
				w = max(w,k);
				break;
				
			}
		}
		memset(check,0,sizeof(check));
	}
	group[1][1] = 1;
	for(int i = 2;i <= m2;i++)
	{
		for(int j = 1;j < i;j++)
		{
			if(fore[i].sta < fore[j].en)
			{
				check[fore[j].g] = 1;
			}
		}
		for(int k = 1;k <= m2;k++)
		{
			if(check[k] == 0)
			{
				fore[i].g = k;
				group[1][k]++;
				e = max(e,k);
				break;
				
			}
		}
		memset(check,0,sizeof(check));
	}
	long long tot = 0;
	f1[1] = group[0][1];
	f2[1] = group[1][1];
	for(int i = 1;i <= n;i++)
	{
		f1[i] = f1[i - 1] + group[0][i];
		f2[i] = f2[i - 1] + group[1][i];
	}
	for(int i = 0;i <= n;i++)
	{
		int k = n - i;
		tot = max(tot,f1[i] + f2[k]);
	}
	cout << tot << endl;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

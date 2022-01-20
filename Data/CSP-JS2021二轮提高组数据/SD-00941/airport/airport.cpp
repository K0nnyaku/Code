#include<bits/stdc++.h>
using namespace std;

int n, m1, m2;
struct air{
	int in, out;
};
bool cmp(air x, air y)
{
	return x.in < y.in;
}
air a[100010], b[100010];
bool visa[100010], visb[100010];
int ansa[100010], ansb[100010];

int cnta = 0, alla = 0;
void worka()
{
	while(alla != m1)
	{
		bool flag = 0;
		int nowout = 0;
		for(int i=1;i<=m1;i++)
		{
			if(visa[i] == 1) continue;
			if(flag==0){
				nowout = a[i].out;
				ansa[++cnta]++;
				visa[i] = 1;
				alla++;
				flag = 1;
				continue;
			}
			if(a[i].in >= nowout){
				nowout = a[i].out;
				ansa[cnta]++;
				alla++; 
				visa[i] = 1;
			}
		}
	}
	return;
}

int cntb = 0, allb = 0;
void workb()
{
	while(allb != m2)
	{
		bool flag = 0;
		int nowout = 0;
		for(int i=1;i<=m2;i++)
		{
			if(visb[i] == 1) continue;
			if(flag==0){
				nowout = b[i].out;
				ansb[++cntb]++;
				visb[i] = 1;
				allb++;
				flag = 1;
				continue;
			}
			if(b[i].in >= nowout){
				nowout = b[i].out;
				ansb[cntb]++;
				allb++; 
				visb[i] = 1;
			}
		}
	}
	return;
}

int answer = -1; 

int main()
{	
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin >> n >> m1 >> m2;
	for(int i=1;i<=m1;i++)
	{
		cin >> a[i].in >> a[i].out;
	}
	for(int i=1;i<=m2;i++)
	{
		cin >> b[i].in >> b[i].out;
	}
	sort(a+1, a+m1+1, cmp);
	sort(b+1, b+m2+1, cmp);
	worka();
	workb();
	for(int i=1;i<=n;i++)
	{
		int ans = 0;
		int t = n-i;
		for(int j=1;j<=i;j++)
		{
			ans += ansa[j];
		}
		for(int j=1;j<=t;j++)
		{
			ans += ansb[j];
		}
		answer = max(answer, ans);
	}
	cout << answer;
	return 0;
}

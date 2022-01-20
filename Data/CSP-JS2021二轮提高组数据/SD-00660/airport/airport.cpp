#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int n,m1,m2,ans,ed1[N],ed2[N];
struct node {
	int s,e;
}a[2][N];
bool cmp(node a,node b)
{
	return a.s < b.s;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	cin >> n >> m1 >> m2;
	
	for(int i = 1;i <= m1;i ++)
		cin >> a[0][i].s >> a[0][i].e;
	
	for(int i = 1;i <= m2;i ++)
		cin >> a[1][i].s >> a[1][i].e;
		
	sort(a[0] + 1,a[0] + m1 + 1,cmp);
	sort(a[1] + 1,a[1] + m2 + 1,cmp);
	
		
	for(int i = 0;i <= n;i ++)
	{
		int gnp = i,gwp = n - i;
		int ansn = 0,answ = 0;
		memset(ed1,0,sizeof(ed1));
		memset(ed2,0,sizeof(ed2));
		for(int j = 1;j <= m1;j ++)
		{
			for(int k = 1;k <= gnp;k ++)
				if(ed1[k] <= a[0][j].s)
				{
					ed1[k] = a[0][j].e;
					ansn ++;
					break;
				}
		}
		for(int j = 1;j <= m2;j ++)
		{
			for(int k = 1;k <= gwp;k ++)
				if(ed2[k] <= a[1][j].s)
				{
					ed2[k] = a[1][j].e;
					answ ++;
					break;
				}
		}
		ans = max(ans,ansn + answ);
	}
	
	cout << ans << endl;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+50;

int n, m1, m2;
int cnt1, cnt2;
int maxans, ans, ans1, ans2;
pair <int, int> guonei[N];
pair <int, int> guoji[N];
bool vis1[N], vis2[N];

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	scanf("%d %d %d", &n, &m1, &m2);
	
	int max_ = 0;
	
	for(int i = 1; i <= m1; i ++)
	{
		scanf("%d %d", &guonei[i].first, &guonei[i].second);
		max_ = max(max_ , guonei[i].second);
	}
		
		
	for(int i = 1; i <= m2; i ++)
	{
		scanf("%d %d", &guoji[i].first, &guoji[i].second);
		max_ = max(max_ , guoji[i].second);
	}
	
	sort(guonei + 1, guonei + m1 + 1);
	sort(guoji + 1, guoji + m2 + 1);
	
	for(int i = 0; i <= n; i ++)
	{
		int j = n - i;
		cnt1 = 0;
		cnt2 = 0;
		ans1 = 0;
		ans2 = 0;
		//memset(vis1, 0, sizeof vis1);
		//memset(vis2, 0, sizeof vis2);
		for(int t = 1; t <= max_; t ++)
		{
			for(int k = 1; k <= m1; k ++)
			{
				if(guonei[k].first == t )
				{
					if(cnt1 < i)
					{
						vis1[k] = 1;
						ans1 ++;
						cnt1 ++;
						break;
					}
					
					if(cnt1 >= i)
						break;
						
				}
				
				if(guonei[k].second == t && vis1[k])
				{
					vis1[k] = false;
					cnt1 --;
					break;
				}
				
			}
			
			
			for(int k = 1; k <= m1; k ++)
			{
				if(guoji[k].first == t )
				{
					if(cnt2 < j)
					{
						vis2[k] = 1;
						ans2 ++;
						cnt2 ++;
						break;
					}
					
					if(cnt2 >= j)
						break;
						
				}
				
				if(guoji[k].second == t && vis2[k])
				{
					vis2[k] = false;
					cnt2 --;
					break;
				}
				
			}
		}
		
		ans = ans1 + ans2;
		maxans = max(ans, maxans);
	}

	printf("%d\n", maxans);
	
	return 0;
}


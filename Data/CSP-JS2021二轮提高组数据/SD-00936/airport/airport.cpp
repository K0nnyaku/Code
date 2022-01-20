#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;
struct plane
{
	int begin, end;
}p1[100010], p2[100010];

int n, m1, m2, n1, n2, k, maxn;
int ans;
bool judge[100010];
bool cmp(plane a, plane b)
{
	return a.begin < b.begin;
}
int main() 
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);

	scanf("%d", &n);
	scanf("%d", &m1);
	scanf("%d", &m2);	
	
	for(int j = 1; j <= m1; j++)
		scanf("%d %d", &p1[j].begin, &p1[j].end);
	for(int j = 1; j <= m2; j++)
		scanf("%d %d", &p2[j].begin, &p2[j].end);	
	
	sort(p1+1, p1+m1+1, cmp);
	sort(p2+1, p2+m2+1, cmp);	
	
	for(int i = 0; i <= n; i++)
	{				
		n1 = i;
		n2 = n-i;			
		if(n2 > m2) continue;
		if(n1 > m1) break;				
		ans = 0;			
		for(int j = 1; j <= m1; j++) judge[j] = 0;					
		while(n1--)
		{
			k = 0;
			for(int j = 1; j <= m1; j++)
			{
				if((!judge[j]) && (p1[j].begin >= k))
				{
					ans++;
					judge[j] = 1;
					k = p1[j].end;
				}	
			}
		}		
		if(ans+m2 <= maxn) continue;										
		for(int j = 1; j <= m2; j++) judge[j] = 0;					
		while(n2--)
		{
			k = 0;
			for(int j = 1; j <= m2; j++)
			{
				if((!judge[j]) && (p2[j].begin >= k))
				{
					ans++;
					judge[j] = 1;
					k = p2[j].end;
				}
			}
		}			
		if(ans > maxn) maxn = ans;	
	}	
	cout << maxn;	
	return 0;
}


















#include<bits/stdc++.h>
#define ll long long
#define N 100010
using namespace std;
int n , m_1 , m_2;
ll ans , maxx , fil[N];
struct node{
	ll bak , lve;
};
node a[N] , b[N];
bool cmp(node a , node b)
{
	return a.bak < b.bak;
}
int main()
{
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out" , "w" , stdout);
	scanf("%d%d%d" , &n , &m_1 , &m_2);
	for(int i = 1 ; i <= m_1 ; i ++)
	scanf("%lld%lld" , &a[i].bak , &a[i].lve);
	for(int i = 1 ; i <= m_2 ; i ++)
	scanf("%lld%lld" , &b[i].bak , &b[i].lve);
    if(n >= m_1 + m_2)
    {
    	printf("%d" , m_1 + m_2);
    	return 0;
	}
	sort(a + 1 , a + m_1 + 1 , cmp);
	sort(b + 1 , b + m_2 + 1 , cmp);
	ll l = min(n , m_1);
	while(l >= 0)
	{
		memset(fil , 0 , sizeof fil);
		maxx = 0;
		ll r = n - l;
		if(r >= m_2)
		maxx += m_2;
		for(int i = 1 ; i <= l ; i ++)
		{
		fil[i] = a[i].lve;	
		}
		maxx += l;
		for(int i = l + 1 ; i <= m_1 ; i ++)
		{
         for(int j = 1 ; j <= l ; j ++)
         {
         	if(fil[j] <= a[i].bak)
         	{
         		maxx ++;
         		fil[j] = a[i].lve;
         		break;
			 }
		 }
		}
		memset(fil , 0 , sizeof fil);
		if(r < m_2)
		{
		for(int i = 1 ; i <= r ; i ++)
		{
		fil[i] = b[i].lve;	
		}
		maxx += r;
		for(int i = l + 1 ; i <= m_2 ; i ++)
		{
         for(int j = 1 ; j <= r ; j ++)
         {
         	if(fil[j] <= b[i].bak)
         	{
         		maxx ++;
         		fil[j] = b[i].lve;
         		break;
			}
		 }
		}
		}	
		l --;
		ans = max(ans , maxx);
	}
	printf("%lld" , ans);
	return 0;
}

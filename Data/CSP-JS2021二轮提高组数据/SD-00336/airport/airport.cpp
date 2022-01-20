#include <bits/stdc++.h>

#define ll long long
#define reg register
#define gc getchar()

using namespace std;

const int maxm = 100000 + 3;

inline ll read()
{
	ll f = 0, x = 0;
	char ch = gc;
	while (!isdigit(ch))
		f |= (ch == '-'), ch = gc;
	while (isdigit(ch))
		x = (x << 1) + (x << 3) + (ch ^ 48), ch = gc;
	return f ? -x : x;
}

struct node
{
	ll a, b;
}	q1[maxm], q2[maxm];

bool cmp(node a, node b)
{
	return a.a < b.a;
}

ll n, m1, m2, ans, air1[maxm], air2[maxm];

int main(void)
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read();
	m1 = read();
	m2 = read();
	for (reg int i(1); i <= m1; i++)
	{
		q1[i].a = read();
		q1[i].b = read();
	} 
	for (reg int i(1); i <= m2; i++)
	{
		q2[i].a = read();
		q2[i].b = read();
	}
	sort(q1 + 1, q1 + m1 + 1, cmp);
	sort(q2 + 1, q2 + m2 + 1, cmp);
	for (reg ll n1(max(n - m2, (ll) 0)); n1 <= min(m1, n); n1++)
	{
		ll nn1[n1 + 1], nn2[n - n1 + 1];
		ll n2 = n - n1;
		memset(nn1, 0, sizeof(nn1));
		memset(nn2, 0, sizeof(nn2));
		ll now = 1, ans1 = 0, ans2 = 0;
		ll as = 1e8 + 1, as1 = 1e8 + 1;
		if (n1 == 0)
		{
			
		}
		else
			if (n1 == 1)
			{
				as = q1[1].b;
				ans1++;
				for (int i = 2; i <= m1; i++)
					if (as <= q1[i].a) 
					{
						ans1++;
						as = q1[i].b;
					}
			}
			else
			{
				for (int i = 1; i <= m1; i++)
				{
					if(now > m1) 	
							break;
					for (int j = 1; j <= n1; j++)
					{	
						if(nn1[j] == 0)
						{
							ans1++;
							nn1[j] = q1[now].b;
							as = min(as,q1[now].b);
							now++;
							if(now > m1) 	
								break;
						}
					}
						for (int j = 1; j <= n1; j++)
						{	
							if (nn1[j] != as)
								as1 = min(as1, nn1[j]);
							if (nn1[j] == as)
								nn1[j] = 0;
							if (now > m1)
							{
								break;
							}
							for (;q1[now].a < as;)
							{
								now++;
							}
							if (now > m1)
							{
								break;							
							}
						} 
					as = as1;
					as1 = 1e8 + 1;
				}
			}
			
		now = 1;
		as = 1e8 + 1, as1 = 1e8 + 1;
		
		if (n2 == 0)
		{
			
		}
		else
			if (n2 == 1)
			{
				as = q2[1].b;
				ans2++;
				for (int i = 2; i <= m2; i++)
					if (as <= q2[i].a) 
					{
						ans2++;
						as = q2[i].b;
					}
			}
			else
			{
				for (int i = 1; i <= m2; i++)
				{
					if(now > m2) 	
							break;
					for (int j = 1; j <= n2; j++)
					{	
						if(nn2[j] == 0)
						{
							ans2++;
							nn2[j] = q2[now].b;
							as = min(as,q2[now].b);
							now++;
							if(now > m1) 	
								break;
						}
					}
						for (int j = 1; j <= n2; j++)
						{	
							if (nn2[j] != as)
								as1 = min(as1, nn1[j]);
							if (nn2[j] == as)
								nn2[j] = 0;
							if (now > m2)
							{
								break;
							}
							for (;q2[now].a < as;)
							{
								now++;
							}
							if (now > m2)
							{
								break;							
							}
						} 
					as = as1;
					as1 = 1e8 + 1;
				}
			}
		ans = max(ans,ans1+ans2);
		ans1 = 0;
		ans2 = 0;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

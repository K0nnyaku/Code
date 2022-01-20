#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstdio>
#include <queue>
#define ll long long
using namespace std;

struct edge
{
	int in ;
	int out;
};
struct deuse
{
	int in[10001];
	int out[10001];
	int num;
};
struct node 
{
	ll a , b;
	ll id;
};

node rem1[10001]; 
node rem2[10001];
ll n , m1 , m2; 
edge airn[10001];
edge airw[10001];
int flag1 = 1;
int flag2 = 1;

bool cmp(node x , node y)
{
	return x.a < y.a;
}
int main()
{	
	freopen("airport.in" , "r" , stdin);
	freopen("airport.out" , "w" , stdout);
	ll alltime = 0;
	cin >> n >> m1 >> m2 ;
	
	for(ll i = 1 ; i <= m1 ; i++)
	{

		cin >> rem1[i].a ;
		cin >> rem1[i].b ;
		rem1[i].id = i;
		airn[rem1[i].a].in = rem1[i].id;
		airn[rem1[i].b].out = rem1[i].id; 	
		alltime = max(rem1[i].b , alltime);
	}
	for(ll i = 1 ; i <= m2 ; i++)
	{

		cin >> rem2[i].a ;
		cin >> rem2[i].b ;
		rem2[i].id = i;
		airw[rem2[i].a].in = rem2[i].id;
		airw[rem2[i].b].out = rem2[i].id;
		alltime = max(rem2[i].b , alltime);
	}
	ll ans = 0;
	for(ll i = 0 ; i <= n ; i++)
	{
		ll temp = n - i; 
		deuse canusen;
		canusen.num = i; 
		deuse canusew ;
		canusew.num  = temp;  
		ll time = 0;
		ll tot = 0;
		while(time <= alltime)
		{
			time++;
			if(airn[time].in != 0 &&  canusen.num > 0)
			{
				canusen.num -- ;
				canusen.in[flag1] = airn[time].in ;
				flag1++;
				tot ++ ;
			}
			else if(airn[time].out != 0 )
			{
				for(int j = 1 ; j <= flag1 ; j++)
				{
					if(airn[time].out == canusen.in[j])
					{
						canusen.num ++;
						canusen.in[j] = -1;
						flag1++;
						break;
					}
				}
			}
			if(airw[time].in != 0 &&  canusew.num > 0)
			{
				canusew.num -- ;
				canusew.in[flag2] = airw[time].in ;
				flag2++;
				tot ++ ;
			}
			else if(airw[time].out != 0)
			{
				for(ll j = 1 ; j <= flag2 ; j++)
				{
					if(airw[time].out == canusew.in[j])
					{
						canusew.num ++;
						canusew.in[j] = -1;
						flag2++;
						break;
					}
				}
			}	
		}
		if(tot > ans)
		{
			ans = tot;
		}	
	}
	cout << ans;
	return 0;
}

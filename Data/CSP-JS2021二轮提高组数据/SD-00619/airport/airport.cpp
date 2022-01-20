#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long ll;
using namespace std;
struct plane_h
{
	ll arrive_h = 0;
	ll leave_h = 0;
};
ll min1,min2;
ll home[100000];//国内廊桥 
ll board[100000];//国外廊桥 
ll temp1[100000],temp2[100000],temp3[100000],temp4[100000];
plane_h a[200000];
plane_h temp_h;
ll ans=0,ans1=0,ans2=0,cnt=0;
struct plane_b
{
	ll arrive_b = 0;
	ll leave_b = 0;
};
plane_b b[200000];
plane_b temp_b;
int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	ll n,m1,m2;
	cin >> n >> m1 >> m2;
	for(ll i = 0;i < m1;i++)
	{
		cin >> a[i].arrive_h >> a[i].leave_h; 
		temp1[i] = a[i].arrive_h;
		temp3[i] = a[i].leave_h;
	}
	sort(temp1,temp1 + m1);
	for(ll i = 0;i < m1;i++)
	{
		for(ll j = 0;j < m1;j++)
			{
				if(temp1[i] == a[j].arrive_h)
				{
					temp_h.arrive_h = a[i].arrive_h;
					temp_h.leave_h = a[i].leave_h;
					a[i].arrive_h = a[j].arrive_h;
					a[i].leave_h = a[j].leave_h;
					a[j].arrive_h = temp_h.arrive_h;
					a[j].leave_h = temp_h.leave_h;
				}
			}
	}
	for(ll i = 0;i < m2;i++)
	{
		cin >> b[i].arrive_b >> b[i].leave_b; 
		temp2[i] = b[i].arrive_b;
		temp4[i] = b[i].leave_b;
	}
	sort(temp2,temp2 + m2);
	for(ll i = 0;i < m2;i++)
	{
		for(ll j = 0;j < m2;j++)
			{
				if(temp2[i] == b[j].arrive_b)
				{
					temp_b.arrive_b = b[i].arrive_b;
					temp_b.leave_b = b[i].leave_b;
					b[i].arrive_b = b[j].arrive_b;
					b[i].leave_b = b[j].leave_b;
					b[j].arrive_b = temp_b.arrive_b;
					b[j].leave_b = temp_b.leave_b;
				}
			}
	}
	ll x = n - 1;
	ll y = 0;
	while(x >= 0)
	{
			y = n - x;
			ans1 = x;
			for(ll i = x + 1;i < m1;i++)
			{
				if(x == 0)
				break;
				else
				{
				sort(temp3,temp3 + x);
				min1 = temp3[0];
				if(a[i].arrive_h >= min1)
				{
					ans1++;
					temp3[0] = a[i].leave_h;
				}
				}
				
			}	
				
			ans2 = y + 1;
			for(ll i = y + 1;i < m2;i++)
			{
				if(y == 0)
				break;
				else
				{
				sort(temp4,temp4 + y);
				min2 = temp4[0];
				if(b[i].arrive_b >= min2)
				{
					ans2++;
					temp4[0] = b[i].leave_b;
				}
				}
				
			}
			cnt = ans1 + ans2;
			ans = max(cnt,ans);	
			x--;
}
cout << ans;
return 0;
}
	
	
	
